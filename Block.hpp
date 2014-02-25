#pragma once

#include <ARC.hpp>

namespace Tortuga
{
	class Block
	{
		public :
			enum Type
			{
				Air = 0 ,
				Stone = 1 ,
				Grass = 2 ,
				Dirt = 3 ,
				Cobblestone = 4 ,
				Wood = 5
			} ;
			
		private :
			Type type ;
			
		public :
			Block ( const Tortuga::Block::Type type ) ;
			
			ARC::Void setType ( const Tortuga::Block::Type type ) ;
			Tortuga::Block::Type getType ( ) const ;
	} ;
}
