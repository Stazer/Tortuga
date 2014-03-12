#include "PacketWriter.hpp"

ARC::Buffer Tortuga::PacketWriter::write ( ) const
{
	Tortuga::PacketWriter packetWriter ;

	packetWriter.writeVariableInt ( this->getBuffer ( ).size ( ) ) ;
	packetWriter.buffer.insert ( packetWriter.buffer.end ( ) , this->getBuffer ( ).begin ( ) , this->getBuffer ( ).end ( ) ) ;

	return packetWriter.getBuffer ( ) ;
}

const ARC::Buffer & Tortuga::PacketWriter::getBuffer ( ) const
{
	return this->buffer ;
}

ARC::Void Tortuga::PacketWriter::writeChar ( ARC::UnsignedChar value )
{
	this->buffer.push_back ( value ) ;
}
ARC::Void Tortuga::PacketWriter::writeShort ( ARC::UnsignedShort value )
{
	this->buffer.push_back ( ( value >> 8 ) & 0xFF ) ;
	this->buffer.push_back ( ( value ) & 0xFF ) ;
}
ARC::Void Tortuga::PacketWriter::writeInt ( ARC::UnsignedInt value )
{
	this->buffer.push_back ( ( value >> 24 ) & 0xFF ) ;
	this->buffer.push_back ( ( value >> 16 ) & 0xFF ) ;
	this->buffer.push_back ( ( value >> 8 ) & 0xFF ) ;
	this->buffer.push_back ( ( value ) & 0xFF ) ;
}
ARC::Void Tortuga::PacketWriter::writeLong ( ARC::UnsignedLong value )
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
ARC::Void Tortuga::PacketWriter::writeVariableInt ( ARC::UnsignedInt value )
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
ARC::Void Tortuga::PacketWriter::writeFloat ( ARC::Float value )
{
	this->writeInt ( * ( reinterpret_cast <const ARC::UnsignedInt *> ( & value ) ) ) ;
}
ARC::Void Tortuga::PacketWriter::writeDouble ( const ARC::Double value )
{
	this->writeLong ( * ( reinterpret_cast <const ARC::UnsignedLong *> ( & value ) ) ) ;
}
ARC::Void Tortuga::PacketWriter::writeString ( const ARC::String & value )
{
	this->writeVariableInt ( value.size ( ) ) ;

	for ( auto iterator = value.begin ( ) ; iterator != value.end ( ) ; ++iterator )
	{
		this->writeChar ( * iterator ) ;
	}
}
ARC::Void Tortuga::PacketWriter::writeBool ( ARC::Bool value )
{
	this->writeChar ( value ? 1 : 0 ) ;
}