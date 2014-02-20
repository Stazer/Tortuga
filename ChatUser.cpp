#include "ChatUser.hpp"
#include "Chat.hpp"

Tortuga::ChatUser::ChatUser ( Tortuga::Chat & chat , Tortuga::Client & client , const ARC::String & name ) :
	name ( name ) ,
	chat ( chat ) ,
	client ( client )
{
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
