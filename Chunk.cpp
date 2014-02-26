#include "Chunk.hpp"
#include "Packet.hpp"
#include "Client.hpp"
#include "Block.hpp"
#include "ChatUser.hpp"

Tortuga::Chunk::Chunk ( const ARC::Vector2SignedInt & position ) :
	position ( position )
{
}

ARC::Void Tortuga::Chunk::send ( Tortuga::Client & client )
{
	ARC::Deflator deflator ;
	
	for ( ARC::UnsignedLong element = 0 ; element < sizeof ( this->type ) ; ++element )
		deflator.put ( this->type [ element ] ) ;
	
	for ( ARC::UnsignedLong element = 0 ; element < sizeof ( this->metadata ) ; ++element )
		deflator.put ( this->metadata [ element ] ) ;
		
	for ( ARC::UnsignedLong element = 0 ; element < sizeof ( this->light ) ; ++element )
		deflator.put ( this->light [ element ] ) ;
		
	for ( ARC::UnsignedLong element = 0 ; element < sizeof ( this->skylight ) ; ++element )
		deflator.put ( this->skylight [ element ] ) ;
	
	for ( ARC::UnsignedLong element = 0 ; element < sizeof ( this->biome ) ; ++element )
		deflator.put ( this->biome [ element ] ) ;
	
	for ( ARC::UnsignedLong element = 0 ; element < sizeof ( this->add ) ; ++element )
		deflator.put ( this->add [ element ] ) ;

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

Tortuga::Chunk Tortuga::Chunk::getTestChunk ( Tortuga::Chunk chunk , const ARC::UnsignedLong steps )
{
	for ( ARC::UnsignedLong element = 0 ; element < Tortuga::Chunk::Size / 4 ; element += steps )
	{
		chunk.type [ element ] = Tortuga::Block::Stone ;
	}
	
	return chunk ;
}
