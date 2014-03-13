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

Tortuga::CreatureEntity::CreatureEntity ( EntityManager & entityManager , Tortuga::Entity::Type type , const Tortuga::Location & location ) :
    Tortuga::Entity ( entityManager , type , location )
{
}

#include <iostream>

ARC::Void Tortuga::CreatureEntity::update ( )
{
    std::cout << "Hello World" ;

    /*// spawn entity for new clients
    for ( auto & client : this->getEntityManager ( ).getWorld ( ).getWorldManager ( ).getServer ( ).getClientManager ( ).getClients ( ) )
    {
        ARC::Bool spawned = false ;
/
        for ( auto & savedClient : this->clients )
        {
            if ( client == savedClient )
            {
                spawned = true ;
                break ;
            }
        }
*
        if ( ! spawned )
        {
            Tortuga::EntityMetadata entityMetadata ;
            entityMetadata.getRecords ( ) [ Tortuga::EntityMetadata::Health ] = 10.0f ;

            client.send ( Tortuga::SpawnMobPacket ( this->getIdentification ( ) , this->getType ( ) , this->getLocation ( ) , 0 , ARC::Vector3SignedShort ( ) , entityMetadata ) ) ;

         //   this->clients.push_back ( & client ) ;
        }
    }*/

    // test movement ;)
}