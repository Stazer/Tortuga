#include "Chunk.hpp"
#include "Packet.hpp"
#include "Client.hpp"

ARC::Void Tortuga::Chunk::send ( Tortuga::Client & client )
{	
	ARC::Deflator deflator ;
	
	for ( ARC::UnsignedLong element = 0 ; element < Tortuga::Chunk::size ; ++element )
		deflator.put ( this->data [ element ] ) ;
		
	deflator.calculate ( ) ;
		
	ARC::SharedPointer <ARC::Buffer> buffer ( new ARC::Buffer ( ) ) ;
	
	for ( ARC::UnsignedLong element = 0 ; element < deflator.getSize ( ) ; ++element )
		buffer->push_back ( deflator.get ( ) ) ;
	
	client.send ( Tortuga::Packet::writeWorldChunkPacket ( { this->position.getX ( ) , this->position.getY ( ) , true , 0b1 , 0b1 , buffer } ) ) ;
}

ARC::Void Tortuga::Chunk::setPosition ( const Tortuga::Position2 & position )
{
	this->position = position ;
}
Tortuga::Position2 & Tortuga::Chunk::getPosition ( )
{
	return this->position ;
}
const Tortuga::Position2 & Tortuga::Chunk::getPosition ( ) const
{
	return this->position ;
}
