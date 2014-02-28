#include "WorldManager.hpp"
#include "Server.hpp"
#include "Packet.hpp"
#include "ChatUser.hpp"
#include "World.hpp"

Tortuga::WorldManager::WorldManager ( Tortuga::Server & server ) :
	server ( server )
{
	this->worlds.push_back ( Tortuga::World::getTestWorld ( * this ) ) ;
	this->setDefaultWorld ( * this->worlds.begin ( ) ) ;
}

Tortuga::Server & Tortuga::WorldManager::getServer ( )
{
	return this->server ;
}
const Tortuga::Server & Tortuga::WorldManager::getServer ( ) const
{
	return this->server ;
}

ARC::List <Tortuga::World> & Tortuga::WorldManager::getWorlds ( )
{
	return this->worlds ;
}
const ARC::List <Tortuga::World> & Tortuga::WorldManager::getWorlds ( ) const
{
	return this->worlds ;
}

ARC::Void Tortuga::WorldManager::setDefaultWorld ( Tortuga::World & defaultWorld )
{
	this->defaultWorld = & defaultWorld ;
}
Tortuga::World & Tortuga::WorldManager::getDefaultWorld ( )
{
	return * this->defaultWorld ;
}
const Tortuga::World & Tortuga::WorldManager::getDefaultWorld ( ) const
{
	return * this->defaultWorld ;
}
