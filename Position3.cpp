#include "Position3.hpp"

Tortuga::Position3::Position3 ( const ARC::Double x , const ARC::Double y , const ARC::Double z ) :
	Position2 ( x , y ) ,
	z ( z )
	
{
}

ARC::Void Tortuga::Position3::setZ ( const ARC::Double z )
{
	this->z = z ;
}
ARC::Double Tortuga::Position3::getZ ( ) const
{
	return this->z ;
}
