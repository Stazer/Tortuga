#include "Position.hpp"

Tortuga::Position::Position ( const ARC::Double positionX , const ARC::Double positionY , const ARC::Double positionZ ) :
	positionX ( positionX ) ,
	positionY ( positionY ) ,
	positionZ ( positionZ )
	
{
}

ARC::Void Tortuga::Position::setPositionX ( const ARC::Double positionX )
{
	this->positionX = positionX ;
}
ARC::Double Tortuga::Position::getPositionX ( ) const
{
	return this->positionX ;
}

ARC::Void Tortuga::Position::setPositionY ( const ARC::Double positionY )
{
	this->positionY = positionY ;
}
ARC::Double Tortuga::Position::getPositionY ( ) const
{
	return this->positionY ;
}

ARC::Void Tortuga::Position::setPositionZ ( const ARC::Double positionZ )
{
	this->positionZ = positionZ ;
}
ARC::Double Tortuga::Position::getPositionZ ( ) const
{
	return this->positionZ ;
}
