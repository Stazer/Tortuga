#include "StatusManager.hpp"
#include "Client.hpp"
#include "Packet.hpp"

Tortuga::StatusManager::StatusManager ( Tortuga::Server & server ) :
	server ( server )
{
}

Tortuga::Server & Tortuga::StatusManager::getServer ( )
{
	return this->server ;
}
const Tortuga::Server & Tortuga::StatusManager::getServer ( ) const
{
	return this->server ;
}

ARC::Void Tortuga::StatusManager::initialize ( )
{
}
ARC::Void Tortuga::StatusManager::finalize ( )
{
}

ARC::Void Tortuga::StatusManager::update ( )
{
}
