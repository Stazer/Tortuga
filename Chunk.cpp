#include "Chunk.hpp"
#include "Packet.hpp"
#include "Client.hpp"
#include "ChatUser.hpp"

Tortuga::Chunk::Chunk ( const ARC::Vector2SignedInt & position ) :
	position ( position )
{
}

ARC::Void Tortuga::Chunk::send ( Tortuga::Client & client )
{
	ARC::Deflator deflator ;
	
	for ( ARC::UnsignedLong element = 0 ; element < sizeof ( this->data ) ; ++element )
		deflator.put ( this->data [ element ] ) ;
	
	for ( ARC::UnsignedLong element = 0 ; element < sizeof ( this->meta ) ; ++element )
		deflator.put ( this->data [ element ] ) ;
		
	for ( ARC::UnsignedLong element = 0 ; element < sizeof ( this->light ) ; ++element )
		deflator.put ( this->data [ element ] ) ;
		
	for ( ARC::UnsignedLong element = 0 ; element < sizeof ( this->skylight ) ; ++element )
		deflator.put ( this->data [ element ] ) ;
	
	for ( ARC::UnsignedLong element = 0 ; element < sizeof ( this->biome ) ; ++element )
		deflator.put ( this->data [ element ] ) ;
	
	for ( ARC::UnsignedLong element = 0 ; element < sizeof ( this->add ) ; ++element )
		deflator.put ( this->data [ element ] ) ;

	deflator.calculate ( ) ;
	
	ARC::SharedPointer <ARC::Buffer> buffer ( new ARC::Buffer ( ) ) ;
	
	for ( ARC::UnsignedLong element = 0 ; element < deflator.getSize ( ) ; ++element )
		buffer->push_back ( deflator.get ( ) ) ;
		
	client.send ( Tortuga::Packet::writeWorldChunkPacket ( { this->position.getX ( ) , this->position.getY ( ) , true , 0xFFFF , 0 , buffer } ) ) ;
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
