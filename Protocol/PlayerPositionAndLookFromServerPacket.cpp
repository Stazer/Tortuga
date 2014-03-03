#include <Tortuga/Protocol/PlayerPositionAndLookFromServerPacket.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::PlayerPositionAndLookFromServerPacket::read ( Tortuga::PacketReader & packetReader )
{
	this->location.getPosition ( ).setX ( packetReader.readDouble ( ) ) ;
	this->location.getPosition ( ).setY ( packetReader.readDouble ( ) ) ;
	this->location.getPosition ( ).setZ ( packetReader.readDouble ( ) ) ;
	this->location.getOrientation ( ).setX ( packetReader.readFloat ( ) ) ;
	this->location.getOrientation ( ).setY ( packetReader.readFloat ( ) ) ;
	this->onGround = packetReader.readBool ( ) ;
}
ARC::Void Tortuga::PlayerPositionAndLookFromServerPacket::write ( Tortuga::PacketWriter & packetWriter ) const
{
	packetWriter.writeVariableInt ( Tortuga::Packet::PlayerPositionAndLookFromServer ) ;
	packetWriter.writeDouble ( this->location.getPosition ( ).getX ( ) ) ;
	packetWriter.writeDouble ( this->location.getPosition ( ).getY ( ) ) ;
	packetWriter.writeDouble ( this->location.getPosition ( ).getZ ( ) ) ;
	packetWriter.writeFloat ( this->location.getOrientation ( ).getX ( ) ) ;
	packetWriter.writeFloat ( this->location.getOrientation ( ).getY ( ) ) ;
	packetWriter.writeBool ( this->onGround ) ;
}

Tortuga::PlayerPositionAndLookFromServerPacket::PlayerPositionAndLookFromServerPacket ( Tortuga::PacketReader & packetReader )
{
	this->read ( packetReader ) ;
}
Tortuga::PlayerPositionAndLookFromServerPacket::PlayerPositionAndLookFromServerPacket ( const Tortuga::Location & location , const ARC::Bool onGround ) :
	location ( location ) ,
	onGround ( onGround )
{
}

ARC::Void Tortuga::PlayerPositionAndLookFromServerPacket::setLocation ( const Tortuga::Location & location )
{
	this->location = location ;
}
Tortuga::Location & Tortuga::PlayerPositionAndLookFromServerPacket::getLocation ( )
{
	return this->location ;
}
const Tortuga::Location & Tortuga::PlayerPositionAndLookFromServerPacket::getLocation ( ) const
{
	return this->location ;
}
			
ARC::Void Tortuga::PlayerPositionAndLookFromServerPacket::setOnGround ( const ARC::Bool onGround )
{
	this->onGround = onGround ;
}
ARC::Bool Tortuga::PlayerPositionAndLookFromServerPacket::getOnGround ( ) const
{
	return this->onGround ;
}
