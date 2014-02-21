#include "Client.hpp"
#include "Server.hpp"
#include "Packet.hpp"
#include "ChatUser.hpp"
#include "Chat.hpp"
#include "World.hpp"
#include <iostream>

ARC::Void Tortuga::Client::onReceive ( )
{
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
					std::cout << "<Error> unknown operationcode, packetOpcode: " << packetOpcode << "\n" ;
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
					std::cout << "<Error> unknown operationcode, packetOpcode: " << packetOpcode << "\n" ;
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
					Tortuga:Packet packet = Tortuga::Packet::writeClientLoginSuccessPacket ( { "" , Tortuga::Packet::readClientLoginStartPacket ( receivedPacket ).username } ) ;
					
					this->send ( packet ) ;
					
					packet = Tortuga::Packet::writeClientJoinGamePacket ( { 0 , 1 , -1 , 0 , 0 , "default" } ) ;
					
					this->send ( packet ) ;
					
					packet = Tortuga::Packet::writeWorldSpawnPositionPacket ( { 0 , 0 , 0 } ) ;
					
					this->send ( packet ) ;			
					
					packet = Tortuga::Packet::writePlayerPositionAndLookPacket ( { 0 , 0 , 0 , 0 , 0 , true } ) ;
					
					this->send ( packet ) ;
										
					this->type = Tortuga::Client::Player ;
					
					break ;
				}
				default :
				{
					std::cout << "<Error> unknown operationcode, packetOpcode: " << packetOpcode << "\n" ;
					break ;
				}
			}
		}
		else if ( this->type == Tortuga::Client::Player )
		{
			switch ( packetOpcode )
			{
				/*case Tortuga::Packet::ClientSettings :
				{
					Tortuga::ClientSettings::readClientSettingsPacket ( * this , receivedPacket ) ;
				
					break ;
				}*/
				/*case Tortuga::Packet::ChatMessageClient :
				{
					Tortuga::ChatManager::readChatMessagePacket ( * this , receivedPacket ) ;
					
					break ;
				}
				/*case Tortuga::Packet::PlayerOnGround :
				{
					Tortuga::Player::readPlayerOnGroundPacket ( * this , receivedPacket ) ;
				
					break ;
				}
				case Tortuga::Packet::PlayerPosition :
				{	
					Tortuga::Player::readPlayerPositionPacket ( * this , receivedPacket ) ;
					
					break ;
				}
				case Tortuga::Packet::PlayerLook :
				{
					Tortuga::Player::readPlayerLookPacket ( * this , receivedPacket ) ;
					
					break ;
				}*/
				case Tortuga::Packet::PlayerPositionAndLookToServer :
				{
					Tortuga::Packet::readPlayerPositionAndLookPacket ( receivedPacket ) ;
				
					break ;
				}
				default :
				{
					std::cout << "<Error> unknown operationcode, packetOpcode: " << packetOpcode << "\n" ;
					break ;
				}
			}
		}
	} while ( this->getBuffer ( ).size ( ) > 0 ) ;
	
}

ARC::Void Tortuga::Client::handleClientHandshake ( Tortuga::Packet & packet )
{
	this->type = static_cast <Tortuga::Client::Type> ( Tortuga::Packet::readClientHandshakePacket ( packet ).state ) ;					
}

ARC::Void Tortuga::Client::handleStatusKeepAlive ( Tortuga::Packet & packet )
{	
	this->send ( Tortuga::Packet::writeStatusKeepAlivePacket ( { Tortuga::Packet::readStatusKeepAlivePacket ( packet ).time } ) ) ;	
}
ARC::Void Tortuga::Client::handleStatusRequest ( Tortuga::Packet & packet )
{
	// nothing to read here
	Tortuga::Packet::readStatusRequestPacket ( packet ) ;
				
	this->send ( Tortuga::Packet::writeStatusResponsePacket ( { "{\"version\": {\"name\": \"1.7.4\",\"protocol\": 4},\"players\": {\"max\": 100,\"online\": 5,\"sample\":[{\"name\":\"Thinkofdeath\", \"id\":\"\"}]},\"description\": {\"text\":\"Hello world\"}}" } ) ) ;
}

Tortuga::Client::Client ( ) :
	type ( Tortuga::Client::None )
{
}

Tortuga::Server & Tortuga::Client::getServer ( )
{
	return Tortuga::Server::getInstance ( ) ;
}
const Tortuga::Server & Tortuga::Client::getServer ( ) const
{
	return Tortuga::Server::getInstance ( ) ;
}

ARC::Void Tortuga::Client::setClientSettings ( const Tortuga::ClientSettings & clientSettings )
{
	this->clientSettings = clientSettings ;
}
Tortuga::ClientSettings & Tortuga::Client::getClientSettings ( )
{
	return this->clientSettings ;
}
const Tortuga::ClientSettings & Tortuga::Client::getClientSettings ( ) const
{
	return this->clientSettings ;
}

ARC::SharedPointer <Tortuga::ChatUser> & Tortuga::Client::getChatUser ( )
{
	return this->chatUser ;
}
const ARC::SharedPointer <Tortuga::ChatUser> & Tortuga::Client::getChatUser ( ) const
{
	return this->chatUser ;
}

Tortuga::Player & Tortuga::Client::getPlayer ( )
{
	return this->player ;
}
const Tortuga::Player & Tortuga::Client::getPlayer ( ) const
{
	return this->player ;
}
