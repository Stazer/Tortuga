#pragma once

#include <ARC.hpp>
#include <Tortuga/World/Block.hpp>

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
			
			ARC::UnsignedLong getArrayPosition ( const ARC::Vector3SignedInt & position ) const ;
			
			
		public :
			Chunk ( const ARC::Vector2SignedInt & position = ARC::Vector2SignedInt ( ) ) ;
			
			operator ARC::Buffer ( ) const ;
		
			ARC::Void setPosition ( const ARC::Vector2SignedInt & position ) ;
			ARC::Vector2SignedInt & getPosition ( ) ;
			const ARC::Vector2SignedInt & getPosition ( ) const ;
			
			ARC::Void setBlock ( const ARC::Vector3SignedInt & position , const Tortuga::Block block ) ;
			Tortuga::Block getBlock ( const ARC::Vector3SignedInt & position ) const ;
			
			ARC::Void setBlockType ( const ARC::Vector3SignedInt & position , const Tortuga::Block::Type type ) ;
			Tortuga::Block::Type getBlockType ( const ARC::Vector3SignedInt & position ) ;
			
			ARC::Void setBlockMetadata ( const ARC::Vector3SignedInt & position , const Tortuga::Block::Metadata metadata ) ;
			Tortuga::Block::Metadata getBlockMetadata ( const ARC::Vector3SignedInt & position ) ;
			
			static Chunk getTestChunk ( Tortuga::Chunk chunk = Tortuga::Chunk ( ) ) ;
	} ;
}
