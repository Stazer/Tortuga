#pragma once

#include <ARC.hpp>
#include <Tortuga/Entity/Entity.hpp>

namespace Tortuga
{
    class World ;

    class EntityManager
    {
        private :
            Tortuga::World & world ;

            ARC::List <Tortuga::Entity> entities ;

        public :
            EntityManager ( Tortuga::World & world ) ;

            Tortuga::World & getWorld ( ) ;
            const Tortuga::World & getWorld ( ) const ;

            ARC::List <Tortuga::Entity> & getEntities ( ) ;
            const ARC::List <Tortuga::Entity> & getEntities ( ) const ;

            ARC::UnsignedInt getFreeIdentification ( ) const ;

            ARC::Void update ( ) ;
    } ;
}
