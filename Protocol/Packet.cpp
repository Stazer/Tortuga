#include <Tortuga/Protocol/Packet.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::Packet::read ( Tortuga::PacketReader & packetReader )
{
}
ARC::Void Tortuga::Packet::write ( Tortuga::PacketWriter & packetWriter ) const
{
}

Tortuga::Packet::Packet ( )
{
}
Tortuga::Packet::Packet ( Tortuga::PacketReader & reader )
{
	this->read ( reader ) ;
}

Tortuga::Packet::~Packet ( )
{
}

Tortuga::Packet::operator ARC::Buffer ( ) const
{
	Tortuga::PacketWriter packetWriter ;
	
	this->write ( packetWriter ) ;
	
	return packetWriter.write ( ) ;	
}
