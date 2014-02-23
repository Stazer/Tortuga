#pragma once

#include <ARC.hpp>
#include "Position2.hpp"

namespace Tortuga
{
	class Position3 : public Tortuga::Position2
	{
		private :
			ARC::Double z ;
	
		public :
			Position ( const ARC::Double x = 0 , const ARC::Double y = 0 , const ARC::Double z = 0 ) ;
			
			ARC::Void setZ ( const ARC::Double z ) ;
			ARC::Double getZ ( ) const ;
	} ;
}
