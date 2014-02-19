#pragma once

#include <ARC.hpp>

namespace Tortuga
{
	class Orientation
	{
		private :
			ARC::Float yaw ;
			ARC::Float pitch ;
	
		public :
			Orientation ( const ARC::Float yaw = 0 , const ARC::Float pitch = 0 ) ;
			
			ARC::Void setYaw ( const ARC::Float yaw ) ;
			ARC::Double getYaw ( ) const ;
			
			ARC::Void setPitch ( const ARC::Float pitch ) ;
			ARC::Double getPitch ( ) const ;
	} ;
}
