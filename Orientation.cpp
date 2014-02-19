#include "Orientation.hpp"

Tortuga::Orientation::Orientation ( const ARC::Float yaw , const ARC::Float pitch ) :
	yaw ( yaw ) ,
	pitch ( pitch )
	
{
}

ARC::Void Tortuga::Orientation::setYaw ( const ARC::Float yaw )
{
	this->yaw = yaw ;
}
ARC::Double Tortuga::Orientation::getYaw ( ) const
{
	return this->yaw ;
}

ARC::Void Tortuga::Orientation::setPitch ( const ARC::Float pitch )
{
	this->pitch = pitch ;
}
ARC::Double Tortuga::Orientation::getPitch ( ) const
{
	return this->pitch ;
}
