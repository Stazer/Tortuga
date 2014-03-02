#include <Tortuga/Protocol/StatusRequestPacket.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::StatusRequestPacket::read ( Tortuga::PacketReader & packetReader )
{
}
ARC::Void Tortuga::StatusRequestPacket::write ( Tortuga::PacketWriter & packetWriter ) const
{
	packetWriter.writeVariableInt ( Tortuga::Packet::StatusRequest ) ;
}

Tortuga::StatusRequestPacket::StatusRequestPacket ( Tortuga::PacketReader & packetReader )
{
	this->read ( packetReader ) ;
}
Tortuga::StatusRequestPacket::StatusRequestPacket ( )
{
}
