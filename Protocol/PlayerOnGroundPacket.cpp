#include <Tortuga/Protocol/PlayerOnGroundPacket.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::PlayerOnGroundPacket::read ( Tortuga::PacketReader & packetReader )
{
	this->onGround = packetReader.readBool ( ) ;
}
ARC::Void Tortuga::PlayerOnGroundPacket::write ( Tortuga::PacketWriter & packetWriter ) const
{
	packetWriter.writeVariableInt ( Tortuga::Packet::PlayerOnGround ) ;
	packetWriter.writeBool ( this->onGround ) ;
}

Tortuga::PlayerOnGroundPacket::PlayerOnGroundPacket ( Tortuga::PacketReader & packetReader )
{
	this->read ( packetReader ) ;
}
Tortuga::PlayerOnGroundPacket::PlayerOnGroundPacket ( ARC::Bool onGround ) :
	onGround ( onGround )
{
}

ARC::Void Tortuga::PlayerOnGroundPacket::setOnGround ( ARC::Bool onGround )
{
	this->onGround = onGround ;
}
ARC::Bool Tortuga::PlayerOnGroundPacket::getOnGround ( ) const
{
	return this->onGround ;
}
