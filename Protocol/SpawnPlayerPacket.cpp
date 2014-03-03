#include <Tortuga/Protocol/SpawnPlayerPacket.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::SpawnPlayerPacket::read ( Tortuga::PacketReader & packetReader )
{
    this->entityIdentification = packetReader.readInt ( ) ;
    this->uuid = packetReader.readString ( ) ;
    this->name = packetReader.readString ( ) ;
    this->location.getPosition ( ).setX ( packetReader.readDouble ( ) ) ;
    this->location.getPosition ( ).setY ( packetReader.readDouble ( ) ) ;
    this->location.getPosition ( ).setZ ( packetReader.readDouble ( ) ) ;
    this->location.getOrientation ( ).setX ( packetReader.readFloat ( ) ) ;
    this->location.getOrientation ( ).setY ( packetReader.readFloat ( ) ) ;
    this->item = packetReader.readShort ( ) ;
    // TODO metadata
}
ARC::Void Tortuga::SpawnPlayerPacket::write ( Tortuga::PacketWriter & packetWriter ) const
{
	packetWriter.writeVariableInt ( Tortuga::Packet::SpawnPlayer ) ;
	packetWriter.writeInt ( this->entityIdentification ) ;
	packetWriter.writeString ( this->uuid ) ;
	packetWriter.writeString ( this->name ) ;
	packetWriter.writeDouble ( this->location.getPosition ( ).getX ( ) ) ;
	packetWriter.writeDouble ( this->location.getPosition ( ).getY ( ) ) ;
	packetWriter.writeDouble ( this->location.getPosition ( ).getZ ( ) ) ;
	packetWriter.writeFloat ( this->location.getOrientation ( ).getX ( ) ) ;
	packetWriter.writeFloat ( this->location.getOrientation ( ).getY ( ) ) ;
	packetWriter.writeShort ( this->item ) ;
	// TODO metadata
}

Tortuga::SpawnPlayerPacket::SpawnPlayerPacket ( Tortuga::PacketReader & packetReader )
{
	this->read ( packetReader ) ;
}
Tortuga::SpawnPlayerPacket::SpawnPlayerPacket ( const ARC::UnsignedInt entityIdentification , const ARC::String & uuid , const ARC::String & name , const Tortuga::Location & location , const ARC::UnsignedShort item ) :
    entityIdentification ( entityIdentification ) ,
    uuid ( uuid ) ,
    name ( name ) ,
    location ( location ) ,
    item ( item )
{
}

ARC::Void Tortuga::SpawnPlayerPacket::setEntityIdentification ( const ARC::UnsignedInt entityIdentification )
{
    this->entityIdentification = entityIdentification ;
}
ARC::UnsignedInt Tortuga::SpawnPlayerPacket::getEntityIdentification ( ) const
{
    return this->entityIdentification ;
}

ARC::Void Tortuga::SpawnPlayerPacket::setUUID ( const ARC::String & uuid )
{
    this->uuid = uuid ;
}
const ARC::String & Tortuga::SpawnPlayerPacket::getUUID ( ) const
{
    return this->uuid ;
}

ARC::Void Tortuga::SpawnPlayerPacket::setName ( const ARC::String & name )
{
    this->name = name ;
}
const ARC::String & Tortuga::SpawnPlayerPacket::getName ( ) const
{
    return this->name ;
}

ARC::Void Tortuga::SpawnPlayerPacket::setLocation ( const Tortuga::Location & location )
{
    this->location = location ;
}
Tortuga::Location & Tortuga::SpawnPlayerPacket::getLocation ( )
{
    return this->location ;
}
const Tortuga::Location & Tortuga::SpawnPlayerPacket::getLocation ( ) const
{
    return this->location ;
}

ARC::Void Tortuga::SpawnPlayerPacket::setItem ( const ARC::UnsignedShort item )
{
    this->item = item ;
}
const ARC::UnsignedShort Tortuga::SpawnPlayerPacket::getItem ( ) const
{
    return this->item ;
}
