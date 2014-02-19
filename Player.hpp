#pragma once

#include "Location.hpp"

namespace Tortuga
{
	class Client ;
	class Packet ;

	class Player
	{
		private :
			Tortuga::Location location ;
			
			ARC::Bool onGround ;
	
		public :
			Player ( ) ;
		
			ARC::Void setLocation ( const Tortuga::Location & location ) ;
			Tortuga::Location & getLocation ( ) ;
			const Tortuga::Location & getLocation ( ) const ;
			
			const ARC::Bool getOnGround ( ) const ;
			const ARC::Bool isOnGround ( ) const ;
	} ;
}
