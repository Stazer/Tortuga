#include <Tortuga/Protocol/PlayerPositionAndLookToServerPacket.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::PlayerPositionAndLookToServerPacket::read ( Tortuga::PacketReader & packetReader )
{
	this->location.getPosition ( ).setX ( packetReader.readDouble ( ) ) ;
	this->location.getPosition ( ).setY ( packetReader.readDouble ( ) ) ; // feet
	packetReader.readDouble ( ) ; // head
	this->location.getPosition ( ).setZ ( packetReader.readDouble ( ) ) ;
	this->location.getOrientation ( ).setX ( packetReader.readFloat ( ) ) ;
	this->location.getOrientation ( ).setY ( packetReader.readFloat ( ) ) ;
	this->onGround = packetReader.readBool ( ) ;
}
ARC::Void Tortuga::PlayerPositionAndLookToServerPacket::write ( Tortuga::PacketWriter & packetWriter ) const
{
	packetWriter.writeVariableInt ( Tortuga::Packet::PlayerPositionAndLookToServer ) ;
	packetWriter.writeDouble ( this->location.getPosition ( ).getX ( ) ) ;
	packetWriter.writeDouble ( this->location.getPosition ( ).getY ( ) ) ; // feet
	packetWriter.writeDouble ( this->location.getPosition ( ).getY ( ) + 1.62 ) ; // head
	packetWriter.writeDouble ( this->location.getPosition ( ).getZ ( ) ) ;
	packetWriter.writeFloat ( this->location.getOrientation ( ).getX ( ) ) ;
	packetWriter.writeFloat ( this->location.getOrientation ( ).getY ( ) ) ;
	packetWriter.writeBool ( this->onGround ) ;
}

Tortuga::PlayerPositionAndLookToServerPacket::PlayerPositionAndLookToServerPacket ( Tortuga::PacketReader & packetReader )
{
	this->read ( packetReader ) ;
}
Tortuga::PlayerPositionAndLookToServerPacket::PlayerPositionAndLookToServerPacket ( const Tortuga::Location & location , ARC::Bool onGround ) :
	location ( location ) ,
	onGround ( onGround )
{
}

ARC::Void Tortuga::PlayerPositionAndLookToServerPacket::setLocation ( const Tortuga::Location & location )
{
	this->location = location ;
}
Tortuga::Location & Tortuga::PlayerPositionAndLookToServerPacket::getLocation ( )
{
	return this->location ;
}
const Tortuga::Location & Tortuga::PlayerPositionAndLookToServerPacket::getLocation ( ) const
{
	return this->location ;
}

ARC::Void Tortuga::PlayerPositionAndLookToServerPacket::setOnGround ( ARC::Bool onGround )
{
	this->onGround = onGround ;
}
ARC::Bool Tortuga::PlayerPositionAndLookToServerPacket::getOnGround ( ) const
{
	return this->onGround ;
}
