#include <Tortuga/Client/Client.hpp>
#include <Tortuga/Client/ClientManager.hpp>
#include <Tortuga/World/WorldManager.hpp>
#include <Tortuga/Server/Server.hpp>
#include <Tortuga/Chat/ChatMessage.hpp>
#include <Tortuga/Status/Status.hpp>
#include <Tortuga/Player.hpp>
#include <Tortuga/Protocol/Packet.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>
#include <Tortuga/Protocol/HandshakePacket.hpp>
#include <Tortuga/Protocol/LoginStartPacket.hpp>
#include <Tortuga/Protocol/LoginSuccessPacket.hpp>
#include <Tortuga/Protocol/StatusRequestPacket.hpp>
#include <Tortuga/Protocol/StatusResponsePacket.hpp>
#include <Tortuga/Protocol/StatusKeepAlivePacket.hpp>
#include <Tortuga/Protocol/ChatMessageToServerPacket.hpp>
#include <Tortuga/Protocol/ChatMessageFromServerPacket.hpp>
#include <Tortuga/Protocol/KeepAlivePacket.hpp>
#include <iostream>

Tortuga::Client::Client ( Tortuga::ClientManager & clientManager ) :
	clientManager ( clientManager ) ,
	chatUser ( * this ) ,
	player ( * this ) ,
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
	return this->chatUser ;
}
const Tortuga::ChatUser & Tortuga::Client::getChatUser ( ) const
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
	if ( this->type == Tortuga::Client::Player && this->keepAliveTimer.getElapsedTime ( ) >= ARC::seconds ( 5.0f ) )
	{
		this->send ( Tortuga::KeepAlivePacket ( static_cast <ARC::UnsignedInt> ( ARC::Randomizer::getNumber ( 0 , 100 ) ) ) ) ;
			
		this->keepAliveTimer.restart ( ) ;
	}

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
						Tortuga::LoginStartPacket loginStartPacket ( packetReader ) ;
					
						this->send ( Tortuga::LoginSuccessPacket ( "" , loginStartPacket.getName ( ) ) ) ;
						
						this->chatUser.setChat ( & this->clientManager.getServer ( ).getChat ( ) ) ;
						this->chatUser.setName ( loginStartPacket.getName ( ) ) ;
						
						this->player.setWorld ( & this->clientManager.getServer ( ).getWorldManager ( ).getDefaultWorld ( ) ) ;
						
						this->type = Tortuga::Client::Player ;
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
					case Tortuga::Packet::KeepAlive :
					{			
						break ;
					}
					case Tortuga::Packet::ClientSettings :
					{
						break ;
					}
					case Tortuga::Packet::PlayerOnGround :
					{
						break ;
					}
					case Tortuga::Packet::PlayerPosition :
					{					
						break ;
					}
					case Tortuga::Packet::PlayerLook :
					{
						break ;
					}
					case Tortuga::Packet::PlayerPositionAndLookToServer :
					{			
						break ;
					}
					case Tortuga::Packet::ChatMessageToServer :
					{
						if ( this->chatUser.getChat ( ) )
							this->chatUser.getChat ( )->send ( Tortuga::ChatMessage ( Tortuga::ChatMessageToServerPacket ( packetReader ).getMessage ( ) ) ) ;
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
