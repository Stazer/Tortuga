#include <Tortuga/Protocol/ExamplePacket.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::ExamplePacket::read ( Tortuga::PacketReader & packetReader )
{
}
ARC::Void Tortuga::ExamplePacket::write ( Tortuga::PacketWriter & packetWriter ) const
{
	packetWriter.writeVariableInt ( Tortuga::Packet::Example ) ;
}

Tortuga::ExamplePacket::ExamplePacket ( Tortuga::PacketReader & packetReader )
{
	this->read ( packetReader ) ;
}
Tortuga::ExamplePacket::ExamplePacket ( )
{
}
