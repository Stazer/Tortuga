#pragma once

#include <ARC.hpp>

namespace Tortuga
{
	class Position2
	{
		private :
			ARC::Double x ;
			ARC::Double y ;
	
		public :
			Position2 ( const ARC::Double x = 0 , const ARC::Double y = 0 ) ;
			
			ARC::Void setX ( const ARC::Double x ) ;
			ARC::Double getX ( ) const ;
			
			ARC::Void setY ( const ARC::Double y ) ;
			ARC::Double getY ( ) const ;
	} ;
}
