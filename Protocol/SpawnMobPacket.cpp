#include <Tortuga/Protocol/SpawnMobPacket.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::SpawnMobPacket::read ( Tortuga::PacketReader & packetReader )
{
	this->entityMetadata.read ( packetReader ) ;
}
ARC::Void Tortuga::SpawnMobPacket::write ( Tortuga::PacketWriter & packetWriter ) const
{
	packetWriter.writeVariableInt ( Tortuga::Packet::SpawnMob ) ;
	packetWriter.writeVariableInt ( this->entityIdentification ) ;
	packetWriter.writeChar ( this->type ) ;
	packetWriter.writeInt ( this->location.getPosition ( ).getX ( ) * 32 ) ;
	packetWriter.writeInt ( this->location.getPosition ( ).getY ( ) * 32 ) ;
	packetWriter.writeInt ( this->location.getPosition ( ).getZ ( ) * 32 ) ;
	packetWriter.writeChar ( static_cast <ARC::UnsignedChar> ( std::fmod ( std::floor ( this->location.getOrientation ( ).getX ( ) ) , 360 ) / 360 * 256 ) ) ;
	packetWriter.writeChar ( static_cast <ARC::UnsignedChar> ( std::fmod ( std::floor ( this->headPitch ) , 360 ) / 360 * 256 ) ) ;
	packetWriter.writeChar ( static_cast <ARC::UnsignedChar> ( std::fmod ( std::floor ( this->location.getOrientation ( ).getY ( ) ) , 360 ) / 360 * 256 ) ) ;
    packetWriter.writeShort ( this->velocity.getX ( ) ) ;
    packetWriter.writeShort ( this->velocity.getY ( ) ) ;
    packetWriter.writeShort ( this->velocity.getZ ( ) ) ;
	this->entityMetadata.write ( packetWriter ) ;
}

Tortuga::SpawnMobPacket::SpawnMobPacket ( Tortuga::PacketReader & packetReader )
{
	this->read ( packetReader ) ;
}
Tortuga::SpawnMobPacket::SpawnMobPacket ( const ARC::UnsignedInt entityIdentification , const ARC::UnsignedChar type , const Tortuga::Location & location , const ARC::Float headPitch , const ARC::Vector3SignedShort & velocity , const Tortuga::EntityMetadata & entityMetadata ) :
	entityIdentification ( entityIdentification ) ,
	type ( type ) ,
	location ( location ) ,
	headPitch ( headPitch ) ,
	velocity ( velocity ) ,
	entityMetadata ( entityMetadata )
{
}

ARC::Void Tortuga::SpawnMobPacket::setEntityIdentification ( const ARC::UnsignedInt entityIdentification )
{
	this->entityIdentification = entityIdentification ;
}
ARC::UnsignedInt Tortuga::SpawnMobPacket::getEntityIdentification ( ) const
{
	return this->entityIdentification ;
}

ARC::Void Tortuga::SpawnMobPacket::setType ( const ARC::UnsignedChar type )
{
	this->type = type ;
}
ARC::UnsignedChar Tortuga::SpawnMobPacket::getType ( ) const
{
	return this->type ;
}

ARC::Void Tortuga::SpawnMobPacket::setLocation ( const Tortuga::Location & location )
{
	this->location = location ;
}
Tortuga::Location & Tortuga::SpawnMobPacket::getLocation ( )
{
	return this->location ;
}
const Tortuga::Location & Tortuga::SpawnMobPacket::getLocation ( ) const
{
	return this->location ;
}

ARC::Void Tortuga::SpawnMobPacket::setHeadPitch ( const ARC::Float headPitch )
{
	this->headPitch = headPitch ;
}
ARC::Float Tortuga::SpawnMobPacket::getHeadPitch ( ) const
{
	return this->headPitch ;
}

ARC::Void Tortuga::SpawnMobPacket::setVelocity ( const ARC::Vector3SignedShort & velocity )
{
	this->velocity = velocity ;
}
ARC::Vector3SignedShort & Tortuga::SpawnMobPacket::getVelocity ( )
{
	return this->velocity ;
}
const ARC::Vector3SignedShort & Tortuga::SpawnMobPacket::getVelocity ( ) const
{
	return this->velocity ;
}

ARC::Void Tortuga::SpawnMobPacket::setEntityMetadata ( const Tortuga::EntityMetadata & entityMetadata )
{
	this->entityMetadata = entityMetadata ;
}
Tortuga::EntityMetadata & Tortuga::SpawnMobPacket::getEntityMetadata ( )
{
	return this->entityMetadata ;
}
const Tortuga::EntityMetadata & Tortuga::SpawnMobPacket::getEntityMetadata ( ) const
{
	return this->entityMetadata ;
}
