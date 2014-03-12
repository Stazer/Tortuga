#pragma once

#include <ARC.hpp>

namespace Tortuga
{
	class PacketWriter
	{
		private :
			ARC::Vector <ARC::UnsignedChar> buffer ;

		public :
			ARC::Buffer write ( ) const ;

			const ARC::Buffer & getBuffer ( ) const ;

			ARC::Void writeChar ( ARC::UnsignedChar value ) ;
			ARC::Void writeShort ( ARC::UnsignedShort value ) ;
			ARC::Void writeInt ( ARC::UnsignedInt value ) ;
			ARC::Void writeLong ( ARC::UnsignedLong value ) ;
			ARC::Void writeVariableInt ( ARC::UnsignedInt value ) ;
			ARC::Void writeFloat ( ARC::Float value ) ;
			ARC::Void writeDouble ( ARC::Double value ) ;
			ARC::Void writeString ( const ARC::String & value ) ;
			ARC::Void writeBool ( ARC::Bool value ) ;
	} ;
}
