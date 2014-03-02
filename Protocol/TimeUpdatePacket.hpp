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
			TimeUpdatePacket ( const ARC::UnsignedLong age , const ARC::UnsignedLong time ) ;
			
			ARC::Void setAge ( const ARC::UnsignedLong age ) ;
			ARC::UnsignedLong getAge ( ) const ;
			
			ARC::Void setTime ( const ARC::UnsignedLong time ) ;
			ARC::UnsignedLong getTime ( ) const ;
	} ;
}
