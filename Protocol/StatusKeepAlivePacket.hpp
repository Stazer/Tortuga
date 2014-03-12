#pragma once

#include <ARC.hpp>
#include <Tortuga/Protocol/Packet.hpp>

namespace Tortuga
{
	class StatusKeepAlivePacket : public Tortuga::Packet
	{
		private :
			ARC::UnsignedLong time ;

			ARC::Void read ( Tortuga::PacketReader & packetReader ) ;
			ARC::Void write ( Tortuga::PacketWriter & packetWriter ) const ;

		public :
			StatusKeepAlivePacket ( Tortuga::PacketReader & packetReader ) ;
			StatusKeepAlivePacket ( ARC::UnsignedLong time ) ;

			ARC::Void setTime ( ARC::UnsignedLong time ) ;
			ARC::UnsignedLong getTime ( ) const ;
	} ;
}
