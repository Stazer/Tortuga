#pragma once

#include <ARC.hpp>
#include <Tortuga/Protocol/Packet.hpp>

namespace Tortuga
{
	class WorldChunkPacket : public Tortuga::Packet
	{
		private :
			ARC::Vector2SignedInt position ;
			ARC::Bool groundUpContinuous ;
			ARC::UnsignedShort primaryBitmask ;
			ARC::UnsignedShort addBitmask ;
			ARC::Buffer data ;

			ARC::Void read ( Tortuga::PacketReader & packetReader ) ;
			ARC::Void write ( Tortuga::PacketWriter & packetWriter ) const ;

		public :
			WorldChunkPacket ( Tortuga::PacketReader & packetReader ) ;
			WorldChunkPacket ( const ARC::Vector2SignedInt & position , ARC::Bool groundUpContinuous , ARC::UnsignedShort primaryBitmask , ARC::UnsignedShort addBitmask , const ARC::Buffer & data ) ;

			ARC::Void setPosition ( const ARC::Vector2SignedInt & position ) ;
			ARC::Vector2SignedInt & getPosition ( ) ;
			const ARC::Vector2SignedInt & getPosition ( ) const ;

			ARC::Void setGroundUpContinuous ( ARC::Bool groundUpContinuous ) ;
			ARC::Bool getGroundUpContinuous ( ) const ;

			ARC::Void setPrimaryBitmask ( ARC::UnsignedShort primaryBitmask ) ;
			ARC::UnsignedShort getPrimaryBitmask ( ) const ;

			ARC::Void setAddBitmask ( ARC::UnsignedShort addBitmask ) ;
			ARC::UnsignedShort getAddBitmask ( ) const ;

			ARC::Void setData ( const ARC::Buffer & data ) ;
			const ARC::Buffer & getData ( ) const ;
	} ;
}