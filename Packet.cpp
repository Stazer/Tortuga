#include "Packet.hpp"
#include "Client.hpp"

#include <iostream>

Tortuga::Packet::Packet ( const ARC::Vector <ARC::UnsignedChar> & buffer ) :
	buffer ( buffer ) ,
	position ( 0 )
{
}

ARC::Void Tortuga::Packet::sendWith ( Tortuga::Client & client )
{
	client.send ( * this ) ;
}

const ARC::Vector <ARC::UnsignedChar> Tortuga::Packet::getBuffer ( ) const
{
	return this->buffer ;
}

ARC::UnsignedInt Tortuga::Packet::getPosition ( ) const
{
	return this->position ;
}
ARC::Void Tortuga::Packet::setPosition ( const ARC::UnsignedInt position )
{
	if ( this->buffer.size ( ) > position )
		this->position = position ;
}

ARC::Void Tortuga::Packet::writeChar ( const ARC::UnsignedChar value )
{
	this->buffer.push_back ( value ) ;
}
ARC::Void Tortuga::Packet::writeShort ( const ARC::UnsignedShort value )
{
	this->buffer.push_back ( ( value >> 8 ) & 0xFF ) ;
	this->buffer.push_back ( ( value ) & 0xFF ) ;
}
ARC::Void Tortuga::Packet::writeInt ( const ARC::UnsignedInt value )
{
	this->buffer.push_back ( ( value >> 24 ) & 0xFF ) ;
	this->buffer.push_back ( ( value >> 16 ) & 0xFF ) ;
	this->buffer.push_back ( ( value >> 8 ) & 0xFF ) ;
	this->buffer.push_back ( ( value ) & 0xFF ) ;
}
ARC::Void Tortuga::Packet::writeLong ( const ARC::UnsignedLong value )
{	
	this->buffer.push_back ( ( value >> 56 ) & 0xFF ) ;
	this->buffer.push_back ( ( value >> 48 ) & 0xFF ) ;
	this->buffer.push_back ( ( value >> 40 ) & 0xFF ) ;
	this->buffer.push_back ( ( value >> 32 ) & 0xFF ) ;
	this->buffer.push_back ( ( value >> 24 ) & 0xFF ) ;
	this->buffer.push_back ( ( value >> 16 ) & 0xFF ) ;
	this->buffer.push_back ( ( value >> 8 ) & 0xFF ) ;
	this->buffer.push_back ( ( value ) & 0xFF ) ;
}
ARC::Void Tortuga::Packet::writeVariableInt ( ARC::UnsignedInt value )
{
	if ( value == 0 )
		this->writeChar ( 0 ) ;
		
	ARC::SignedInt element = 0 ;
	
	for ( ; value ; ++element )
	{
		ARC::UnsignedChar newElement = value & 0x7F ;
		value >>= 7 ;
		
		if ( value )
			newElement |= 0x80 ;
			
		this->buffer.push_back ( newElement ) ;
	}
}
ARC::Void Tortuga::Packet::writeFloat ( const ARC::Float value )
{
	this->writeInt ( * ( reinterpret_cast <const ARC::UnsignedInt *> ( & value ) ) ) ;
}
ARC::Void Tortuga::Packet::writeDouble ( const ARC::Double value )
{
	this->writeLong ( * ( reinterpret_cast <const ARC::UnsignedLong *> ( & value ) ) ) ;
}
ARC::Void Tortuga::Packet::writeString ( const ARC::String & value )
{
	this->writeVariableInt ( value.size ( ) ) ;
	
	for ( auto iterator = value.begin ( ) ; iterator != value.end ( ) ; ++iterator )
	{
		this->writeChar ( * iterator ) ;
	}
}
ARC::Void Tortuga::Packet::writeBool ( const ARC::Bool value )
{
	this->writeChar ( value ? 1 : 0 ) ;
}

