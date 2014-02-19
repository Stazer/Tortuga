#pragma once

#include <ARC.hpp>

namespace Tortuga
{
	class Position
	{
		private :
			ARC::Double positionX ;
			ARC::Double positionY ;
			ARC::Double positionZ ;
	
		public :
			Position ( const ARC::Double positionX = 0 , const ARC::Double positionY = 0 , const ARC::Double positionZ = 0 ) ;
			
			ARC::Void setPositionX ( const ARC::Double positionX ) ;
			ARC::Double getPositionX ( ) const ;
			
			ARC::Void setPositionY ( const ARC::Double positionY ) ;
			ARC::Double getPositionY ( ) const ;
			
			ARC::Void setPositionZ ( const ARC::Double positionZ ) ;
			ARC::Double getPositionZ ( ) const ;
	} ;
}
