#include "Block.hpp"

Tortuga::Block::Block ( const Tortuga::Block::Type type ) :
	type ( type )
{
}

ARC::Void Tortuga::Block::setType ( const Tortuga::Block::Type type )
{
	this->type = type ;
}
Tortuga::Block::Type Tortuga::Block::getType ( ) const
{
	return this->type ;
}
