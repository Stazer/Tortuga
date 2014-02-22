#pragma once

#include <ARC.hpp>

namespace Tortuga
{
	class Position
	{
		private :
			ARC::Double x ;
			ARC::Double y ;
			ARC::Double z ;
	
		public :
			Position ( const ARC::Double x = 0 , const ARC::Double y = 0 , const ARC::Double z = 0 ) ;
			
			ARC::Void setX ( const ARC::Double x ) ;
			ARC::Double setX ( ) const ;
			
			ARC::Void setY ( const ARC::Double y ) ;
			ARC::Double getY ( ) const ;
			
			ARC::Void setZ ( const ARC::Double z ) ;
			ARC::Double getZ ( ) const ;
	} ;
}
