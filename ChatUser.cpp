#include "ChatUser.hpp"
#include "Packet.hpp"
#include "Client.hpp"
#include "ClientManager.hpp"
#include "Server.hpp"
#include "Chunk.hpp"
#include "Chat.hpp"
#include "ChatMessage.hpp"

Tortuga::ChatUser::ChatUser ( Tortuga::Chat & chat , Tortuga::Client & client , const ARC::String & name ) :
	chat ( chat ) ,
	client ( client ) ,
	name ( name )
{
	this->chat.getChatUsers ( ).push_back ( ARC::SharedPointer <Tortuga::ChatUser> ( this ) ) ;
}
		
Tortuga::Chat & Tortuga::ChatUser::getChat ( )
{
	return this->chat ;
}
const Tortuga::Chat & Tortuga::ChatUser::getChat ( ) const
{
	return this->chat ;
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

ARC::Void Tortuga::ChatUser::send ( const Tortuga::ChatMessage & message )
{
	this->client.send ( message ) ;
}

ARC::Void Tortuga::ChatUser::handleChatMessage ( Tortuga::Packet & packet )
{
	Tortuga::Packet::ChatMessageData chatMessageData = Tortuga::Packet::readChatMessagePacket ( packet ) ;
	
	this->chat.send ( Tortuga::ChatMessage ( chatMessageData.message ) ) ;
}
