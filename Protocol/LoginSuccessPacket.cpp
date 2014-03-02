#include <Tortuga/Protocol/LoginSuccessPacket.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::LoginSuccessPacket::read ( Tortuga::PacketReader & packetReader )
{
	this->uuid = packetReader.readVariableInt ( ) ;
	this->name = packetReader.readVariableInt ( ) ;
}
ARC::Void Tortuga::LoginSuccessPacket::write ( Tortuga::PacketWriter & packetWriter ) const
{
	packetWriter.writeVariableInt ( Tortuga::Packet::LoginSuccess ) ;
	packetWriter.writeString ( this->uuid ) ;
	packetWriter.writeString ( this->name ) ;
}

Tortuga::LoginSuccessPacket::LoginSuccessPacket ( Tortuga::PacketReader & packetReader )
{
	this->read ( packetReader ) ;
}
Tortuga::LoginSuccessPacket::LoginSuccessPacket ( const ARC::String & uuid , const ARC::String & name ) :
	uuid ( uuid ) ,
	name ( name )
{
}
	
ARC::Void Tortuga::LoginSuccessPacket::setName ( const ARC::String & name )
{
	this->name = name ;
}
const ARC::String & Tortuga::LoginSuccessPacket::getName ( ) const
{
	return this->name ;
}
