#include <Tortuga/Client/Client.hpp>
#include <Tortuga/Client/ClientManager.hpp>
#include <Tortuga/World/WorldManager.hpp>
#include <Tortuga/Server/Server.hpp>
#include <Tortuga/Chat/ChatMessage.hpp>
#include <Tortuga/Chat/ChatUser.hpp>
#include <Tortuga/Status/Status.hpp>
#include <Tortuga/Entity/PlayerEntity.hpp>
#include <Tortuga/Entity/PlayerEntity.hpp>
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
#include <Tortuga/Protocol/SpawnPlayerPacket.hpp>
#include <Tortuga/Protocol/SpawnMobPacket.hpp>
#include <Tortuga/Protocol/JoinGamePacket.hpp>
#include <Tortuga/Protocol/SpawnPositionPacket.hpp>
#include <Tortuga/Protocol/PlayerPositionAndLookFromServerPacket.hpp>
#include <Tortuga/Protocol/TimeUpdatePacket.hpp>
#include <iostream>

Tortuga::Client::Client ( Tortuga::ClientManager & clientManager ) :
	clientManager ( clientManager ) ,
	chatUser ( nullptr ) ,
	playerEntity ( nullptr ) ,
	type ( Tortuga::Client::None )
{
}
Tortuga::Client::~Client ( )
{
    if ( this->chatUser )
    {
        for ( auto chatUser = this->chatUser->getChat ( ).getChatUsers ( ).begin ( ) ; chatUser != this->chatUser->getChat ( ).getChatUsers ( ).end ( ) ; ++chatUser )
        {
            if ( & * chatUser == this->chatUser )
            {
                this->chatUser->getChat ( ).getChatUsers ( ).erase ( chatUser ) ;
                break ;
            }
        }
    }

    if ( this->playerEntity )
    {
        for ( auto playerEntity = this->playerEntity->getEntityManager ( ).getEntities ( ).begin ( ) ; playerEntity != this->playerEntity->getEntityManager ( ).getEntities ( ).end ( ) ; ++playerEntity )
        {
            if ( & * playerEntity == this->playerEntity )
            {
                this->playerEntity->getEntityManager ( ).getEntities ( ).erase ( playerEntity ) ;
                break ;
            }
        }
    }
}

Tortuga::ClientManager & Tortuga::Client::getClientManager ( )
{
	return this->clientManager ;
}
const Tortuga::ClientManager & Tortuga::Client::getClientManager ( ) const
{
	return this->clientManager ;
}

Tortuga::ChatUser * Tortuga::Client::getChatUser ( )
{
	return this->chatUser ;
}
const Tortuga::ChatUser * Tortuga::Client::getChatUser ( ) const
{
	return this->chatUser ;
}

Tortuga::PlayerEntity * Tortuga::Client::getPlayerEntity ( )
{
	return this->playerEntity ;
}
const Tortuga::PlayerEntity * Tortuga::Client::getPlayerEntity ( ) const
{
	return this->playerEntity ;
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

ARC::Void Tortuga::Client::joinWorld ( Tortuga::World & world )
{
    if ( this->playerEntity )
    {
        for ( auto playerEntity = this->playerEntity->getEntityManager ( ).getEntities ( ).begin ( ) ; playerEntity != this->playerEntity->getEntityManager ( ).getEntities ( ).end ( ) ; ++playerEntity )
        {
            if ( & * playerEntity == this->playerEntity )
            {
                this->playerEntity->getEntityManager ( ).getEntities ( ).erase ( playerEntity ) ;
                break ;
            }
        }
    }

    world.getEntityManager ( ).getEntities ( ).push_back ( Tortuga::PlayerEntity ( * this , world.getEntityManager ( ) , Tortuga::Location ( Tortuga::Position ( static_cast <ARC::Double> ( world.getSpawnPosition ( ).getX ( ) ) , static_cast <ARC::Double> ( world.getSpawnPosition ( ).getY ( ) ) , static_cast <ARC::Double> ( world.getSpawnPosition ( ).getZ ( ) ) ) ) , "" ) ) ;
    this->playerEntity = reinterpret_cast <Tortuga::PlayerEntity *> ( & world.getEntityManager ( ).getEntities ( ).back ( ) ) ;

    this->send ( Tortuga::JoinGamePacket ( this->playerEntity->getIdentification ( ) , world.getGamemode ( ) , world.getDimension ( ) , world.getDifficulty ( ) , "default" ) ) ;
	this->send ( Tortuga::SpawnPositionPacket ( world.getSpawnPosition ( ) ) ) ;
	this->send ( Tortuga::PlayerPositionAndLookFromServerPacket ( this->playerEntity->getLocation ( ) , true ) ) ;
	this->send ( Tortuga::TimeUpdatePacket ( world.getAge ( ) , world.getTime ( ) ) ) ;

	for ( auto chunk : world.getChunks ( ) )
		this->send ( chunk ) ;
}

ARC::Bool Tortuga::Client::update ( )
{
	if ( this->type == Tortuga::Client::Player && this->keepAliveTimer.getElapsedTime ( ) >= ARC::seconds ( 5.0f ) )
	{
		this->send ( Tortuga::KeepAlivePacket ( static_cast <ARC::UnsignedInt> ( ARC::Randomizer::getNumber ( 0 , 100 ) ) ) ) ;

		this->keepAliveTimer.restart ( ) ;
	}

    if ( this->playerEntity )
    {
        for ( auto entity = this->playerEntity->getEntityManager ( ).getEntities ( ).begin ( ) ; entity != this->playerEntity->getEntityManager ( ).getEntities ( ).end ( ) ; ++entity )
        {
            if ( & * entity == this->playerEntity )
                break ;

                Tortuga::EntityMetadata entityMetadata ;

                entityMetadata.getRecords ( ) [ Tortuga::EntityMetadata::Health ] = 55.0f ;
                this->send ( Tortuga::SpawnPlayerPacket ( entity->getIdentification ( ) , "" , "Player" , entity->getLocation ( ) , 0 , entityMetadata ) ) ;
        }
    }

	if ( this->receive ( ) == ARC::Socket::Done )
	{
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

                        this->getClientManager ( ).getServer ( ).getChat ( ).getChatUsers ( ).push_back ( Tortuga::ChatUser ( * this , this->getClientManager ( ).getServer ( ).getChat ( ) , loginStartPacket.getName ( ) ) ) ;
                        this->chatUser = & this->getClientManager ( ).getServer ( ).getChat ( ).getChatUsers ( ).back ( ) ;

                        this->joinWorld ( this->clientManager.getServer ( ).getWorldManager ( ).getDefaultWorld ( ) ) ;

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
						Tortuga::ChatMessageToServerPacket chatMessageToServerPacket ( packetReader ) ;

						if ( this->chatUser )
							this->chatUser->getChat ( ).send ( Tortuga::ChatMessage ( chatMessageToServerPacket.getMessage ( ) ) ) ;

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
