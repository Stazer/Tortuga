#include <Tortuga/Entity/Entity.hpp>
#include <Tortuga/Entity/EntityManager.hpp>

Tortuga::Entity::Entity ( Tortuga::EntityManager & entityManager , Tortuga::Entity::Type type , const Tortuga::Location & location ) :
    entityManager ( entityManager ) ,
    identification ( entityManager.getFreeIdentification ( ) ) ,
    type ( type ) ,
    location ( location )
{
}
Tortuga::Entity::~Entity ( )
{
}

Tortuga::EntityManager & Tortuga::Entity::getEntityManager ( )
{
    return this->entityManager ;
}
const Tortuga::EntityManager & Tortuga::Entity::getEntityManager ( ) const
{
    return this->entityManager ;
}

ARC::UnsignedInt Tortuga::Entity::getIdentification ( ) const
{
    return this->identification ;
}

Tortuga::Entity::Type Tortuga::Entity::getType ( ) const
{
    return this->type ;
}

ARC::Void Tortuga::Entity::setLocation ( const Tortuga::Location & location )
{
    this->location = location ;
}
Tortuga::Location & Tortuga::Entity::getLocation ( )
{
    return this->location ;
}
const Tortuga::Location & Tortuga::Entity::getLocation ( ) const
{
    return this->location ;
}

ARC::Void Tortuga::Entity::update ( )
{
}