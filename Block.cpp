#include "Block.hpp"

Tortuga::Block::Block ( const Tortuga::Block::Type type , const Tortuga::Block::Metadata metadata ) :
	type ( type ) ,
	metadata ( metadata )
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

ARC::Void Tortuga::Block::setMetadata ( const Tortuga::Block::Metadata metadata )
{
	this->metadata = metadata ;
}
Tortuga::Block::Metadata Tortuga::Block::getMetadata ( ) const
{
	return this->metadata ;
}
