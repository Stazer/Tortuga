#pragma once

#include <ARC.hpp>
#include <Tortuga/Protocol/Packet.hpp>

namespace Tortuga
{
	class TimeUpdatePacket : public Tortuga::Packet
	{
		private :
			ARC::UnsignedLong age ;
			ARC::UnsignedLong time ;

			ARC::Void read ( Tortuga::PacketReader & packetReader ) ;
			ARC::Void write ( Tortuga::PacketWriter & packetWriter ) const ;

		public :
			TimeUpdatePacket ( Tortuga::PacketReader & packetReader ) ;
			TimeUpdatePacket ( ARC::UnsignedLong age , ARC::UnsignedLong time ) ;

			ARC::Void setAge ( ARC::UnsignedLong age ) ;
			ARC::UnsignedLong getAge ( ) const ;

			ARC::Void setTime ( ARC::UnsignedLong time ) ;
			ARC::UnsignedLong getTime ( ) const ;
	} ;
}