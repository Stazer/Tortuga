#include "World.hpp"
#include "Client.hpp"
#include "Packet.hpp"

Tortuga::World::World ( )
{
}

Tortuga::World Tortuga::World::getTestWorld ( Tortuga::World world )
{
	for ( ARC::UnsignedShort x = -10 ; x <= 10 ; ++x )
		for ( ARC::UnsignedShort y = -10 ; y <= 10 ; ++y )
			world.chunks.push_back ( Tortuga::Chunk::getTestChunk ( Tortuga::Chunk ( ARC::Vector2SignedInt ( x , y ) ) ) ) ;
			
	return world ;
}
