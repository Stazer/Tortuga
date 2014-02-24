#pragma once

#include <ARC.hpp>
#include "Chunk.hpp"

namespace Tortuga
{
	class Client ;
	class WorldManager ;

	class World
	{
		private :
			ARC::Vector <Tortuga::Chunk> chunks ;
	
		public :
			World ( ) ;
			
			/*static ARC::Void writeTimeUpdate ( Tortuga::Client & client , const ARC::UnsignedLong ageOfWorld , const ARC::UnsignedLong timeOfDay ) ;
			static ARC::Void writeSpawnPositionPacket ( Tortuga::Client & client , const ARC::SignedInt positionX , const ARC::SignedInt positionY , const ARC::SignedInt positionZ ) ;
			
			static ARC::Void writeChunkData ( Tortuga::Client & client , const ARC::SignedInt positionX , const ARC::SignedInt positionY , const ARC::Bool groundUpContinuous , const ARC::UnsignedShort primaryBitmask , const ARC::UnsignedShort addBitmask , const ARC::UnsignedInt dataSize , const ARC::UnsignedChar * data ) ;*/
	} ;
}
