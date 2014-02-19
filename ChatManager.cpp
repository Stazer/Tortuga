#include "ChatManager.hpp"
#include "Server.hpp"
#include "Packet.hpp"
#include "ChatUser.hpp"

Tortuga::ChatManager::ChatManager ( Tortuga::Server & server ) :
	server ( server )
{
}

Tortuga::Server & Tortuga::ChatManager::getServer ( )
{
	return this->server ;
}
const Tortuga::Server & Tortuga::ChatManager::getServer ( ) const
{
	return this->server ;
}

ARC::List <ARC::SharedPointer <Tortuga::ChatUser>> Tortuga::ChatManager::getChatUsers ( )
{
	return this->chatUsers ;
}
const ARC::List <ARC::SharedPointer <Tortuga::ChatUser>> Tortuga::ChatManager::getChatUsers ( ) const
{
	return this->chatUsers ;
}

ARC::Void Tortuga::ChatManager::initialize ( )
{
}
ARC::Void Tortuga::ChatManager::finalize ( )
{
}
			
ARC::Void Tortuga::ChatManager::update ( )
{
}
