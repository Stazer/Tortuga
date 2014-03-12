#include <Tortuga/Location.hpp>

Tortuga::Location::Location ( const Tortuga::Position & position , const Tortuga::Orientation & orientation ) :
	position ( position ) ,
	orientation ( orientation )
{
}

ARC::Void Tortuga::Location::setPosition ( const Tortuga::Position & position )
{
	this->position = position ;
}
Tortuga::Position & Tortuga::Location::getPosition ( )
{
	return this->position ;
}
const Tortuga::Position & Tortuga::Location::getPosition ( ) const
{
	return this->position ;
}

ARC::Void Tortuga::Location::setOrientation ( const Tortuga::Orientation & orientation )
{
	this->orientation = orientation ;
}
Tortuga::Orientation & Tortuga::Location::getOrientation ( )
{
	return this->orientation ;
}
const Tortuga::Orientation & Tortuga::Location::getOrientation ( ) const
{
	return this->orientation ;
}