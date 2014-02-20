#include "Chat.hpp"
#include "Server.hpp"
#include "Packet.hpp"
#include "ChatUser.hpp"

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

ARC::List <ARC::SharedPointer <Tortuga::ChatUser>> Tortuga::Chat::getChatUsers ( )
{
	return this->chatUsers ;
}
const ARC::List <ARC::SharedPointer <Tortuga::ChatUser>> Tortuga::Chat::getChatUsers ( ) const
{
	return this->chatUsers ;
}
