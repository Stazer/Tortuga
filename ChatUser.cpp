#include "ChatUser.hpp"
#include "ChatManager.hpp"

Tortuga::ChatUser::ChatUser ( Tortuga::ChatManager & chatManager , Tortuga::Client & client , const ARC::String & name ) :
	name ( name ) ,
	chatManager ( chatManager ) ,
	client ( client )
{
}

Tortuga::ChatManager & Tortuga::ChatUser::getChatManager ( )
{
	return this->chatManager ;
}
const Tortuga::ChatManager & Tortuga::ChatUser::getChatManager ( ) const
{
	return this->chatManager ;
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
