#pragma once

#include <ARC.hpp>
#include <Tortuga/Protocol/Packet.hpp>

namespace Tortuga
{
	class KeepAlivePacket : public Tortuga::Packet
	{
		private :
			ARC::UnsignedInt identification ;

			ARC::Void read ( Tortuga::PacketReader & packetReader ) ;
			ARC::Void write ( Tortuga::PacketWriter & packetWriter ) const ;

		public :
			KeepAlivePacket ( Tortuga::PacketReader & packetReader ) ;
			KeepAlivePacket ( ARC::UnsignedInt identification ) ;

			ARC::Void setIdentification ( ARC::UnsignedInt identification ) ;
			ARC::UnsignedInt getIdentification ( ) const ;
	} ;
}
