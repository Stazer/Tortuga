#include "Status.hpp"
#include "Packet.hpp"

Tortuga::Status::Status ( const ARC::String & version , const ARC::UnsignedShort protocol , const ARC::UnsignedShort maximalPlayers , const ARC::UnsignedShort onlinePlayers , const ARC::String & text ) :
	version ( version ) ,
	protocol ( protocol ) ,
	maximalPlayers ( maximalPlayers ) ,
	onlinePlayers ( onlinePlayers ) ,
	text ( text )
{
}

Tortuga::Status::operator ARC::Buffer ( )
{
	return Tortuga::Packet::writeStatusResponsePacket ( { "{\"version\": {\"name\": \"" + this->version + "\",\"protocol\": " + ARC::toString <ARC::UnsignedShort> ( this->protocol ) + "},\"players\": {\"max\": " + ARC::toString <ARC::UnsignedShort> ( this->maximalPlayers ) + ",\"online\": " + ARC::toString <ARC::UnsignedShort> ( this->onlinePlayers ) + "},\"description\": {\"text\":\"" + this->text + "\"}}" } ) ;
}
			
ARC::Void Tortuga::Status::setVersion ( const ARC::String & version )
{
	this->version = version ;
}
const ARC::String & Tortuga::Status::getVersion ( ) const
{
	return this->version ;
}
			
ARC::Void Tortuga::Status::setProtocol ( const ARC::UnsignedShort protocol )
{
	this->protocol = protocol ;
}
const ARC::UnsignedShort Tortuga::Status::getProtocol ( ) const
{
	return this->protocol ;
}
			
ARC::Void Tortuga::Status::setMaximalPlayers ( const ARC::UnsignedShort maximalPlayers )
{
	this->maximalPlayers = maximalPlayers ;
}
const ARC::UnsignedShort Tortuga::Status::getMaximalPlayers ( ) const
{
	return this->maximalPlayers ;
}
			
ARC::Void Tortuga::Status::setOnlinePlayers ( const ARC::UnsignedShort onlinePlayers )
{
	this->onlinePlayers = onlinePlayers ;
}
const ARC::UnsignedShort Tortuga::Status::getOnlinePlayers ( ) const
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
