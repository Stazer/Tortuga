#include <Tortuga/Protocol/HandshakePacket.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::HandshakePacket::read ( Tortuga::PacketReader & packetReader )
{
	this->protocol = packetReader.readVariableInt ( ) ;
	this->serverAddress = packetReader.readString ( ) ;
	this->serverPort = packetReader.readShort ( ) ;
	this->state = packetReader.readVariableInt ( ) ;
}
ARC::Void Tortuga::HandshakePacket::write ( Tortuga::PacketWriter & packetWriter ) const
{
	packetWriter.writeVariableInt ( Tortuga::Packet::Handshake ) ;
	packetWriter.writeVariableInt ( this->protocol ) ;
	packetWriter.writeString ( this->serverAddress ) ;
	packetWriter.writeShort ( this->serverPort ) ;
	packetWriter.writeVariableInt ( this->state ) ;
}

Tortuga::HandshakePacket::HandshakePacket ( Tortuga::PacketReader & packetReader )
{
	this->read ( packetReader ) ;
}
Tortuga::HandshakePacket::HandshakePacket ( const ARC::UnsignedInt protocol , const ARC::String & serverAddress , const ARC::UnsignedShort serverPort , const ARC::UnsignedInt state ) :
	protocol ( protocol ) ,
	serverAddress ( serverAddress ) ,
	serverPort ( serverPort ) ,
	state ( state )
{
}

ARC::Void Tortuga::HandshakePacket::setProtocol ( const ARC::UnsignedInt protocol )
{
	this->protocol = protocol ;
}
ARC::UnsignedInt Tortuga::HandshakePacket::getProtocol ( ) const
{
	return this->protocol ;
}
	
ARC::Void Tortuga::HandshakePacket::setServerAddress ( const ARC::String & serverAddress )
{
	this->serverAddress = serverAddress ;
}
const ARC::String & Tortuga::HandshakePacket::getServerAddress ( ) const
{
	return this->serverAddress ;
}
			
ARC::Void Tortuga::HandshakePacket::setServerPort ( const ARC::UnsignedShort serverPort )
{
	this->serverPort = serverPort ;
}
ARC::UnsignedShort Tortuga::HandshakePacket::getServerPort ( ) const
{
	return this->serverPort ;
}
			
ARC::Void Tortuga::HandshakePacket::setState ( const ARC::UnsignedInt state )
{
	this->state = state ;
}
ARC::UnsignedInt Tortuga::HandshakePacket::getState ( ) const
{
	return this->state ;
}
