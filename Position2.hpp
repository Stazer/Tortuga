#pragma once

#include <ARC.hpp>

namespace Tortuga
{
	template <class Type>
	class Position2
	{
		private :
			Type x ;
			Type y ;
	
		public :
			Position2 ( const Type x = 0 , const Type y = 0 ) :
				x ( x ) ,
				y ( y )
			{
			}
			
			ARC::Void setX ( const Type x )
			{
				this->x = x ;
			}
			Type getX ( ) const
			{
				return this->x ;
			}
			
			ARC::Void setY ( const Type y )
			{
				this->y = y ;
			}
			Type getY ( ) const
			{
				return this->y ;
			}
	} ;
	
	using Position2Double = Position2 <ARC::Double> ;
	using Position2Float = Position2 <ARC::Float> ;
	using Position2SignedInt = Position2 <ARC::SignedInt> ;
}
