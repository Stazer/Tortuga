#pragma once

#include <ARC.hpp>
#include <Tortuga/World/Dimension.hpp>
#include <Tortuga/World/Chunk.hpp>
#include <Tortuga/Difficulty.hpp>
#include <Tortuga/Gamemode.hpp>

namespace Tortuga
{
	class Client ;
	class WorldManager ;
	class Player ;

	class World
	{
		private :
			Tortuga::WorldManager & worldManager ;

			Tortuga::Gamemode::Type gamemode ;
			Tortuga::Dimension::Type dimension ;
			Tortuga::Difficulty::Type difficulty ;

			ARC::Vector3SignedInt spawnPosition ;

			ARC::UnsignedLong age ;
			ARC::UnsignedLong time ;

			ARC::List <Tortuga::Chunk> chunks ;

			ARC::List <Tortuga::Player *> players ;

		public :
			World ( Tortuga::WorldManager & worldManager , const Tortuga::Gamemode::Type gamemode = Tortuga::Gamemode::Creative , const Tortuga::Dimension::Type dimension = Tortuga::Dimension::Normal , const Tortuga::Difficulty::Type difficulty = Tortuga::Difficulty::Normal , const ARC::Vector3SignedInt & spawnPosition = ARC::Vector3SignedInt ( ) , const ARC::UnsignedLong age = 0 , const ARC::UnsignedLong time = 0 ) ;

			Tortuga::WorldManager & getWorldManager ( ) ;
			const Tortuga::WorldManager & getWorldManager ( ) const ;

			ARC::Void setGamemode ( const Tortuga::Gamemode::Type gamemode ) ;
			Tortuga::Gamemode::Type getGamemode ( ) const ;

			ARC::Void setDimension ( const Tortuga::Dimension::Type dimension ) ;
			Tortuga::Dimension::Type getDimension ( ) const ;

			ARC::Void setDifficulty ( const Tortuga::Difficulty::Type difficulty ) ;
			Tortuga::Difficulty::Type getDifficulty ( ) const ;

			ARC::Void setSpawnPosition ( const ARC::Vector3SignedInt & spawnPosition ) ;
			const ARC::Vector3SignedInt & getSpawnPosition ( ) const ;

			ARC::Void setAge ( const ARC::UnsignedLong age ) ;
			ARC::UnsignedLong getAge ( ) const ;

			ARC::Void setTime ( const ARC::UnsignedLong time ) ;
			ARC::UnsignedLong getTime ( ) const ;

			ARC::List <Tortuga::Chunk> & getChunks ( ) ;
			const ARC::List <Tortuga::Chunk> & getChunks ( ) const ;

			ARC::List <Tortuga::Player *> & getPlayers ( ) ;
			const ARC::List <Tortuga::Player *> & getPlayers ( ) const ;

			ARC::Void update ( ) ;

			static Tortuga::World getTestWorld ( Tortuga::World world ) ;
	} ;
}
