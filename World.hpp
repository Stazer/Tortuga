#pragma once

#include <ARC.hpp>
#include "Dimension.hpp"
#include "Difficulty.hpp"

namespace Tortuga
{
	class Client ;
	class WorldManager ;
	class Chunk ;

	class World
	{
		private :
			Tortuga::WorldManager & worldManager ;
		
			Tortuga::Dimension::Type dimension ;
			Tortuga::Difficulty::Type difficulty ;
		
			ARC::List <ARC::SharedPointer <Tortuga::Chunk>> chunks ;
	
		public :
			World ( Tortuga::WorldManager & worldManager ) ;
			
			Tortuga::WorldManager & getWorldManager ( ) ;
			const Tortuga::WorldManager & getWorldManager ( ) const ;
			
			static Tortuga::World getTestWorld ( Tortuga::World world ) ;
	} ;
}
