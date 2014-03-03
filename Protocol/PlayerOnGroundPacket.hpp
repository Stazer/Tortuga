#pragma once

#include <ARC.hpp>
#include <Tortuga/Protocol/Packet.hpp>

namespace Tortuga
{
	class PlayerOnGroundPacket : public Tortuga::Packet
	{
		private :
			ARC::Bool onGround ;
		
			ARC::Void read ( Tortuga::PacketReader & packetReader ) ;
			ARC::Void write ( Tortuga::PacketWriter & packetWriter ) const ;
			
		public :
			PlayerOnGroundPacket ( Tortuga::PacketReader & packetReader ) ;
			PlayerOnGroundPacket ( const ARC::Bool onGround ) ;
			
			ARC::Void setOnGround ( const ARC::Bool onGround ) ;
			ARC::Bool getOnGround ( ) const ;
	} ;
}
