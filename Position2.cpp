#include "Position2.hpp"

Tortuga::Position2::Position2 ( const ARC::Double x , const ARC::Double y ) :
	x ( x ) ,
	y ( y )
	
{
}

ARC::Void Tortuga::Position2::setX ( const ARC::Double x )
{
	this->x = x ;
}
ARC::Double Tortuga::Position2::getX ( ) const
{
	return this->x ;
}

ARC::Void Tortuga::Position2::setY ( const ARC::Double y )
{
	this->y = y ;
}
ARC::Double Tortuga::Position2::getY ( ) const
{
	return this->y ;
}
