#pragma once

#include <ARC.hpp>
#include <Tortuga/Protocol/Packet.hpp>
#include <Tortuga/Position.hpp>

namespace Tortuga
{
	class PlayerPositionPacket : public Tortuga::Packet
	{
		private :
			Tortuga::Position position ;
			ARC::Bool onGround ;
		
			ARC::Void read ( Tortuga::PacketReader & packetReader ) ;
			ARC::Void write ( Tortuga::PacketWriter & packetWriter ) const ;
			
		public :
			PlayerPositionPacket ( Tortuga::PacketReader & packetReader ) ;
			PlayerPositionPacket ( const Tortuga::Position & position , const ARC::Bool onGround ) ;
			
			ARC::Void setPosition ( const Tortuga::Position & position ) ;
			Tortuga::Position & getPosition ( ) ;
			const Tortuga::Position & getPosition ( ) const ;
			
			ARC::Void setOnGround ( const ARC::Bool onGround ) ;
			ARC::Bool getOnGround ( ) const ;
	} ;
}
