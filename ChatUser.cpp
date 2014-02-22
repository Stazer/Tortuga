#include "ChatUser.hpp"
#include "Packet.hpp"

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

ARC::Void Tortuga::ChatUser::handleChatMessage ( Tortuga::Packet & packet )
{
	//Tortuga::Packet::ChatMessage
}
