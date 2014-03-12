#pragma once

#include <ARC.hpp>
#include <Tortuga/Location.hpp>

namespace Tortuga
{
    class EntityManager ;
    class Client ;

    class Entity
    {
        public :
            enum Type
            {
                Player = 0 ,
                Creeper = 50 ,
                Skeleton = 51 ,
                Spider = 52 ,
                GiantZombie = 53 ,
                Zombie = 54
            } ;

        private :
            Tortuga::EntityManager & entityManager ;
            ARC::UnsignedInt identification ;
            Tortuga::Entity::Type type ;
            Tortuga::Location location ;

        protected :
            Entity ( Tortuga::EntityManager & entityManager , Tortuga::Entity::Type type , const Tortuga::Location & location ) ;

        public :
            virtual ~Entity ( ) ;

            Tortuga::EntityManager & getEntityManager ( ) ;
            const Tortuga::EntityManager & getEntityManager ( ) const ;

            ARC::UnsignedInt getIdentification ( ) const ;

            Tortuga::Entity::Type getType ( ) const ;

            ARC::Void setLocation ( const Tortuga::Location & location ) ;
            Tortuga::Location & getLocation ( ) ;
            const Tortuga::Location & getLocation ( ) const ;

            virtual ARC::Void update ( ) ;
    } ;
}
