#include <Tortuga/Entity/PlayerEntity.hpp>

Tortuga::PlayerEntity::PlayerEntity ( Tortuga::Client & client , Tortuga::EntityManager & entityManager , const Tortuga::Location & location , const ARC::String & name ) :
    Tortuga::Entity ( entityManager , Tortuga::Entity::Player , location ) ,
    client ( client ) ,
    name ( name )
{
}

Tortuga::Client & Tortuga::PlayerEntity::getClient ( )
{
    return this->client ;
}
const Tortuga::Client & Tortuga::PlayerEntity::getClient ( ) const
{
    return this->client ;
}

ARC::Void Tortuga::PlayerEntity::setName ( const ARC::String & name )
{
    this->name = name ;
}
const ARC::String & Tortuga::PlayerEntity::getName ( ) const
{
    return this->name ;
}
