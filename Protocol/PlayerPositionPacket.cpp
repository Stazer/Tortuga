#include <Tortuga/Protocol/PlayerPositionPacket.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::PlayerPositionPacket::read ( Tortuga::PacketReader & packetReader )
{
	this->position.setX ( packetReader.readDouble ( ) ) ;
	this->position.setY ( packetReader.readDouble ( ) ) ; // feet
	packetReader.readDouble ( ) ; // head
	this->position.setZ ( packetReader.readDouble ( ) ) ;
	this->onGround = packetReader.readBool ( ) ;
}
ARC::Void Tortuga::PlayerPositionPacket::write ( Tortuga::PacketWriter & packetWriter ) const
{
	packetWriter.writeVariableInt ( Tortuga::Packet::PlayerPosition ) ;
	packetWriter.writeDouble ( this->position.getX ( ) ) ;
	packetWriter.writeDouble ( this->position.getY ( ) ) ; // feet
	packetWriter.writeDouble ( this->position.getY ( ) + 1.62 ) ; // head
	packetWriter.writeDouble ( this->position.getZ ( ) ) ;
	packetWriter.writeBool ( this->onGround ) ;
}

Tortuga::PlayerPositionPacket::PlayerPositionPacket ( Tortuga::PacketReader & packetReader )
{
	this->read ( packetReader ) ;
}
Tortuga::PlayerPositionPacket::PlayerPositionPacket ( const Tortuga::Position & position , ARC::Bool onGround ) :
	position ( position ) ,
	onGround ( onGround )
{
}

ARC::Void Tortuga::PlayerPositionPacket::setPosition ( const Tortuga::Position & position )
{
	this->position = position ;
}
Tortuga::Position & Tortuga::PlayerPositionPacket::getPosition ( )
{
	return this->position ;
}
const Tortuga::Position & Tortuga::PlayerPositionPacket::getPosition ( ) const
{
	return this->position ;
}

ARC::Void Tortuga::PlayerPositionPacket::setOnGround ( ARC::Bool onGround )
{
	this->onGround = onGround ;
}
ARC::Bool Tortuga::PlayerPositionPacket::getOnGround ( ) const
{
	return this->onGround ;
}
