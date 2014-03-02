#pragma once

#include <ARC.hpp>
#include <Tortuga/Protocol/Packet.hpp>

namespace Tortuga
{
	class StatusRequestPacket : public Tortuga::Packet
	{
		private :
			ARC::Void read ( Tortuga::PacketReader & packetReader ) ;
			ARC::Void write ( Tortuga::PacketWriter & packetWriter ) const ;
			
		public :
			StatusRequestPacket ( Tortuga::PacketReader & packetReader ) ;
			StatusRequestPacket ( ) ;
	} ;
}
