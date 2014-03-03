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
				WoodPlanks = 5
			} ;
			
			enum Metadata
			{
				None = 0 ,
			
				OakWoodPlanks = 0 ,
				SpruceWoodPlanks = 1 ,
				BirchWoodPlanks = 2 ,
				JungleWoodPlanks = 3 ,
				AcaciaWoodPlanks = 4 ,
				DarkOakWoodPlanks = 5
			} ;
			
		private :
			Type type ;
			Metadata metadata ;
			
		public :
			Block ( const Tortuga::Block::Type type , const Tortuga::Block::Metadata metadata = Tortuga::Block::None ) ;
			
			ARC::Void setType ( const Tortuga::Block::Type type ) ;
			Tortuga::Block::Type getType ( ) const ;
			
			ARC::Void setMetadata ( const Tortuga::Block::Metadata metadata ) ;
			Tortuga::Block::Metadata getMetadata ( ) const ;
	} ;
}
