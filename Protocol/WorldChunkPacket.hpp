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
			WorldChunkPacket ( const ARC::Vector2SignedInt & position , const ARC::Bool groundUpContinuous , const ARC::UnsignedShort primaryBitmask , const ARC::UnsignedShort addBitmask , const ARC::Buffer & data ) ;
			
			ARC::Void setPosition ( const ARC::Vector2SignedInt & position ) ;
			ARC::Vector2SignedInt & getPosition ( ) ;
			const ARC::Vector2SignedInt & getPosition ( ) const ;
			
			ARC::Void setGroundUpContinuous ( const ARC::Bool groundUpContinuous ) ;
			ARC::Bool getGroundUpContinuous ( ) const ;
			
			ARC::Void setPrimaryBitmask ( const ARC::UnsignedShort primaryBitmask ) ;
			ARC::UnsignedShort getPrimaryBitmask ( ) const ;
			
			ARC::Void setAddBitmask ( const ARC::UnsignedShort addBitmask ) ;
			ARC::UnsignedShort getAddBitmask ( ) const ;
			
			ARC::Void setData ( const ARC::Buffer & data ) ;
			const ARC::Buffer & getData ( ) const ;
	} ;
}

/*

Tortuga::Packet Tortuga::Packet::writeWorldChunkPacket ( const Tortuga::Packet::WorldChunkData & worldChunkData )
{
	Tortuga::Packet packet ;
	
	packet.writeVariableInt ( Tortuga::Packet::WorldChunk ) ;
	packet.writeInt ( worldChunkData.x ) ;
	packet.writeInt ( worldChunkData.z ) ;
	packet.writeBool ( worldChunkData.groundUpContinuous ) ;
	packet.writeShort ( worldChunkData.primaryBitmask ) ;
	packet.writeShort ( worldChunkData.addBitmask ) ;
	packet.writeInt ( worldChunkData.data->size ( ) ) ;
	
	for ( auto element : * worldChunkData.data )
		packet.writeChar ( element ) ;

	return Tortuga::Packet::write ( packet ) ;		
}

*/
