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

ARC::Void Tortuga::WorldManager::initialize ( )
{
}
ARC::Void Tortuga::WorldManager::finalize ( )
{
}
			
ARC::Void Tortuga::WorldManager::update ( )
{
}

