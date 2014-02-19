#include "Location.hpp"

Tortuga::Location::Location ( const ARC::Double positionX , const ARC::Double positionY , const ARC::Double positionZ , const ARC::Float yaw , const ARC::Float pitch ) :
	Position ( positionX , positionY , positionZ ) ,
	Orientation ( yaw , pitch )
{
}
