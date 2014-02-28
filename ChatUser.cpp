#include "ChatUser.hpp"
#include "Packet.hpp"
#include "Client.hpp"
#include "ClientManager.hpp"
#include "Server.hpp"
#include "Chunk.hpp"
#include "Chat.hpp"
#include "ChatMessage.hpp"

Tortuga::ChatUser::ChatUser ( Tortuga::Client & client , const ARC::String & name ) :
	client ( client ) ,
	name ( name ) ,
	chat ( nullptr )
{
}
Tortuga::ChatUser::ChatUser ( Tortuga::Client & client , Tortuga::Chat * chat , const ARC::String & name ) :
	client ( client ) ,
	name ( name ) ,
	chat ( nullptr )
{
	this->setChat ( chat ) ;
}
Tortuga::ChatUser::~ChatUser ( )
{
	this->setChat ( nullptr ) ;
}

ARC::Void Tortuga::ChatUser::setChat ( Tortuga::Chat * chat )
{
	if ( this->chat )
		this->chat->getChatUsers ( ).remove ( this ) ;
	
	this->chat = chat ;
	
	if ( this->chat )
		this->chat->getChatUsers ( ).push_back ( this ) ;
}
Tortuga::Chat * Tortuga::ChatUser::getChat ( )
{
	return this->chat ;
}
const Tortuga::Chat * Tortuga::ChatUser::getChat ( ) const
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
	if ( this->chat )
		this->chat->send ( Tortuga::ChatMessage ( Tortuga::Packet::readChatMessagePacket ( packet ).message ) ) ;
}
