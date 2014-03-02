#include <Tortuga/Protocol/StatusResponsePacket.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::StatusResponsePacket::read ( Tortuga::PacketReader & packetReader )
{
	this->message = packetReader.readString ( ) ;
}
ARC::Void Tortuga::StatusResponsePacket::write ( Tortuga::PacketWriter & packetWriter ) const
{
	packetWriter.writeVariableInt ( Tortuga::Packet::StatusResponse ) ;
	packetWriter.writeString ( this->message ) ;
}

Tortuga::StatusResponsePacket::StatusResponsePacket ( Tortuga::PacketReader & packetReader )
{
	this->read ( packetReader ) ;
}
Tortuga::StatusResponsePacket::StatusResponsePacket ( const ARC::String & message ) :
	message ( message )
{
}

ARC::Void Tortuga::StatusResponsePacket::setMessage ( const ARC::String & message )
{
	this->message = message ;
}
const ARC::String & Tortuga::StatusResponsePacket::getMessage ( ) const
{
	return this->message ;
}
