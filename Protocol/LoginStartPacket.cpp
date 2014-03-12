#include <Tortuga/Protocol/LoginStartPacket.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::LoginStartPacket::read ( Tortuga::PacketReader & packetReader )
{
	this->name = packetReader.readString ( ) ;
}
ARC::Void Tortuga::LoginStartPacket::write ( Tortuga::PacketWriter & packetWriter ) const
{
	packetWriter.writeVariableInt ( Tortuga::Packet::LoginStart ) ;
	packetWriter.writeString ( this->name ) ;
}

Tortuga::LoginStartPacket::LoginStartPacket ( Tortuga::PacketReader & packetReader )
{
	this->read ( packetReader ) ;
}
Tortuga::LoginStartPacket::LoginStartPacket ( const ARC::String & name ) :
	name ( name )
{
}

ARC::Void Tortuga::LoginStartPacket::setName ( const ARC::String & name )
{
	this->name = name ;
}
const ARC::String & Tortuga::LoginStartPacket::getName ( ) const
{
	return this->name ;
}