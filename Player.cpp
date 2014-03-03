#include <Tortuga/Player.hpp>
#include <Tortuga/World/World.hpp>

Tortuga::Player::Player ( Tortuga::Client & client ) :
	client ( client ) ,
	onGround ( true ) ,
	world ( nullptr )
{
}
Tortuga::Player::Player ( Tortuga::Client & client , Tortuga::World * world ) :
	client ( client ) ,
	onGround ( true ) ,
	world ( nullptr )
{
	this->setWorld ( world ) ;
}
Tortuga::Player::~Player ( )
{
	this->setWorld ( nullptr ) ;
}

Tortuga::Client & Tortuga::Player::getClient ( )
{
	return this->client ;
}
const Tortuga::Client & Tortuga::Player::getClient ( ) const
{
	return this->client ;
}

ARC::Void Tortuga::Player::setWorld ( Tortuga::World * world )
{
	if ( this->world )
		this->world->getPlayers ( ).remove ( this ) ;
		
	this->world = world ;
	
	if ( this->world )
	{
		/*this->client.send ( Tortuga::Packet::writeClientJoinGamePacket ( { 0 , 1 , this->world->getDimension ( ) , this->world->getDifficulty ( ) , 0 , "default" } ) ) ;				
		this->client.send ( Tortuga::Packet::writeWorldSpawnPositionPacket ( { static_cast <ARC::SignedInt> ( this->world->getSpawnPosition ( ).getX ( ) ) , static_cast <ARC::SignedInt> ( this->world->getSpawnPosition ( ).getY ( ) ) , static_cast <ARC::SignedInt> ( this->world->getSpawnPosition ( ).getZ ( ) ) } ) ) ;	
		this->client.send ( Tortuga::Packet::writePlayerPositionAndLookPacket ( { this->world->getSpawnPosition ( ).getX ( ) , this->world->getSpawnPosition ( ).getY ( ) , this->world->getSpawnPosition ( ).getZ ( ) , 0 , 0 , true } ) ) ;
		this->client.send ( Tortuga::Packet::writeWorldTimeUpdatePacket ( { 0 , 300 } ) ) ;*/
	}
}
Tortuga::World * Tortuga::Player::getWorld ( )
{
	return this->world ;
}
const Tortuga::World * Tortuga::Player::getWorld ( ) const
{
	return this->world ;
}

ARC::Void Tortuga::Player::setLocation ( const Tortuga::Location & location )
{
	this->location = location ;
}
Tortuga::Location & Tortuga::Player::getLocation ( )
{
	return this->location ;
}
const Tortuga::Location & Tortuga::Player::getLocation ( ) const
{
	return this->location ;
}

ARC::Void Tortuga::Player::setOnGround ( const ARC::Bool onGround )
{
	this->onGround = onGround ;
}
const ARC::Bool Tortuga::Player::getOnGround ( ) const
{
	return this->onGround ;
}
const ARC::Bool Tortuga::Player::isOnGround ( ) const
{
	return this->onGround ;
}
