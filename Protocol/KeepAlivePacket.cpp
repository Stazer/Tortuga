#include <Tortuga/Protocol/KeepAlivePacket.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::KeepAlivePacket::read ( Tortuga::PacketReader & packetReader )
{
	this->identification = packetReader.readInt ( ) ;
}
ARC::Void Tortuga::KeepAlivePacket::write ( Tortuga::PacketWriter & packetWriter ) const
{
	packetWriter.writeVariableInt ( Tortuga::Packet::KeepAlive ) ;
	packetWriter.writeInt ( this->identification ) ;
}

Tortuga::KeepAlivePacket::KeepAlivePacket ( Tortuga::PacketReader & packetReader )
{
	this->read ( packetReader ) ;
}
Tortuga::KeepAlivePacket::KeepAlivePacket ( const ARC::UnsignedInt identification ) :
	identification ( identification )
{
}

ARC::Void Tortuga::KeepAlivePacket::setIdentification ( const ARC::UnsignedInt identification )
{
	this->identification = identification ;
}
ARC::UnsignedInt Tortuga::KeepAlivePacket::getIdentification ( ) const
{
	return this->identification ;
}
