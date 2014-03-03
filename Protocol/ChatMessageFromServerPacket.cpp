#include <Tortuga/Protocol/ChatMessageFromServerPacket.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::ChatMessageFromServerPacket::read ( Tortuga::PacketReader & packetReader )
{
	this->message = packetReader.readString ( ) ;
}
ARC::Void Tortuga::ChatMessageFromServerPacket::write ( Tortuga::PacketWriter & packetWriter ) const
{
	packetWriter.writeVariableInt ( Tortuga::Packet::ChatMessageFromServer ) ;
	packetWriter.writeString ( this->message ) ;
}

Tortuga::ChatMessageFromServerPacket::ChatMessageFromServerPacket ( Tortuga::PacketReader & packetReader )
{
	this->read ( packetReader ) ;
}
Tortuga::ChatMessageFromServerPacket::ChatMessageFromServerPacket ( const ARC::String & message ) :
	message ( message )
{
}

ARC::Void Tortuga::ChatMessageFromServerPacket::setMessage ( const ARC::String & message )
{
	this->message = message ;
}
const ARC::String & Tortuga::ChatMessageFromServerPacket::getMessage ( ) const
{
	return this->message ;
}
