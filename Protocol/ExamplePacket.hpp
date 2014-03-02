#pragma once

#include <ARC.hpp>
#include <Tortuga/Protocol/Packet.hpp>

namespace Tortuga
{
	class ExamplePacket : public Tortuga::Packet
	{
		private :
			ARC::Void read ( Tortuga::PacketReader & packetReader ) ;
			ARC::Void write ( Tortuga::PacketWriter & packetWriter ) const ;
			
		public :
			ExamplePacket ( Tortuga::PacketReader & packetReader ) ;
			ExamplePacket ( ) ;
	} ;
}
