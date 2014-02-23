#pragma once

#include <ARC.hpp>
#include "Position2.hpp"

namespace Tortuga
{
	template <class Type>
	class Position3 : public Tortuga::Position2 <Type>
	{
		private :
			ARC::Double z ;
	
		public :
			Position3 ( const Type x = 0 , const Type y = 0 , const ARC::Double z = 0 ) :
				Position2 <Type> ( x , y ) ,
				z ( z )
			{
			}
			
			ARC::Void setZ ( const Type z )
			{
				this->z = z ;
			}
			Type getZ ( ) const
			{
				return this->z ;
			}
	} ;
	
	using Position3Double = Position3 <ARC::Double> ;
	using Position3Float = Position3 <ARC::Float> ;
	using Position3SignedInt = Position3 <ARC::SignedInt> ;
}
