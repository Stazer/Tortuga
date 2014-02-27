#pragma once

#include <ARC.hpp>
#include "Location.hpp"

namespace Tortuga
{
	class Client ;
	class Packet ;
	class World ;

	class Player
	{
		private :
			Tortuga::Client & client ;
		
			Tortuga::Location location ;
			
			ARC::Bool onGround ;
	
		public :
			Player ( Tortuga::Client & client ) ;
			~Player ( ) ;
			
			Tortuga::Client & getClient ( ) ;
			const Tortuga::Client & getClient ( ) const ;
		
			ARC::Void setLocation ( const Tortuga::Location & location ) ;
			Tortuga::Location & getLocation ( ) ;
			const Tortuga::Location & getLocation ( ) const ;
			
			ARC::Void setOnGround ( const ARC::Bool onGround ) ;
			const ARC::Bool getOnGround ( ) const ;
			const ARC::Bool isOnGround ( ) const ;
			
			ARC::Void handlePlayerOnGround ( Tortuga::Packet & packet ) ;
			ARC::Void handlePlayerPosition ( Tortuga::Packet & packet ) ;
			ARC::Void handlePlayerLook ( Tortuga::Packet & packet ) ;
			ARC::Void handlePlayerPositionAndLook ( Tortuga::Packet & packet ) ;
	} ;
}
