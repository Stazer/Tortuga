#pragma once

#include <ARC.hpp>
#include <Tortuga/Protocol/Packet.hpp>
#include <Tortuga/Orientation.hpp>

namespace Tortuga
{
	class PlayerLookPacket : public Tortuga::Packet
	{
		private :
			Tortuga::Orientation orientation ;
			ARC::Bool onGround ;
		
			ARC::Void read ( Tortuga::PacketReader & packetReader ) ;
			ARC::Void write ( Tortuga::PacketWriter & packetWriter ) const ;
			
		public :
			PlayerLookPacket ( Tortuga::PacketReader & packetReader ) ;
			PlayerLookPacket ( const Tortuga::Orientation & orientation , const ARC::Bool onGround ) ;
			
			ARC::Void setOrientation ( const Tortuga::Orientation & orientation ) ;
			Tortuga::Orientation & getOrientation ( ) ;
			const Tortuga::Orientation & getOrientation ( ) const ;
			
			ARC::Void setOnGround ( const ARC::Bool onGround ) ;
			ARC::Bool getOnGround ( ) const ;
	} ;
}
