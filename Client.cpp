#include "Client.hpp"
#include "Server.hpp"
#include "Packet.hpp"
#include "ChatUser.hpp"
#include "World.hpp"
#include "Player.hpp"
#include "Difficulty.hpp"
#include "ClientManager.hpp"
#include <iostream>

Tortuga::Client::Client ( Tortuga::ClientManager & clientManager ) :
	clientManager ( clientManager ) ,
	type ( Tortuga::Client::None )
{
}

Tortuga::ClientManager & Tortuga::Client::getClientManager ( )
{
	return this->clientManager ;
}
const Tortuga::ClientManager & Tortuga::Client::getClientManager ( ) const
{
	return this->clientManager ;
}

ARC::Void Tortuga::Client::setBuffer ( const ARC::Buffer & buffer )
{
	this->buffer = buffer ;
}
ARC::Buffer & Tortuga::Client::getBuffer ( )
{
	return this->buffer ;
}
const ARC::Buffer & Tortuga::Client::getBuffer ( ) const
{
	return this->buffer ;
}

Tortuga::ChatUser & Tortuga::Client::getChatUser ( )
{
	return * this->chatUser ;
}
const Tortuga::ChatUser & Tortuga::Client::getChatUser ( ) const
{
	return * this->chatUser ;
}

Tortuga::Player & Tortuga::Client::getPlayer ( )
{
	return * this->player ;
}
const Tortuga::Player & Tortuga::Client::getPlayer ( ) const
{
	return * this->player ;
}

const ARC::String & Tortuga::Client::getLocale ( ) const
{
	return this->locale ;
}
ARC::UnsignedChar Tortuga::Client::getViewDistance ( ) const
{
	return this->viewDistance ;
}
ARC::UnsignedChar Tortuga::Client::getChatFlags ( ) const
{
	return this->chatFlags ;
}
ARC::Bool Tortuga::Client::getChatColors ( ) const
{
	return this->chatColors ;
}
Tortuga::Difficulty::Type Tortuga::Client::getDifficulty ( ) const
{
	return this->difficulty ;
}
ARC::Bool Tortuga::Client::getShowCape ( ) const
{
	return this->showCape ;
}

ARC::Bool Tortuga::Client::update ( )
{
	const ARC::UnsignedLong maximalSize = 1024 ;

	ARC::UnsignedChar * receivedData = new ARC::UnsignedChar [ maximalSize ] ;
	ARC::UnsignedLong receivedSize = 0 ;
		
	ARC::Socket::Status status = sf::TcpSocket::receive ( receivedData , maximalSize , receivedSize ) ;
	
	ARC::Buffer newBuffer ;
	
	for ( ARC::UnsignedLong element = 0 ; element < receivedSize ; ++element )
	{
		newBuffer.push_back ( receivedData [ element ] ) ;
	}
	
	delete receivedData ;
	
	if ( status == ARC::Socket::Done )
	{
		this->buffer.insert ( this->buffer.end ( ) , newBuffer.begin ( ) , newBuffer.end ( ) ) ;
			
		do
		{
			Tortuga::Packet receivedPacket = Tortuga::Packet::read ( this->getBuffer ( ) ) ;
		
			if ( this->getBuffer ( ).size ( ) == 0 || receivedPacket.getBuffer ( ).size ( ) == 0 || this->getBuffer ( ).size ( ) < receivedPacket.getBuffer ( ).size ( ) )
				break ;
			
			this->getBuffer ( ).erase ( this->getBuffer ( ).begin ( ) , this->getBuffer ( ).begin ( ) + receivedPacket.getBuffer ( ).size ( ) ) ;
		
			ARC::UnsignedInt packetOpcode = receivedPacket.readVariableInt ( ) ;
		
			if ( this->type == Tortuga::Client::None )
			{
				switch ( packetOpcode )
				{
					case Tortuga::Packet::ClientHandshake :
					{
						this->handleClientHandshake ( receivedPacket ) ;
						break ;
					}
					default :
					{
						std::cout << "<Error> unknown operationcode, packetOpcode: 0x" << std::hex << packetOpcode << "\n" ;
						break ;
					}
				}
			}
			else if ( this->type == Tortuga::Client::Status )
			{
				switch ( packetOpcode )
				{
					case Tortuga::Packet::StatusKeepAlive :
					{
						this->handleStatusKeepAlive ( receivedPacket ) ;					
						break ;
					}
					case Tortuga::Packet::StatusRequest :
					{
						this->handleStatusRequest ( receivedPacket ) ;
			
						break ;
					}
					default :
					{
						std::cout << "<Error> unknown operationcode, packetOpcode: 0x" << std::hex << packetOpcode << "\n" ;
						break ;
					}
				}
			}
			else if ( this->type == Tortuga::Client::Login )
			{
				switch ( packetOpcode )
				{
					case Tortuga::Packet::ClientLoginStart :
					{				
						this->handleClientLoginStart ( receivedPacket ) ;
						break ;
					}
					default :
					{
						std::cout << "<Error> unknown operationcode, packetOpcode: 0x" << std::hex << packetOpcode << "\n" ;
						break ;
					}
				}
			}
			else if ( this->type == Tortuga::Client::Player )
			{
				switch ( packetOpcode )
				{
					case Tortuga::Packet::ClientKeepAlive :
					{
						this->handleClientKeepAlive ( receivedPacket ) ;				
						break ;
					}
					case Tortuga::Packet::ClientSettings :
					{
						this->handleClientSettings ( receivedPacket ) ;
						break ;
					}
					case Tortuga::Packet::PlayerOnGround :
					{
						this->player->handlePlayerOnGround ( receivedPacket ) ;
						break ;
					}
					case Tortuga::Packet::PlayerPosition :
					{	
						this->player->handlePlayerPosition ( receivedPacket ) ;					
						break ;
					}
					case Tortuga::Packet::PlayerLook :
					{
						this->player->handlePlayerLook ( receivedPacket ) ;
						break ;
					}
					case Tortuga::Packet::PlayerPositionAndLookToServer :
					{
						this->player->handlePlayerPositionAndLook ( receivedPacket ) ;				
						break ;
					}
					case Tortuga::Packet::ChatMessageToServer :
					{
						this->chatUser->handleChatMessage ( receivedPacket ) ;
						break ;
					}
					default :
					{
						std::cout << "<Error> unknown operationcode, packetOpcode: 0x" << std::hex << packetOpcode << "\n" ;
						break ;
					}
				}
			}
		} while ( this->getBuffer ( ).size ( ) > 0 ) ;
	}
	else
		return false ;
		
	return true ;
}

