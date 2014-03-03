#pragma once

#include <ARC.hpp>
#include <Tortuga/Position.hpp>
#include <Tortuga/Orientation.hpp>

namespace Tortuga
{
	class Location 
	{
		private :
			Tortuga::Position position ;
			Tortuga::Orientation orientation ;
		
		public :
			Location ( const Tortuga::Position & position = Tortuga::Position ( ) , const Tortuga::Orientation & orientation = Tortuga::Orientation ( ) ) ;
			
			ARC::Void setPosition ( const Tortuga::Position & position ) ;
			Tortuga::Position & getPosition ( ) ;
			const Tortuga::Position & getPosition ( ) const ;
			
			ARC::Void setOrientation ( const Tortuga::Orientation & orientation ) ;
			Tortuga::Orientation & getOrientation ( ) ;
			const Tortuga::Orientation & getOrientation ( ) const ;
	} ;
}
