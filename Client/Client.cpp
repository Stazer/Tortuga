#include <Tortuga/Client/Client.hpp>
#include <Tortuga/Client/ClientManager.hpp>
#include <Tortuga/Status/Status.hpp>
#include <Tortuga/Protocol/Packet.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>
#include <Tortuga/Protocol/HandshakePacket.hpp>
#include <Tortuga/Protocol/LoginStartPacket.hpp>
#include <Tortuga/Protocol/LoginSuccessPacket.hpp>
#include <Tortuga/Protocol/StatusRequestPacket.hpp>
#include <Tortuga/Protocol/StatusResponsePacket.hpp>
#include <Tortuga/Protocol/StatusKeepAlivePacket.hpp>
#include <Tortuga/Protocol/JoinGamePacket.hpp>
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
/*
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
*/
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
/*Tortuga::Difficulty::Type Tortuga::Client::getDifficulty ( ) const
{
	return this->difficulty ;
}*/
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
			Tortuga::PacketReader packetReader ;
			
			packetReader.read ( this->getBuffer ( ) ) ;
			
			if ( this->getBuffer ( ).size ( ) == 0 || packetReader.getBuffer ( ).size ( ) == 0 || this->getBuffer ( ).size ( ) < packetReader.getBuffer ( ).size ( ) )
				break ;
			
			this->getBuffer ( ).erase ( this->getBuffer ( ).begin ( ) , this->getBuffer ( ).begin ( ) + packetReader.getBuffer ( ).size ( ) ) ;

			const ARC::UnsignedInt packetOpcode = packetReader.readVariableInt ( ) ;
			
			if ( this->type == Tortuga::Client::None )
			{
				switch ( packetOpcode )
				{
					case Tortuga::Packet::Handshake :
					{
						this->type = static_cast <Tortuga::Client::Type> ( Tortuga::HandshakePacket ( packetReader ).getState ( ) ) ;
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
						this->send ( Tortuga::StatusKeepAlivePacket ( packetReader ) ) ;
						break ;
					}
					case Tortuga::Packet::StatusRequest :
					{
						this->send ( Tortuga::Status ( ) ) ;
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
					case Tortuga::Packet::LoginStart :
					{
						this->send ( Tortuga::LoginSuccessPacket ( "" , Tortuga::LoginStartPacket ( packetReader ).getName ( ) ) ) ;
						this->send ( Tortuga::JoinGamePacket ( 0 , 1 , 0 , 0 , "default" ) ) ;
						break ;
					}
					default :
					{
						std::cout << "<Error> unknown operationcode, packetOpcode: 0x" << std::hex << packetOpcode << "\n" ;
						break ;
					}
				}
			}
			/*else if ( this->type == Tortuga::Client::Player )
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
			}*/
		} while ( this->getBuffer ( ).size ( ) > 0 ) ;
	}
	else
		return false ;
		
	return true ;
}
