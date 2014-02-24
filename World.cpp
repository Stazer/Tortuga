#include "World.hpp"
#include "Client.hpp"
#include "Packet.hpp"
#include <cryptopp/zlib.h>

Tortuga::World::World ( )
{
	// DEBUG
	for ( int x = -10 ; x <= 10 ; ++x )
		for ( int y = -10 ; y <= 10 ; ++y )
			this->chunks.push_back ( Tortuga::Chunk ( x ,y ) ) ;
}
