#pragma once

#include <ARC.hpp>
#include <Tortuga/Protocol/Packet.hpp>
#include <Tortuga/Location.hpp>

namespace Tortuga
{
	class PlayerPositionAndLookToServerPacket : public Tortuga::Packet
	{
		private :
			Tortuga::Location location ;
			ARC::Bool onGround ;

			ARC::Void read ( Tortuga::PacketReader & packetReader ) ;
			ARC::Void write ( Tortuga::PacketWriter & packetWriter ) const ;

		public :
			PlayerPositionAndLookToServerPacket ( Tortuga::PacketReader & packetReader ) ;
			PlayerPositionAndLookToServerPacket ( const Tortuga::Location & location , ARC::Bool onGround ) ;

			ARC::Void setLocation ( const Tortuga::Location & location ) ;
			Tortuga::Location & getLocation ( ) ;
			const Tortuga::Location & getLocation ( ) const ;

			ARC::Void setOnGround ( ARC::Bool onGround ) ;
			ARC::Bool getOnGround ( ) const ;
	} ;
}
