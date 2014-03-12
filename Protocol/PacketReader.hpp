#pragma once

#include <ARC.hpp>

namespace Tortuga
{
	class PacketReader
	{
		private :
			ARC::Vector <ARC::UnsignedChar> buffer ;
			ARC::UnsignedLong position ;

		public :
			PacketReader ( ) ;

			ARC::Void read ( const ARC::Buffer & buffer ) ;

			const ARC::Buffer & getBuffer ( ) const ;

			ARC::UnsignedLong getPosition ( ) const ;
			ARC::Void setPosition ( ARC::UnsignedLong position ) ;

			ARC::UnsignedChar readChar ( ) ;
			ARC::UnsignedShort readShort ( ) ;
			ARC::UnsignedInt readInt ( ) ;
			ARC::UnsignedLong readLong ( ) ;
			ARC::UnsignedInt readVariableInt ( ) ;
			ARC::Float readFloat ( ) ;
			ARC::Double readDouble ( ) ;
			ARC::String readString ( ) ;
			ARC::Bool readBool ( ) ;
	} ;
}
