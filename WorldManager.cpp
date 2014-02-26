#include "WorldManager.hpp"
#include "Server.hpp"
#include "Packet.hpp"
#include "ChatUser.hpp"

Tortuga::WorldManager::WorldManager ( Tortuga::Server & server ) :
	server ( server )
{
}

Tortuga::Server & Tortuga::WorldManager::getServer ( )
{
	return this->server ;
}
const Tortuga::Server & Tortuga::WorldManager::getServer ( ) const
{
	return this->server ;
}

ARC::Vector <ARC::SharedPointer <Tortuga::World>> & Tortuga::WorldManager::getWorlds ( )
{
	return this->worlds ;
}
const ARC::Vector <ARC::SharedPointer <Tortuga::World>> & Tortuga::WorldManager::getWorlds ( ) const
{
	return this->worlds ;
}