ARC::UnsignedChar Tortuga::Packet::readChar ( )
{
	if ( this->position < this->buffer.size ( ) )
		return this->buffer [ this->position++ ] ;
		
	return 0 ;
}
ARC::UnsignedShort Tortuga::Packet::readShort ( )
{
	return ( ( static_cast <ARC::UnsignedShort> ( this->readChar ( ) ) ) << 8 ) |
	       ( ( static_cast <ARC::UnsignedShort> ( this->readChar ( ) ) ) ) ;
}
ARC::UnsignedInt Tortuga::Packet::readInt ( )
{
	return ( ( static_cast <ARC::UnsignedInt> ( this->readChar ( ) ) ) << 24 ) |
	       ( ( static_cast <ARC::UnsignedInt> ( this->readChar ( ) ) ) << 16 ) |
	       ( ( static_cast <ARC::UnsignedInt> ( this->readChar ( ) ) ) << 8 ) |
	       ( ( static_cast <ARC::UnsignedInt> ( this->readChar ( ) ) ) ) ;
}
ARC::UnsignedLong Tortuga::Packet::readLong ( )
{
	return ( ( static_cast <ARC::UnsignedLong> ( this->readChar ( ) ) ) << 56 ) |
	       ( ( static_cast <ARC::UnsignedLong> ( this->readChar ( ) ) ) << 48 ) |
	       ( ( static_cast <ARC::UnsignedLong> ( this->readChar ( ) ) ) << 40 ) |
	       ( ( static_cast <ARC::UnsignedLong> ( this->readChar ( ) ) ) << 32 ) |
	       ( ( static_cast <ARC::UnsignedLong> ( this->readChar ( ) ) ) << 24 ) |
	       ( ( static_cast <ARC::UnsignedLong> ( this->readChar ( ) ) ) << 16 ) |
	       ( ( static_cast <ARC::UnsignedLong> ( this->readChar ( ) ) ) << 8 ) |
	       ( ( static_cast <ARC::UnsignedLong> ( this->readChar ( ) ) ) ) ;
}
ARC::UnsignedInt Tortuga::Packet::readVariableInt ( )
{
	ARC::UnsignedChar data [ 4 ] ;
	ARC::UnsignedInt bufferSize = 0 ;
	
	do
	{
		if ( bufferSize == 4 )
			return -1 ;
			
		data [ bufferSize++ ] = this->readChar ( ) ;
	} while ( data [ bufferSize - 1 ] & 0x80 ) ;
	
	ARC::UnsignedInt value = 0 ;
	
	for ( ARC::SignedInt element = bufferSize - 1 ; element >= 0 ; --element )
	{
		value <<= 7 ;
		value |= ( data [ element ] & 0x7F ) ;
	}
	
	return value ;
}
ARC::Float Tortuga::Packet::readFloat ( )
{
	ARC::UnsignedInt value = this->readInt ( ) ;
	
	return * ( reinterpret_cast <ARC::Float *> ( & value ) ) ;
}
ARC::Double Tortuga::Packet::readDouble ( )
{
	ARC::UnsignedLong value = this->readLong ( ) ;
	
	return * ( reinterpret_cast <ARC::Double *> ( & value ) ) ;
}
ARC::String Tortuga::Packet::readString ( )
{
	ARC::SignedInt length = this->readVariableInt ( ) ;
	
	ARC::String value = "" ;
	
	for ( ARC::SignedInt element = 0 ; element < length ; ++element )
	{
		value.push_back ( this->readChar ( ) ) ;
	}
	
	return value ;
}
ARC::Bool Tortuga::Packet::readBool ( )
{
	return this->readChar ( ) == false ;
}

Tortuga::Packet Tortuga::Packet::encode ( const Tortuga::Packet & packet )
{
	return Tortuga::Packet::encode ( packet.getBuffer ( ) ) ;
}
Tortuga::Packet Tortuga::Packet::encode ( const ARC::Vector <ARC::UnsignedChar> & buffer )
{
	Tortuga::Packet newPacket ;
	
	newPacket.writeVariableInt ( buffer.size ( ) ) ;
	
	newPacket.buffer.insert ( newPacket.buffer.end ( ) , buffer.begin ( ) , buffer.end ( ) ) ;
	
	return newPacket ;
}

Tortuga::Packet Tortuga::Packet::decode ( Tortuga::Packet packet )
{
	const ARC::UnsignedInt packetSize = packet.readVariableInt ( ) ;
	
	if ( packetSize > 0 )
	{
		packet.buffer.resize ( packetSize + 1 ) ;
	}
	else
		packet.buffer.clear ( ) ;
	
	return packet ;
}
Tortuga::Packet Tortuga::Packet::decode ( const ARC::Vector <ARC::UnsignedChar> & buffer )
{
	return Tortuga::Packet::decode ( Tortuga::Packet ( buffer ) ) ;
}
