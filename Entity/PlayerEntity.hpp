#pragma once

#include <ARC.hpp>
#include <Tortuga/Entity/Entity.hpp>

namespace Tortuga
{
    class Client ;

    class PlayerEntity : public Tortuga::Entity
    {
        private :
            Tortuga::Client & client ;

            ARC::String name ;

        public :
            PlayerEntity ( Tortuga::Client & client , Tortuga::EntityManager & entityManager , const Tortuga::Location & location , const ARC::String & name ) ;

            Tortuga::Client & getClient ( ) ;
            const Tortuga::Client & getClient ( ) const ;

            ARC::Void setName ( const ARC::String & name ) ;
            const ARC::String & getName ( ) const ;
    } ;
}
