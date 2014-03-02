#include <Tortuga/Protocol/PacketReader.hpp>

Tortuga::PacketReader::PacketReader ( ) :
	position ( 0 )
{
}

ARC::Void Tortuga::PacketReader::read ( const ARC::Buffer & buffer )
{
	Tortuga::PacketReader packetReader ;
	packetReader.buffer = buffer ;
	
	const ARC::UnsignedInt packetSize = packetReader.readVariableInt ( ) ;
	
	packetReader.buffer.resize ( packetSize + 1 ) ;
	
	this->buffer = packetReader.buffer ;
	this->position = packetReader.position ;
}

const ARC::Buffer & Tortuga::PacketReader::getBuffer ( ) const
{
	return this->buffer ;
}

ARC::UnsignedLong Tortuga::PacketReader::getPosition ( ) const
{
	return this->position ;
}
ARC::Void Tortuga::PacketReader::setPosition ( const ARC::UnsignedLong position )
{
	if ( this->buffer.size ( ) > position )
		this->position = position ;
	else
		this->position = this->buffer.size ( ) ;
}

ARC::UnsignedChar Tortuga::PacketReader::readChar ( )
{
	if ( this->position < this->buffer.size ( ) )
		return this->buffer [ this->position++ ] ;
		
	return 0 ;
}
ARC::UnsignedShort Tortuga::PacketReader::readShort ( )
{
	return ( ( static_cast <ARC::UnsignedShort> ( this->readChar ( ) ) ) << 8 ) |
	       ( ( static_cast <ARC::UnsignedShort> ( this->readChar ( ) ) ) ) ;
}
ARC::UnsignedInt Tortuga::PacketReader::readInt ( )
{
	return ( ( static_cast <ARC::UnsignedInt> ( this->readChar ( ) ) ) << 24 ) |
	       ( ( static_cast <ARC::UnsignedInt> ( this->readChar ( ) ) ) << 16 ) |
	       ( ( static_cast <ARC::UnsignedInt> ( this->readChar ( ) ) ) << 8 ) |
	       ( ( static_cast <ARC::UnsignedInt> ( this->readChar ( ) ) ) ) ;
}
ARC::UnsignedLong Tortuga::PacketReader::readLong ( )
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
ARC::UnsignedInt Tortuga::PacketReader::readVariableInt ( )
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
ARC::Float Tortuga::PacketReader::readFloat ( )
{
	ARC::UnsignedInt value = this->readInt ( ) ;
	
	return * ( reinterpret_cast <ARC::Float *> ( & value ) ) ;
}
ARC::Double Tortuga::PacketReader::readDouble ( )
{
	ARC::UnsignedLong value = this->readLong ( ) ;
	
	return * ( reinterpret_cast <ARC::Double *> ( & value ) ) ;
}
ARC::String Tortuga::PacketReader::readString ( )
{
	ARC::SignedInt length = this->readVariableInt ( ) ;
	
	ARC::String value = "" ;
	
	for ( ARC::SignedInt element = 0 ; element < length ; ++element )
	{
		value.push_back ( this->readChar ( ) ) ;
	}
	
	return value ;
}
ARC::Bool Tortuga::PacketReader::readBool ( )
{
	return this->readChar ( ) == false ;
}
