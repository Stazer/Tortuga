#include "WorldManager.hpp"
#include "Server.hpp"
#include "Packet.hpp"
#include "ChatUser.hpp"
#include "World.hpp"

Tortuga::WorldManager::WorldManager ( Tortuga::Server & server ) :
	server ( server )
{
	ARC::SharedPointer <Tortuga::World> world ( new Tortuga::World ( Tortuga::World::getTestWorld ( ) ) ) ;
	
	this->defaultWorld = world ;
	this->worlds.push_back ( world ) ;
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

ARC::Void Tortuga::WorldManager::setDefaultWorld ( Tortuga::World & defaultWorld )
{
	this->defaultWorld = ARC::SharedPointer <Tortuga::World> ( & defaultWorld ) ;
}
Tortuga::World & Tortuga::WorldManager::getDefaultWorld ( )
{
	return * this->defaultWorld ;
}
const Tortuga::World & Tortuga::WorldManager::getDefaultWorld ( ) const
{
	return * this->defaultWorld ;
}
