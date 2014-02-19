#include "World.hpp"
#include "Client.hpp"
#include "Packet.hpp"
#include <cryptopp/zlib.h>

Tortuga::World::World ( Tortuga::WorldManager & worldManager ) :
	worldManager ( worldManager )
{
}
			
Tortuga::WorldManager & Tortuga::World::getWorldManager ( )
{
	return this->worldManager ;
}
const Tortuga::WorldManager & Tortuga::World::getWorldManager ( ) const
{
	return this->worldManager ;
}
/*
ARC::Void Tortuga::World::writeTimeUpdate ( Tortuga::Client & client , const ARC::UnsignedLong ageOfWorld , const ARC::UnsignedLong timeOfDay )
{
	Tortuga::Packet packet ;
	
	packet.setVariableInt ( Tortuga::Packet::TimeUpdate ) ;
	packet.setLong ( ageOfWorld ) ;
	packet.setLong ( timeOfDay ) ;
	
	Tortuga::Packet::encode ( packet ).sendWith ( client ) ;
}
ARC::Void Tortuga::World::writeSpawnPositionPacket ( Tortuga::Client & client , const ARC::SignedInt positionX , const ARC::SignedInt positionY , const ARC::SignedInt positionZ )
{
	Tortuga::Packet packet ;

	packet.setVariableInt ( Tortuga::Packet::Server::SpawnPosition ) ;
	packet.setInt ( positionX ) ;
	packet.setInt ( positionY ) ;
	packet.setInt ( positionZ ) ;
					
	Tortuga::Packet::encode ( packet ).sendWith ( client ) ;
}
/*
#include <cryptopp/zlib.h>
#include <cryptopp/cryptlib.h>

struct chunkdata
{
	unsigned char blocks [ 4096 ] ;
} ;

ARC::Void Tortuga::World::writeChunkData ( Tortuga::Client & client , const ARC::SignedInt positionX , const ARC::SignedInt positionY , const ARC::Bool groundUpContinuous , const ARC::UnsignedShort primaryBitmask , const ARC::UnsignedShort addBitmask , const ARC::UnsignedInt dataSize , const ARC::UnsignedChar * data  )
{
		/*Tortuga::Packet p ;
		
		p.setVariableInt ( Tortuga::Packet::ChunkData ) ; 	//opcode for chunkdata
		p.setInt ( positionX ) ;		//x
		p.setInt ( positionY ) ;		//y
		p.setBool ( true ) ;		//ground-up continueous
		p.setShort ( 0b1 ) ;		//bitmask with 1 bit for every 16x16x16
		p.setShort ( 0b1 ) ;		//Same as above, but this is used exclusively for the 'add' portion of the payload 
		
		
		
		
		
		
		chunkdata chunk ;
		
		/*for ( int i = 0 ; i < 16 ; ++i )
		{
			for ( int block = 0 ; block < 4096 ; ++block )
			{
				chunk [ i ].blocks [ block ] = 0 ;
			}
		}*
		
		for ( int i = 0 ; i < 512 ; ++i )
		{
			chunk.blocks [ i ] = 0x1 ;
		}
		
		CryptoPP::ZlibCompressor press ;
		
		for ( int i = 0 ; i < 512 ; ++i )
		{
			press.Put ( chunk.blocks [ i ] ) ;
		}
		
		press.MessageEnd ( ) ;
		
		ARC::UnsignedInt size = press.MaxRetrievable ( ) ;
		
		
		p.setInt ( size ) ;		//compressedsize
		
		for ( ARC::UnsignedInt i = 0 ; i < size ; ++i )
		{
			ARC::UnsignedChar byte ;
			
			press.Get ( byte ) ;
			
			p.setChar ( byte ) ;
		}
		//p.setChar ( 0 ) ;		//chunkdata
		
		//delete buf ;
		*/
		
/*		
		//Tortuga::Packet::encode ( p ).sendWith ( client ) ;
}*/
