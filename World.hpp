#pragma once

#include <ARC.hpp>
#include "Chunk.hpp"

namespace Tortuga
{
	class Client ;
	class WorldManager ;

	class World
	{
		private :
			ARC::Vector <Tortuga::Chunk> chunks ;
	
		public :
			World ( ) ;
	} ;
}
