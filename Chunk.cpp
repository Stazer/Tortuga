#include "Chunk.hpp"
#include "Packet.hpp"
#include "Client.hpp"

Tortuga::Chunk::Chunk ( const Tortuga::Position2SignedInt & position ) :
	position ( position )
{
}

ARC::Void Tortuga::Chunk::send ( Tortuga::Client & client )
{
	ARC::UnsignedChar data [ 16 * 16 ] ;
	
	ARC::Deflator deflator ;
	
	for ( ARC::UnsignedLong element = 0 ; element < 16 * 16 ; ++element )
		deflator.put ( this->data [ element ] ) ;
		
	deflator.calculate ( ) ;
		
	ARC::SharedPointer <ARC::Buffer> buffer ( new ARC::Buffer ( ) ) ;
	
	for ( ARC::UnsignedLong element = 0 ; element < deflator.getSize ( ) ; ++element )
		buffer->push_back ( deflator.get ( ) ) ;

	/*ARC::Deflator deflator ;
	
	for ( ARC::UnsignedLong element = 0 ; element < Tortuga::Chunk::size ; ++element )
		deflator.put ( this->data [ element ] ) ;
		
	deflator.calculate ( ) ;
		
	ARC::SharedPointer <ARC::Buffer> buffer ( new ARC::Buffer ( ) ) ;
	
	for ( ARC::UnsignedLong element = 0 ; element < deflator.getSize ( ) ; ++element )
		buffer->push_back ( deflator.get ( ) ) ;*/
	
	client.send ( Tortuga::Packet::writeWorldChunkPacket ( { this->position.getX ( ) , this->position.getY ( ) , true , 0b1 , 0b1 , buffer } ) ) ;
}

ARC::Void Tortuga::Chunk::setPosition ( const Tortuga::Position2SignedInt & position )
{
	this->position = position ;
}
Tortuga::Position2SignedInt & Tortuga::Chunk::getPosition ( )
{
	return this->position ;
}
const Tortuga::Position2SignedInt & Tortuga::Chunk::getPosition ( ) const
{
	return this->position ;
}
