#pragma once

#include <ARC.hpp>
#include <Tortuga/Entity/Entity.hpp>

namespace Tortuga
{
    class EntityManager ;

    class CreatureEntity : public Tortuga::Entity
    {
        private :

        public :
            CreatureEntity ( EntityManager & entityManager , const Tortuga::Entity::Type type , const Tortuga::Location & location ) ;

            ARC::Void update ( ) ;
    } ;
}
