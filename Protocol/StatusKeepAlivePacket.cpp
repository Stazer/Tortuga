#include <Tortuga/Protocol/StatusKeepAlivePacket.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::StatusKeepAlivePacket::read ( Tortuga::PacketReader & packetReader )
{
	this->time = packetReader.readLong ( ) ;
}
ARC::Void Tortuga::StatusKeepAlivePacket::write ( Tortuga::PacketWriter & packetWriter ) const
{
	packetWriter.writeVariableInt ( Tortuga::Packet::StatusKeepAlive ) ;
	packetWriter.writeLong ( this->time ) ;
}

Tortuga::StatusKeepAlivePacket::StatusKeepAlivePacket ( Tortuga::PacketReader & packetReader )
{
	this->read ( packetReader ) ;
}
Tortuga::StatusKeepAlivePacket::StatusKeepAlivePacket ( const ARC::UnsignedLong time ) :
	time ( time )
{
}

ARC::Void Tortuga::StatusKeepAlivePacket::setTime ( const ARC::UnsignedLong time )
{
	this->time = time ;
}
ARC::UnsignedLong Tortuga::StatusKeepAlivePacket::getTime ( ) const
{
	return this->time ;
}
