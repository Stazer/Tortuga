#include "Chat.hpp"
#include "ChatUser.hpp"
#include "ChatMessage.hpp"

Tortuga::Chat::Chat ( Tortuga::Server & server ) :
	server ( server )
{
}

Tortuga::Server & Tortuga::Chat::getServer ( )
{
	return this->server ;
}
const Tortuga::Server & Tortuga::Chat::getServer ( ) const
{
	return this->server ;
}

ARC::List <ARC::SharedPointer <Tortuga::ChatUser>> & Tortuga::Chat::getChatUsers ( )
{
	return this->chatUsers ;
}
const ARC::List <ARC::SharedPointer <Tortuga::ChatUser>> & Tortuga::Chat::getChatUsers ( ) const
{
	return this->chatUsers ;
}
			
ARC::Void Tortuga::Chat::send ( const Tortuga::ChatMessage & message )
{
	for ( auto chatUser : this->chatUsers )
		chatUser->send ( message ) ;
}
