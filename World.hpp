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
			World ( Tortuga::WorldManager & worldManager , const Tortuga::Dimension::Type dimension = Tortuga::Dimension::Normal , const Tortuga::Difficulty::Type difficulty = Tortuga::Difficulty::Normal ) ;
			
			Tortuga::WorldManager & getWorldManager ( ) ;
			const Tortuga::WorldManager & getWorldManager ( ) const ;
			
			ARC::Void setDimension ( const Tortuga::Dimension::Type dimension ) ;
			Tortuga::Dimension::Type getDimension ( ) const ;
			
			ARC::Void setDifficulty ( const Tortuga::Difficulty::Type difficulty ) ;
			Tortuga::Difficulty::Type getDifficulty ( ) const ;
			
			static Tortuga::World getTestWorld ( Tortuga::World world ) ;
	} ;
}
