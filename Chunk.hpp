#pragma once

#include <ARC.hpp>

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
		
			ARC::Void setPosition ( const ARC::Vector2SignedInt & position ) ;
			ARC::Vector2SignedInt & getPosition ( ) ;
			const ARC::Vector2SignedInt & getPosition ( ) const ;
			
			ARC::Void send ( Tortuga::Client & client ) ;
			
			static Chunk getTestChunk ( ) ;
	} ;
}
