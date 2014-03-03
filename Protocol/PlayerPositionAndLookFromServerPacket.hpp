#pragma once

#include <ARC.hpp>
#include <Tortuga/Protocol/Packet.hpp>
#include <Tortuga/Location.hpp>

namespace Tortuga
{
	class PlayerPositionAndLookFromServerPacket : public Tortuga::Packet
	{
		private :
			Tortuga::Location location ;
			ARC::Bool onGround ;
		
			ARC::Void read ( Tortuga::PacketReader & packetReader ) ;
			ARC::Void write ( Tortuga::PacketWriter & packetWriter ) const ;
			
		public :
			PlayerPositionAndLookFromServerPacket ( Tortuga::PacketReader & packetReader ) ;
			PlayerPositionAndLookFromServerPacket ( const Tortuga::Location & location , const ARC::Bool onGround ) ;
			
			ARC::Void setLocation ( const Tortuga::Location & location ) ;
			Tortuga::Location & getLocation ( ) ;
			const Tortuga::Location & getLocation ( ) const ;
			
			ARC::Void setOnGround ( const ARC::Bool onGround ) ;
			ARC::Bool getOnGround ( ) const ;
	} ;
}
