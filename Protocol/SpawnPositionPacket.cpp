#include <Tortuga/Protocol/SpawnPositionPacket.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::SpawnPositionPacket::read ( Tortuga::PacketReader & packetReader )
{
	this->position.setX ( packetReader.readInt ( ) ) ;
	this->position.setY ( packetReader.readInt ( ) ) ;
	this->position.setZ ( packetReader.readInt ( ) ) ;
}
ARC::Void Tortuga::SpawnPositionPacket::write ( Tortuga::PacketWriter & packetWriter ) const
{
	packetWriter.writeVariableInt ( Tortuga::Packet::SpawnPosition ) ;
	packetWriter.writeInt ( this->position.getX ( ) ) ;
	packetWriter.writeInt ( this->position.getY ( ) ) ;
	packetWriter.writeInt ( this->position.getZ ( ) ) ;
}

Tortuga::SpawnPositionPacket::SpawnPositionPacket ( Tortuga::PacketReader & packetReader )
{
	this->read ( packetReader ) ;
}
Tortuga::SpawnPositionPacket::SpawnPositionPacket ( const ARC::Vector3SignedInt & position ) :
	position ( position )
{
}

ARC::Void Tortuga::SpawnPositionPacket::setPosition ( const ARC::Vector3SignedInt & position )
{
	this->position = position ;
}
const ARC::Vector3SignedInt & Tortuga::SpawnPositionPacket::getPosition ( ) const
{
	return this->position ;
}
