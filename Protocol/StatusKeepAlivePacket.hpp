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
			StatusKeepAlivePacket ( const ARC::UnsignedLong time ) ;
			
			ARC::Void setTime ( const ARC::UnsignedLong time ) ;
			ARC::UnsignedLong getTime ( ) const ;
	} ;
}
