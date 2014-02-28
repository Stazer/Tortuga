#include "World.hpp"
#include "Client.hpp"
#include "Chunk.hpp"
#include "Packet.hpp"

Tortuga::World::World ( Tortuga::WorldManager & worldManager , const Tortuga::Dimension::Type dimension , const Tortuga::Difficulty::Type difficulty , const ARC::Vector3SignedInt & spawnPosition ) :
	worldManager ( worldManager ) ,
	dimension ( dimension ) ,
	difficulty ( difficulty ) ,
	spawnPosition ( spawnPosition )
{
}

Tortuga::WorldManager & Tortuga::World::getWorldManager ( )
{
	return this->worldManager ;
}
const Tortuga::WorldManager & Tortuga::World::getWorldManager ( ) const
{
	return this->worldManager ;
}

ARC::Void Tortuga::World::setDimension ( const Tortuga::Dimension::Type dimension )
{
	this->dimension = dimension ;
}
Tortuga::Dimension::Type Tortuga::World::getDimension ( ) const
{
	return this->dimension ;
}
			
ARC::Void Tortuga::World::setDifficulty ( const Tortuga::Difficulty::Type difficulty )
{
	this->difficulty = difficulty ;
}
Tortuga::Difficulty::Type Tortuga::World::getDifficulty ( ) const
{
	return this->difficulty ;
}

ARC::Void Tortuga::World::setSpawnPosition ( const ARC::Vector3SignedInt & spawnPosition )
{
	this->spawnPosition = spawnPosition ;
}
const ARC::Vector3SignedInt & Tortuga::World::getSpawnPosition ( ) const
{
	return this->spawnPosition ;
}

ARC::List <Tortuga::Player *> & Tortuga::World::getPlayers ( )
{
	return this->players ;
}
const ARC::List <Tortuga::Player *> & Tortuga::World::getPlayers ( ) const
{
	return this->players ;
}

Tortuga::World Tortuga::World::getTestWorld ( Tortuga::World world )
{
	for ( ARC::UnsignedShort x = -10 ; x <= 10 ; ++x )
		for ( ARC::UnsignedShort y = -10 ; y <= 10 ; ++y )
			world.chunks.push_back ( ARC::SharedPointer <Tortuga::Chunk> ( new Tortuga::Chunk ( Tortuga::Chunk::getTestChunk ( ) ) ) ) ;
			
	return world ;
}
