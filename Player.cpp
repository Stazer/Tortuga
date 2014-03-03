#include <Tortuga/Player.hpp>
#include <Tortuga/World/World.hpp>
#include <Tortuga/Protocol/JoinGamePacket.hpp>
#include <Tortuga/Protocol/SpawnPositionPacket.hpp>
#include <Tortuga/Protocol/PlayerPositionAndLookFromServerPacket.hpp>
#include <Tortuga/Protocol/TimeUpdatePacket.hpp>
#include <Tortuga/Client/Client.hpp>

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
		this->client.send ( Tortuga::JoinGamePacket ( 0 , world->getGamemode ( ) , world->getDimension ( ) , world->getDifficulty ( ) , "default" ) ) ;
		this->client.send ( Tortuga::SpawnPositionPacket ( world->getSpawnPosition ( ) ) ) ;
		this->client.send ( Tortuga::PlayerPositionAndLookFromServerPacket ( Tortuga::Location ( ) , true ) ) ;
		this->client.send ( Tortuga::TimeUpdatePacket ( 0 , 300 ) ) ;
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
