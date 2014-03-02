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
		
			ARC::Void writeChar ( const ARC::UnsignedChar value ) ;
			ARC::Void writeShort ( const ARC::UnsignedShort value ) ;
			ARC::Void writeInt ( const ARC::UnsignedInt value ) ;
			ARC::Void writeLong ( const ARC::UnsignedLong value ) ;
			ARC::Void writeVariableInt ( ARC::UnsignedInt value ) ;
			ARC::Void writeFloat ( const ARC::Float value ) ;
			ARC::Void writeDouble ( const ARC::Double value ) ;
			ARC::Void writeString ( const ARC::String & value ) ;
			ARC::Void writeBool ( const ARC::Bool value ) ;
	} ;
}
