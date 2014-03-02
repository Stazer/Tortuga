#pragma once

#include <ARC.hpp>
#include <Tortuga/Protocol/Packet.hpp>

namespace Tortuga
{
	class SpawnPositionPacket : public Tortuga::Packet
	{
		private :
			ARC::Vector3SignedInt position ;
			
			ARC::Void read ( Tortuga::PacketReader & packetReader ) ;
			ARC::Void write ( Tortuga::PacketWriter & packetWriter ) const ;
			
		public :
			SpawnPositionPacket ( Tortuga::PacketReader & packetReader ) ;
			SpawnPositionPacket ( const ARC::Vector3SignedInt & position ) ;
			
			ARC::Void setPosition ( const ARC::Vector3SignedInt & position ) ;
			const ARC::Vector3SignedInt & getPosition ( ) const ;
	} ;
}
