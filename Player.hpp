#pragma once

#include "Location.hpp"

namespace Tortuga
{
	class Client ;
	class Packet ;

	class Player
	{
		private :
			Tortuga::Client & client ;
		
			Tortuga::Location location ;
			
			ARC::Bool onGround ;
	
		public :
			Player ( Tortuga::Client & client ) ;
			
			Tortuga::Client & getClient ( ) ;
			const Tortuga::Client & getClient ( ) const ;
		
			ARC::Void setLocation ( const Tortuga::Location & location ) ;
			Tortuga::Location & getLocation ( ) ;
			const Tortuga::Location & getLocation ( ) const ;
			
			ARC::Void setOnGround ( const ARC::Bool onGround ) ;
			const ARC::Bool getOnGround ( ) const ;
			const ARC::Bool isOnGround ( ) const ;
	} ;
}
