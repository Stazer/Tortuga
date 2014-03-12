#include <Tortuga/Status/Status.hpp>
#include <Tortuga/Protocol/StatusResponsePacket.hpp>

Tortuga::Status::Status ( const ARC::String & version , ARC::UnsignedShort protocol , ARC::UnsignedShort maximalPlayers , ARC::UnsignedShort onlinePlayers , const ARC::String & text ) :
	version ( version ) ,
	protocol ( protocol ) ,
	maximalPlayers ( maximalPlayers ) ,
	onlinePlayers ( onlinePlayers ) ,
	text ( text )
{
}

Tortuga::Status::operator ARC::Buffer ( )
{
	return Tortuga::StatusResponsePacket ( "{\"version\": {\"name\": \"" + this->version + "\",\"protocol\": " + ARC::toString <ARC::UnsignedShort> ( this->protocol ) + "},\"players\": {\"max\": " + ARC::toString <ARC::UnsignedShort> ( this->maximalPlayers ) + ",\"online\": " + ARC::toString <ARC::UnsignedShort> ( this->onlinePlayers ) + "},\"description\": {\"text\":\"" + this->text + "\"}}" ) ;
}

ARC::Void Tortuga::Status::setVersion ( const ARC::String & version )
{
	this->version = version ;
}
const ARC::String & Tortuga::Status::getVersion ( ) const
{
	return this->version ;
}

ARC::Void Tortuga::Status::setProtocol ( ARC::UnsignedShort protocol )
{
	this->protocol = protocol ;
}
ARC::UnsignedShort Tortuga::Status::getProtocol ( ) const
{
	return this->protocol ;
}

ARC::Void Tortuga::Status::setMaximalPlayers ( ARC::UnsignedShort maximalPlayers )
{
	this->maximalPlayers = maximalPlayers ;
}
ARC::UnsignedShort Tortuga::Status::getMaximalPlayers ( ) const
{
	return this->maximalPlayers ;
}

ARC::Void Tortuga::Status::setOnlinePlayers ( ARC::UnsignedShort onlinePlayers )
{
	this->onlinePlayers = onlinePlayers ;
}
ARC::UnsignedShort Tortuga::Status::getOnlinePlayers ( ) const
{
	return this->onlinePlayers ;
}

ARC::Void Tortuga::Status::setText ( const ARC::String & text )
{
	this->text = text ;
}
const ARC::String & Tortuga::Status::getText ( ) const
{
	return this->text ;
}