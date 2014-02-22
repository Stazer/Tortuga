#include "Location.hpp"

Tortuga::Location::Location ( const ARC::Double x , const ARC::Double y , const ARC::Double z , const ARC::Float yaw , const ARC::Float pitch ) :
	Position ( x , y , z ) ,
	Orientation ( yaw , pitch )
{
}
