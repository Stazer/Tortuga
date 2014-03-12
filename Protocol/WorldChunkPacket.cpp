#include <Tortuga/Protocol/WorldChunkPacket.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::WorldChunkPacket::read ( Tortuga::PacketReader & packetReader )
{
	this->position.setX ( packetReader.readInt ( ) ) ;
	this->position.setY ( packetReader.readInt ( ) ) ;
	this->groundUpContinuous = packetReader.readBool ( ) ;
	this->primaryBitmask = packetReader.readShort ( ) ;
	this->addBitmask = packetReader.readShort ( ) ;

	ARC::UnsignedInt size = packetReader.readInt ( ) ;

	for ( ARC::UnsignedInt element = 0 ; element < size ; ++element )
		this->data.push_back ( packetReader.readChar ( ) ) ;
}
ARC::Void Tortuga::WorldChunkPacket::write ( Tortuga::PacketWriter & packetWriter ) const
{
	packetWriter.writeVariableInt ( Tortuga::Packet::WorldChunk ) ;
	packetWriter.writeInt ( this->position.getX ( ) ) ;
	packetWriter.writeInt ( this->position.getY ( ) ) ;
	packetWriter.writeBool ( this->groundUpContinuous ) ;
	packetWriter.writeShort ( this->primaryBitmask ) ;
	packetWriter.writeShort ( this->addBitmask ) ;

	packetWriter.writeInt ( this->data.size ( ) ) ;

	for ( auto element : this->data )
		packetWriter.writeChar ( element ) ;
}

Tortuga::WorldChunkPacket::WorldChunkPacket ( Tortuga::PacketReader & packetReader )
{
	this->read ( packetReader ) ;
}
Tortuga::WorldChunkPacket::WorldChunkPacket ( const ARC::Vector2SignedInt & position , ARC::Bool groundUpContinuous , ARC::UnsignedShort primaryBitmask , ARC::UnsignedShort addBitmask , const ARC::Buffer & data ) :
	position ( position ) ,
	groundUpContinuous ( groundUpContinuous ) ,
	primaryBitmask ( primaryBitmask ) ,
	addBitmask ( addBitmask ) ,
	data ( data )
{
}

ARC::Void Tortuga::WorldChunkPacket::setPosition ( const ARC::Vector2SignedInt & position )
{
	this->position = position ;
}
ARC::Vector2SignedInt & Tortuga::WorldChunkPacket::getPosition ( )
{
	return this->position ;
}
const ARC::Vector2SignedInt & Tortuga::WorldChunkPacket::getPosition ( ) const
{
	return this->position ;
}

ARC::Void Tortuga::WorldChunkPacket::setGroundUpContinuous ( ARC::Bool groundUpContinuous )
{
	this->groundUpContinuous = groundUpContinuous ;
}
ARC::Bool Tortuga::WorldChunkPacket::getGroundUpContinuous ( ) const
{
	return this->groundUpContinuous ;
}

ARC::Void Tortuga::WorldChunkPacket::setPrimaryBitmask ( ARC::UnsignedShort primaryBitmask )
{
	this->primaryBitmask = primaryBitmask ;
}
ARC::UnsignedShort Tortuga::WorldChunkPacket::getPrimaryBitmask ( ) const
{
	return this->primaryBitmask ;
}

ARC::Void Tortuga::WorldChunkPacket::setAddBitmask ( ARC::UnsignedShort addBitmask )
{
	this->addBitmask = addBitmask ;
}
ARC::UnsignedShort Tortuga::WorldChunkPacket::getAddBitmask ( ) const
{
	return this->addBitmask ;
}

ARC::Void Tortuga::WorldChunkPacket::setData ( const ARC::Buffer & data )
{
	this->data = data ;
}
const ARC::Buffer & Tortuga::WorldChunkPacket::getData ( ) const
{
	return this->data ;
}
