#include <Tortuga/Protocol/JoinGamePacket.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::JoinGamePacket::read ( Tortuga::PacketReader & packetReader )
{
	this->entityIdentification = packetReader.readInt ( ) ;
	this->gamemode = packetReader.readChar ( ) ;
	this->dimension = packetReader.readChar ( ) ;
	this->difficulty = packetReader.readChar ( ) ;
	this->maximalPlayers = packetReader.readChar ( ) ;
	this->levelType = packetReader.readString ( ) ;
}
ARC::Void Tortuga::JoinGamePacket::write ( Tortuga::PacketWriter & packetWriter ) const
{
	packetWriter.writeVariableInt ( Tortuga::Packet::JoinGame ) ;
	packetWriter.writeInt ( this->entityIdentification ) ;
	packetWriter.writeChar ( this->gamemode ) ;
	packetWriter.writeChar ( this->dimension ) ;
	packetWriter.writeChar ( this->difficulty ) ;
	packetWriter.writeChar ( this->maximalPlayers ) ;
	packetWriter.writeString ( this->levelType ) ;
}

Tortuga::JoinGamePacket::JoinGamePacket ( Tortuga::PacketReader & packetReader )
{
	this->read ( packetReader ) ;
}
Tortuga::JoinGamePacket::JoinGamePacket ( ARC::UnsignedInt entityIdentification , ARC::UnsignedChar gamemode , ARC::SignedChar dimension , ARC::UnsignedChar difficulty , const ARC::String & levelType ) :
	entityIdentification ( entityIdentification ) ,
	gamemode ( gamemode ) ,
	dimension ( dimension ) ,
	difficulty ( difficulty ) ,
	levelType ( levelType )
{
}

ARC::Void Tortuga::JoinGamePacket::setEntityIdentification ( ARC::UnsignedInt entityIdentification )
{
	this->entityIdentification = entityIdentification ;
}
ARC::UnsignedInt Tortuga::JoinGamePacket::getEntityIdentification ( ) const
{
	return this->entityIdentification ;
}

ARC::Void Tortuga::JoinGamePacket::setGamemode ( ARC::UnsignedChar gamemode )
{
	this->gamemode = gamemode ;
}
ARC::UnsignedChar Tortuga::JoinGamePacket::getGamemode ( ) const
{
	return this->gamemode ;
}

ARC::Void Tortuga::JoinGamePacket::setDimension ( ARC::SignedChar dimension )
{
	this->dimension = dimension ;
}
ARC::SignedChar Tortuga::JoinGamePacket::getDimension ( ) const
{
	return this->dimension ;
}

ARC::Void Tortuga::JoinGamePacket::setDifficulty ( ARC::UnsignedChar difficulty )
{
	this->difficulty = difficulty ;
}
ARC::UnsignedChar Tortuga::JoinGamePacket::getDifficulty ( ) const
{
	return this->difficulty ;
}

ARC::Void Tortuga::JoinGamePacket::setMaximalPlayers ( ARC::UnsignedChar maximalPlayers )
{
	this->maximalPlayers = maximalPlayers ;
}
ARC::UnsignedChar Tortuga::JoinGamePacket::getMaximalPlayers ( ) const
{
	return this->maximalPlayers ;
}

ARC::Void Tortuga::JoinGamePacket::setLevelType ( const ARC::String & levelType )
{
	this->levelType = levelType ;
}
const ARC::String & Tortuga::JoinGamePacket::getLevelType ( ) const
{
	return this->levelType ;
}