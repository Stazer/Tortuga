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
			
		public :
			ARC::Void send ( Tortuga::Client & client ) ;
	} ;
}
