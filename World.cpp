#include "World.hpp"
#include "Client.hpp"
#include "Chunk.hpp"
#include "Packet.hpp"

Tortuga::World::World ( Tortuga::WorldManager & worldManager ) :
	worldManager ( worldManager )
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

Tortuga::World Tortuga::World::getTestWorld ( Tortuga::World world )
{
	for ( ARC::UnsignedShort x = -10 ; x <= 10 ; ++x )
		for ( ARC::UnsignedShort y = -10 ; y <= 10 ; ++y )
			world.chunks.push_back ( ARC::SharedPointer <Tortuga::Chunk> ( new Tortuga::Chunk ( Tortuga::Chunk::getTestChunk ( ) ) ) ) ;
			
	return world ;
}
