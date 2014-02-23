#include "ChatUser.hpp"
#include "Packet.hpp"
#include "Client.hpp"
#include "Server.hpp"
#include "Chunk.hpp"

Tortuga::ChatUser::ChatUser ( Tortuga::Client & client , const ARC::String & name ) :
	name ( name ) ,
	client ( client )
{
}
		
Tortuga::Client & Tortuga::ChatUser::getClient ( )
{
	return this->client ;
}
const Tortuga::Client & Tortuga::ChatUser::getClient ( ) const
{
	return this->client ;
}
			
ARC::Void Tortuga::ChatUser::setName ( const ARC::String & name )
{
	this->name = name ;
}
const ARC::String & Tortuga::ChatUser::getName ( ) const
{
	return this->name ;
}

ARC::Void Tortuga::ChatUser::send ( const ARC::String & message )
{
	this->client.send ( Tortuga::Packet::writeChatMessagePacket ( { "{\"text\": \"" + message + "\"}" } ) ) ;
}
ARC::Void Tortuga::ChatUser::broadcast ( const ARC::String & message )
{
	for ( auto client : this->client.getServer ( ).getClients ( ) )
	{
		client->getChatUser ( )->send ( message ) ;
	}
}

ARC::Void Tortuga::ChatUser::handleChatMessage ( Tortuga::Packet & packet )
{
	Tortuga::Packet::ChatMessageData chatMessageData = Tortuga::Packet::readChatMessagePacket ( packet ) ;
		
	this->broadcast ( chatMessageData.message ) ;	
}
