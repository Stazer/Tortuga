#include <Tortuga/Protocol/PlayerLookPacket.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::PlayerLookPacket::read ( Tortuga::PacketReader & packetReader )
{
	this->orientation.setX ( packetReader.readFloat ( ) ) ;
	this->orientation.setY ( packetReader.readFloat ( ) ) ;
	this->onGround = packetReader.readBool ( ) ;
}
ARC::Void Tortuga::PlayerLookPacket::write ( Tortuga::PacketWriter & packetWriter ) const
{
	packetWriter.writeVariableInt ( Tortuga::Packet::PlayerLook ) ;
	packetWriter.writeFloat ( this->orientation.getX ( ) ) ;
	packetWriter.writeFloat ( this->orientation.getY ( ) ) ;
	packetWriter.writeBool ( this->onGround ) ;
}

Tortuga::PlayerLookPacket::PlayerLookPacket ( Tortuga::PacketReader & packetReader )
{
	this->read ( packetReader ) ;
}
Tortuga::PlayerLookPacket::PlayerLookPacket ( const Tortuga::Orientation & orientation , ARC::Bool onGround ) :
	orientation ( orientation ) ,
	onGround ( onGround )
{
}

ARC::Void Tortuga::PlayerLookPacket::setOrientation ( const Tortuga::Orientation & orientation )
{
	this->orientation = orientation ;
}
Tortuga::Orientation & Tortuga::PlayerLookPacket::getOrientation ( )
{
	return this->orientation ;
}
const Tortuga::Orientation & Tortuga::PlayerLookPacket::getOrientation ( ) const
{
	return this->orientation ;
}

ARC::Void Tortuga::PlayerLookPacket::setOnGround ( ARC::Bool onGround )
{
	this->onGround = onGround ;
}
ARC::Bool Tortuga::PlayerLookPacket::getOnGround ( ) const
{
	return this->onGround ;
}
