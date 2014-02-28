#pragma once

#include <ARC.hpp>
#include "Dimension.hpp"
#include "Difficulty.hpp"

namespace Tortuga
{
	class Client ;
	class WorldManager ;
	class Chunk ;
	class Player ;

	class World
	{
		private :
			Tortuga::WorldManager & worldManager ;
		
			Tortuga::Dimension::Type dimension ;
			Tortuga::Difficulty::Type difficulty ;
			
			ARC::Vector3SignedInt spawnPosition ;
		
			ARC::List <ARC::SharedPointer <Tortuga::Chunk>> chunks ;
	
			ARC::List <Tortuga::Player *> players ;
	
		public :
			World ( Tortuga::WorldManager & worldManager , const Tortuga::Dimension::Type dimension = Tortuga::Dimension::Normal , const Tortuga::Difficulty::Type difficulty = Tortuga::Difficulty::Normal , const ARC::Vector3SignedInt & spawnPosition = ARC::Vector3SignedInt ( ) ) ;
			
			Tortuga::WorldManager & getWorldManager ( ) ;
			const Tortuga::WorldManager & getWorldManager ( ) const ;
			
			ARC::Void setDimension ( const Tortuga::Dimension::Type dimension ) ;
			Tortuga::Dimension::Type getDimension ( ) const ;
			
			ARC::Void setDifficulty ( const Tortuga::Difficulty::Type difficulty ) ;
			Tortuga::Difficulty::Type getDifficulty ( ) const ;
			
			ARC::Void setSpawnPosition ( const ARC::Vector3SignedInt & spawnPosition ) ;
			const ARC::Vector3SignedInt & getSpawnPosition ( ) const ;
			
			ARC::List <Tortuga::Player *> & getPlayers ( ) ;
			const ARC::List <Tortuga::Player *> & getPlayers ( ) const ;
			
			static Tortuga::World getTestWorld ( Tortuga::World world ) ;
	} ;
}
