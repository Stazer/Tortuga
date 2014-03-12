#include <Tortuga/Entity/EntityManager.hpp>
#include <Tortuga/Entity/Entity.hpp>

Tortuga::EntityManager::EntityManager ( Tortuga::World & world ) :
    world ( world )
{
}

Tortuga::World & Tortuga::EntityManager::getWorld ( )
{
    return this->world ;
}
const Tortuga::World & Tortuga::EntityManager::getWorld ( ) const
{
    return this->world ;
}

ARC::List <Tortuga::Entity> & Tortuga::EntityManager::getEntities ( )
{
    return this->entities ;
}
const ARC::List <Tortuga::Entity> & Tortuga::EntityManager::getEntities ( ) const
{
    return this->entities ;
}

ARC::UnsignedInt Tortuga::EntityManager::getFreeIdentification ( ) const
{
    for ( auto entity = this->entities.begin ( ) ; entity != this->entities.end ( ) ; ++entity )
    {
        const ARC::UnsignedInt distance = std::distance ( this->entities.begin ( ) , entity ) ;

        if ( entity->getIdentification ( ) != distance )
            return distance ;
    }

    return this->entities.size ( ) ;
}

ARC::Void Tortuga::EntityManager::update ( )
{
    for ( auto & entity : this->entities )
        entity.update ( ) ;
}
