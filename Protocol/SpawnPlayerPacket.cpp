#include <Tortuga/Protocol/SpawnPlayerPacket.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::SpawnPlayerPacket::read ( Tortuga::PacketReader & packetReader )
{
    this->entityIdentification = packetReader.readVariableInt ( ) ;
    this->uuid = packetReader.readString ( ) ;
    this->name = packetReader.readString ( ) ;
    this->location.getPosition ( ).setX ( packetReader.readDouble ( ) ) ;
    this->location.getPosition ( ).setY ( packetReader.readDouble ( ) ) ;
    this->location.getPosition ( ).setZ ( packetReader.readDouble ( ) ) ;
    this->location.getOrientation ( ).setX ( packetReader.readFloat ( ) ) ;
    this->location.getOrientation ( ).setY ( packetReader.readFloat ( ) ) ;
    this->item = packetReader.readShort ( ) ;
    this->entityMetadata.read ( packetReader ) ;
}
ARC::Void Tortuga::SpawnPlayerPacket::write ( Tortuga::PacketWriter & packetWriter ) const
{
	packetWriter.writeVariableInt ( Tortuga::Packet::SpawnPlayer ) ;
	packetWriter.writeVariableInt ( this->entityIdentification ) ;
	packetWriter.writeString ( this->uuid ) ;
	packetWriter.writeString ( this->name ) ;
	packetWriter.writeInt ( this->location.getPosition ( ).getX ( ) * 32 ) ;
	packetWriter.writeInt ( this->location.getPosition ( ).getY ( ) * 32 ) ;
	packetWriter.writeInt ( this->location.getPosition ( ).getZ ( ) * 32 ) ;
	packetWriter.writeChar ( static_cast <ARC::UnsignedChar> ( std::fmod ( std::floor ( this->location.getOrientation ( ).getX ( ) ) , 360 ) / 360 * 256 ) ) ;
	packetWriter.writeChar ( static_cast <ARC::UnsignedChar> ( std::fmod ( std::floor ( this->location.getOrientation ( ).getY ( ) ) , 360 ) / 360 * 256 ) ) ;
	packetWriter.writeShort ( this->item ) ;
	this->entityMetadata.write ( packetWriter ) ;
}

Tortuga::SpawnPlayerPacket::SpawnPlayerPacket ( Tortuga::PacketReader & packetReader )
{
	this->read ( packetReader ) ;
}
Tortuga::SpawnPlayerPacket::SpawnPlayerPacket ( ARC::UnsignedInt entityIdentification , const ARC::String & uuid , const ARC::String & name , const Tortuga::Location & location , ARC::UnsignedShort item , const Tortuga::EntityMetadata & entityMetadata ) :
    entityIdentification ( entityIdentification ) ,
    uuid ( uuid ) ,
    name ( name ) ,
    location ( location ) ,
    item ( item ) ,
    entityMetadata ( entityMetadata )
{
}

ARC::Void Tortuga::SpawnPlayerPacket::setEntityIdentification ( ARC::UnsignedInt entityIdentification )
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

ARC::Void Tortuga::SpawnPlayerPacket::setItem ( ARC::UnsignedShort item )
{
    this->item = item ;
}
ARC::UnsignedShort Tortuga::SpawnPlayerPacket::getItem ( ) const
{
    return this->item ;
}

ARC::Void Tortuga::SpawnPlayerPacket::setEntityMetadata ( const Tortuga::EntityMetadata & entityMetadata )
{
    this->entityMetadata = entityMetadata ;
}
Tortuga::EntityMetadata & Tortuga::SpawnPlayerPacket::getEntityMetadata ( )
{
    return this->entityMetadata ;
}
const Tortuga::EntityMetadata & Tortuga::SpawnPlayerPacket::getEntityMetadata ( ) const
{
    return this->entityMetadata ;
}
