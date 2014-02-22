#pragma once

#include <ARC.hpp>
#include "Position.hpp"
#include "Orientation.hpp"

namespace Tortuga
{
	class Location : public Tortuga::Position , public Tortuga::Orientation
	{	
		public :
			Location ( const ARC::Double x = 0 , const ARC::Double y = 0 , const ARC::Double z = 0 , const ARC::Float yaw = 0 , const ARC::Float pitch = 0 ) ;
	} ;
}