#include "Status.hpp"

ARC::Void Tortuga::Client::handleStatusKeepAlive ( Tortuga::Packet & packet )
{	
	this->send ( Tortuga::Packet::writeStatusKeepAlivePacket ( { Tortuga::Packet::readStatusKeepAlivePacket ( packet ).time } ) ) ;	
}
ARC::Void Tortuga::Client::handleStatusRequest ( Tortuga::Packet & packet )
{
	Tortuga::Packet::readStatusRequestPacket ( packet ) ;				
	this->send ( Tortuga::Status ( ) ) ;
}

ARC::Void Tortuga::Client::handleClientHandshake ( Tortuga::Packet & packet )
{
	this->type = static_cast <Tortuga::Client::Type> ( Tortuga::Packet::readClientHandshakePacket ( packet ).state ) ;					
}
ARC::Void Tortuga::Client::handleClientKeepAlive ( Tortuga::Packet & packet )
{
}

ARC::Void Tortuga::Client::handleClientLoginStart ( Tortuga::Packet & packet )
{		
	this->send ( Tortuga::Packet::writeClientLoginSuccessPacket ( { "" , Tortuga::Packet::readClientLoginStartPacket ( packet ).username } ) ) ;
	this->send ( Tortuga::Packet::writeClientJoinGamePacket ( { 0 , 1 , 0 , 0 , 0 , "default" } ) ) ;				
	this->send ( Tortuga::Packet::writeWorldSpawnPositionPacket ( { 0 , 0 , 0 } ) ) ;	
	this->send ( Tortuga::Packet::writePlayerPositionAndLookPacket ( { 0 , 0 , 0 , 0 , 0 , true } ) ) ;
	
	this->send ( Tortuga::Packet::writeWorldTimeUpdatePacket ( { 0 , 300 } ) ) ;
	
	this->chatUser = ARC::SharedPointer <Tortuga::ChatUser> ( new Tortuga::ChatUser ( * this , this->getClientManager ( ).getServer ( ).getChat ( ) ) ) ;
	this->player = ARC::SharedPointer <Tortuga::Player> ( new Tortuga::Player ( * this ) ) ;
	this->type = Tortuga::Client::Player ;
}		
ARC::Void Tortuga::Client::handleClientSettings ( Tortuga::Packet & packet )
{
	Tortuga::Packet::ClientSettingsData clientSettingsData = Tortuga::Packet::readClientSettingsPacket ( packet ) ;

	this->locale = clientSettingsData.locale ;
	this->viewDistance = clientSettingsData.viewDistance ;
	this->chatFlags = clientSettingsData.chatFlags ;
	this->chatColors = clientSettingsData.chatColors ;
	this->difficulty = static_cast <Tortuga::Difficulty::Type> ( clientSettingsData.difficulty ) ;
	this->showCape = clientSettingsData.showCape ;
}
