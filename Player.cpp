#include "Player.hpp"
#include "Client.hpp"
#include "Packet.hpp"

Tortuga::Player::Player ( Tortuga::Client & client ) :
	client ( client ) ,
	onGround ( true )
{
}

Tortuga::Client & Tortuga::Player::getClient ( )
{
	return this->client ;
}
const Tortuga::Client & Tortuga::Player::getClient ( ) const
{
	return this->client ;
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
			
ARC::Void Tortuga::Player::handlePlayerOnGround ( Tortuga::Packet & packet )
{
	this->onGround = Tortuga::Packet::readPlayerOnGroundPacket ( packet ).onGround ;
}
