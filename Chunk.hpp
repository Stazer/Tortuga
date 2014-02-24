#pragma once

#include <ARC.hpp>

namespace Tortuga
{
	class Client ;

	class Chunk
	{
		private :
			static const ARC::UnsignedLong size = 16 * 16 * 256 ;
		
			ARC::UnsignedChar data [ Tortuga::Chunk::size ] ;
			ARC::Vector2SignedInt position ;
			
		public :
			Chunk ( const ARC::Vector2SignedInt & position = ARC::Vector2SignedInt ( ) ) ;
		
			ARC::Void setPosition ( const ARC::Vector2SignedInt & position ) ;
			ARC::Vector2SignedInt & getPosition ( ) ;
			const ARC::Vector2SignedInt & getPosition ( ) const ;
			
			ARC::Void send ( Tortuga::Client & client ) ;
	} ;
}
