#include "Chunk.hpp"
#include "Packet.hpp"
#include "Client.hpp"

Tortuga::Chunk::Chunk ( const ARC::Vector2SignedInt & position ) :
	position ( position )
{
}

#include <iostream>

ARC::Void Tortuga::Chunk::send ( Tortuga::Client & client )
{
	ARC::UnsignedChar blockData [ 16 * 16 * 3 ] ;
	
	for ( ARC::UnsignedLong element = 0 ; element < ( 16 * 16 * 3 ) ; ++element )
		blockData [ element ] = 5 ; // Wood
	
	ARC::Deflator deflator ;
	
	for ( ARC::UnsignedLong element = 0 ; element < ( 16 * 16 * 3 ) ; ++element )
		deflator.put ( blockData [ element ] ) ;
		
	deflator.calculate ( ) ;
		
	ARC::SharedPointer <ARC::Buffer> buffer ( new ARC::Buffer ( ) ) ;
	
	for ( ARC::UnsignedLong element = 0 ; element < deflator.getSize ( ) ; ++element )
		buffer->push_back ( deflator.get ( ) ) ;
		
	client.send ( Tortuga::Packet::writeWorldChunkPacket ( { 0 , 0 , true , 0b11111 , 0 , buffer } ) ) ;

	/*ARC::Deflator deflator ;
	
	for ( ARC::UnsignedLong element = 0 ; element < Tortuga::Chunk::size ; ++element )
		deflator.put ( this->data [ element ] ) ;
		
	deflator.calculate ( ) ;
		
	ARC::SharedPointer <ARC::Buffer> buffer ( new ARC::Buffer ( ) ) ;
	
	for ( ARC::UnsignedLong element = 0 ; element < deflator.getSize ( ) ; ++element )
		buffer->push_back ( deflator.get ( ) ) ;*/
	
	//client.send ( Tortuga::Packet::writeWorldChunkPacket ( { this->position.getX ( ) , this->position.getY ( ) , true , 0b1 , 0b1 , buffer } ) ) ;
}

ARC::Void Tortuga::Chunk::setPosition ( const ARC::Vector2SignedInt & position )
{
	this->position = position ;
}
ARC::Vector2SignedInt & Tortuga::Chunk::getPosition ( )
{
	return this->position ;
}
const ARC::Vector2SignedInt & Tortuga::Chunk::getPosition ( ) const
{
	return this->position ;
}
