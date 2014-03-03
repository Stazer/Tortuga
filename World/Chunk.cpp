#include <Tortuga/World/Chunk.hpp>
#include <Tortuga/Protocol/WorldChunkPacket.hpp>

ARC::UnsignedLong Tortuga::Chunk::getArrayPosition ( const ARC::Vector3SignedInt & position ) const
{
	const ARC::UnsignedLong arrayPosition = ( position.getY ( ) << 8 ) | ( position.getZ ( ) << 4 ) | position.getX ( ) ;
				
	return ( arrayPosition < Tortuga::Chunk::Size ) ? arrayPosition : 0 ;
}

Tortuga::Chunk::Chunk ( const ARC::Vector2SignedInt & position ) :
	position ( position )
{
}

Tortuga::Chunk::operator ARC::Buffer ( ) const
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
	
	ARC::Buffer buffer ;
	
	for ( ARC::UnsignedLong element = 0 ; element < deflator.getSize ( ) ; ++element )
		buffer.push_back ( deflator.get ( ) ) ;
		
	return Tortuga::WorldChunkPacket ( this->position , true , 0xFFFF , 0 , buffer ) ;
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

ARC::Void Tortuga::Chunk::setBlock ( const ARC::Vector3SignedInt & position , const Tortuga::Block block )
{
	
}
Tortuga::Block Tortuga::Chunk::getBlock ( const ARC::Vector3SignedInt & position ) const
{

}
			
ARC::Void Tortuga::Chunk::setBlockType ( const ARC::Vector3SignedInt & position , const Tortuga::Block::Type type )
{
	this->type [ this->getArrayPosition ( position ) ] = type ;
}
Tortuga::Block::Type Tortuga::Chunk::getBlockType ( const ARC::Vector3SignedInt & position )
{
	return static_cast <Tortuga::Block::Type> ( this->type [ this->getArrayPosition ( position ) ] ) ;
}
			
ARC::Void Tortuga::Chunk::setBlockMetadata ( const ARC::Vector3SignedInt & position , const Tortuga::Block::Metadata metadata )
{
	const ARC::UnsignedLong arrayPosition = this->getArrayPosition ( position ) ;
	const ARC::UnsignedLong part = arrayPosition >> 1 ;
	
	if ( arrayPosition & 1 )
	{
		this->metadata [ part ] &= 0x0F ;
		this->metadata [ part ] |= ( metadata << 4 ) ;
	}
	else
	{
		this->metadata [ part ] &= 0xF0 ;
		this->metadata [ part ] |= metadata ;
	}
}
Tortuga::Block::Metadata Tortuga::Chunk::getBlockMetadata ( const ARC::Vector3SignedInt & position )
{
	const ARC::UnsignedLong arrayPosition = this->getArrayPosition ( position ) ;
	const ARC::UnsignedLong part = arrayPosition >> 1 ;
	
	return static_cast <Tortuga::Block::Metadata> ( ( arrayPosition & 1 ) ? this->metadata [ part ] >> 4 : this->metadata [ part ] & 0xF ) ;
}

Tortuga::Chunk Tortuga::Chunk::getTestChunk ( Tortuga::Chunk chunk )
{
	for ( ARC::UnsignedLong element = 0 ; element < Tortuga::Chunk::Size / 4 ; element += 5 )
	{
		chunk.type [ element ] = Tortuga::Block::Stone ;
	}
	
	return chunk ;
}
