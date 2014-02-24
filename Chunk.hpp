#pragma once

#include <ARC.hpp>
#include "Position2.hpp"

namespace Tortuga
{
	class Client ;

	class Chunk
	{
		private :
			static const ARC::UnsignedLong size = 16 * 16 * 256 ;
		
			ARC::UnsignedChar data [ Tortuga::Chunk::size ] ;
			Tortuga::Position2SignedInt position ;
			
		public :
			Chunk ( const Tortuga::Position2SignedInt & position = Tortuga::Position2SignedInt ( ) ) ;
		
			ARC::Void setPosition ( const Tortuga::Position2SignedInt & position ) ;
			Tortuga::Position2SignedInt & getPosition ( ) ;
			const Tortuga::Position2SignedInt & getPosition ( ) const ;
			
			ARC::Void send ( Tortuga::Client & client ) ;
	} ;
}
