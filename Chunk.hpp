#pragma once

#include <ARC.hpp>
#include "Packet.hpp"

namespace Tortuga
{
	class Client ;

	class Chunk
	{
		public :
			enum
			{
				Width = 16 ,
				Height = 256 ,
				Size = Width * Height * Width
			} ;
			
		private :		
			ARC::Vector2SignedInt position ;
				
			ARC::UnsignedChar type [ Tortuga::Chunk::Size ] ;
			ARC::UnsignedChar metadata [ Tortuga::Chunk::Size / 2 ] ;
			ARC::UnsignedChar light [ Tortuga::Chunk::Size / 2 ] ;
			ARC::UnsignedChar skylight [ Tortuga::Chunk::Size / 2 ] ;
			
			ARC::UnsignedChar add [ Tortuga::Chunk::Size ] ;
			ARC::UnsignedChar biome [ Tortuga::Chunk::Width * Tortuga::Chunk::Width ] ;
			
			
		public :
			Chunk ( const ARC::Vector2SignedInt & position = ARC::Vector2SignedInt ( ) ) ;
			
			operator ARC::Buffer ( ) const ;
		
			ARC::Void setPosition ( const ARC::Vector2SignedInt & position ) ;
			ARC::Vector2SignedInt & getPosition ( ) ;
			const ARC::Vector2SignedInt & getPosition ( ) const ;
			
			static Chunk getTestChunk ( Tortuga::Chunk chunk = Tortuga::Chunk ( ) , const ARC::UnsignedLong steps = 5 ) ;
	} ;
}
