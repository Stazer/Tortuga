#include <Tortuga/Protocol/TimeUpdatePacket.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::TimeUpdatePacket::read ( Tortuga::PacketReader & packetReader )
{
	this->age = packetReader.readLong ( ) ;
	this->time = packetReader.readLong ( ) ;
}
ARC::Void Tortuga::TimeUpdatePacket::write ( Tortuga::PacketWriter & packetWriter ) const
{
	packetWriter.writeVariableInt ( Tortuga::Packet::TimeUpdate ) ;
	packetWriter.writeLong ( this->age ) ;
	packetWriter.writeLong ( this->time ) ;
}

Tortuga::TimeUpdatePacket::TimeUpdatePacket ( Tortuga::PacketReader & packetReader )
{
	this->read ( packetReader ) ;
}
Tortuga::TimeUpdatePacket::TimeUpdatePacket ( const ARC::UnsignedLong age , const ARC::UnsignedLong time ) :
	age ( age ) ,
	time ( time )
{
}

ARC::Void Tortuga::TimeUpdatePacket::setAge ( const ARC::UnsignedLong age )
{
	this->age = age ;
}
ARC::UnsignedLong Tortuga::TimeUpdatePacket::getAge ( ) const
{
	return this->age ;
}
			
ARC::Void Tortuga::TimeUpdatePacket::setTime ( const ARC::UnsignedLong time )
{
	this->time = time ;
}
ARC::UnsignedLong Tortuga::TimeUpdatePacket::getTime ( ) const
{
	return this->time ;
}
