#include <Tortuga/Entity/CreatureEntity.hpp>
#include <Tortuga/Entity/EntityManager.hpp>
#include <Tortuga/Entity/PlayerEntity.hpp>
#include <Tortuga/World/WorldManager.hpp>
#include <Tortuga/World/World.hpp>
#include <Tortuga/Client/Client.hpp>
#include <Tortuga/Protocol/EntityMetadata.hpp>
#include <Tortuga/Protocol/SpawnMobPacket.hpp>
#include <Tortuga/Client/ClientManager.hpp>
#include <Tortuga/Server/Server.hpp>

#include <iostream>

Tortuga::CreatureEntity::CreatureEntity ( EntityManager & entityManager , const Tortuga::Entity::Type type , const Tortuga::Location & location ) :
    Tortuga::Entity ( entityManager , type , location )
{
}

ARC::Void Tortuga::CreatureEntity::update ( )
{
    for ( auto client : this->getEntityManager ( ).getWorld ( ).getWorldManager ( ).getServer ( ).getClientManager ( ).getClients ( ) )
    {

    }
}
