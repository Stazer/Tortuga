#include "Chat.hpp"

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

ARC::Vector <ARC::SharedPointer <Tortuga::ChatUser>> & Tortuga::Chat::getChatUsers ( )
{
	return this->chatUsers ;
}
const ARC::Vector <ARC::SharedPointer <Tortuga::ChatUser>> & Tortuga::Chat::getChatUsers ( ) const
{
	return this->chatUsers ;
}
			
ARC::Void Tortuga::Chat::send ( const ARC::String & message )
{
}
