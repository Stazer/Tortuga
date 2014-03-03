#include <Tortuga/Protocol/ChatMessageToServerPacket.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::ChatMessageToServerPacket::read ( Tortuga::PacketReader & packetReader )
{
	this->message = packetReader.readString ( ) ;
}
ARC::Void Tortuga::ChatMessageToServerPacket::write ( Tortuga::PacketWriter & packetWriter ) const
{
	packetWriter.writeVariableInt ( Tortuga::Packet::ChatMessageToServer ) ;
	packetWriter.writeString ( this->message ) ;
}

Tortuga::ChatMessageToServerPacket::ChatMessageToServerPacket ( Tortuga::PacketReader & packetReader )
{
	this->read ( packetReader ) ;
}
Tortuga::ChatMessageToServerPacket::ChatMessageToServerPacket ( const ARC::String & message ) :
	message ( message )
{
}

ARC::Void Tortuga::ChatMessageToServerPacket::setMessage ( const ARC::String & message )
{
	this->message = message ;
}
const ARC::String & Tortuga::ChatMessageToServerPacket::getMessage ( ) const
{
	return this->message ;
}
