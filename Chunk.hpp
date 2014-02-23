#pragma once

#include <ARC.hpp>
#include "Posiiton2.hpp"

namespace Tortuga
{
	class Client ;

	class Chunk
	{
		private :
			static const ARC::UnsignedLong size = 16 * 16 * 256 ;
		
			ARC::UnsignedChar data [ Tortuga::Chunk::size ] ;
			Tortuga::Position2 position ;
			
		public :
			ARC::Void setPosition ( const Tortuga::Position2 & position ) ;
			Tortuga::Position2 & getPosition ( ) ;
			const Tortuga::Position2 & getPosition ( ) const ;
			
			ARC::Void send ( Tortuga::Client & client ) ;
	} ;
}
