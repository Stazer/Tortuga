#include "Position.hpp"

Tortuga::Position::Position ( const ARC::Double x , const ARC::Double y , const ARC::Double z ) :
	x ( x ) ,
	y ( y ) ,
	z ( z )
	
{
}

ARC::Void Tortuga::Position::setX ( const ARC::Double x )
{
	this->x = x ;
}
ARC::Double Tortuga::Position::getX ( ) const
{
	return this->x ;
}

ARC::Void Tortuga::Position::setY ( const ARC::Double y )
{
	this->y = y ;
}
ARC::Double Tortuga::Position::getY ( ) const
{
	return this->y ;
}

ARC::Void Tortuga::Position::setZ ( const ARC::Double z )
{
	this->z = z ;
}
ARC::Double Tortuga::Position::getZ ( ) const
{
	return this->z ;
}
