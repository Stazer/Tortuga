#include "ClientManager.hpp"
#include "Server.hpp"
#include "Packet.hpp"
#include "ChatUser.hpp"
#include <iostream>

Tortuga::ClientManager::ClientManager ( Tortuga::Server & server ) :
	server ( server )
{
}

Tortuga::Server & Tortuga::ClientManager::getServer ( )
{
	return this->server ;
}
const Tortuga::Server & Tortuga::ClientManager::getServer ( ) const
{
	return this->server ;
}

ARC::List <ARC::SharedPointer <Tortuga::Client>> & Tortuga::ClientManager::getClients ( )
{
	return this->clients ;
}
const ARC::List <ARC::SharedPointer <Tortuga::Client>> & Tortuga::ClientManager::getClients ( ) const
{
	return this->clients ;
}

ARC::Void Tortuga::ClientManager::initialize ( )
{
	this->selector.add ( this->server ) ;
}
ARC::Void Tortuga::ClientManager::finalize ( )
{
	this->selector.remove ( this->server ) ;
}

ARC::Void Tortuga::ClientManager::update ( const ARC::Time & timeout )
{
	if ( this->selector.wait ( timeout ) )
	{
		if ( this->selector.isReady ( this->server ) )
		{
			ARC::SharedPointer <Tortuga::Client> client ( new Tortuga::Client ( * this ) ) ;
				
			if ( this->server.accept ( * client ) == ARC::Socket::Done )
			{
				std::cout << "Client connected ( " << client->getRemoteAddress ( ) << ":" << client->getRemotePort ( ) << " )\n" ;
			
				this->selector.add ( * client ) ;
				this->clients.push_back ( client ) ;
			}
		}
		else
		{
			for ( auto client = this->clients.begin ( ) ; client != this->clients.end ( ) ; ++client )
			{
				if ( this->selector.isReady ( ( ** client ) ) )
				{
					if ( ( * client )->receive ( ) != ARC::Socket::Done )
					{
						std::cout << "Client disconnected ( " << ( * client )->getRemoteAddress ( ) << ":" << ( * client )->getRemotePort ( ) << " )\n" ;
					
						this->selector.remove ( ** client ) ;
						client = this->clients.erase ( client ) ;
					}
				}
			}
		}
	}
	
	for ( auto client = this->clients.begin ( ) ; client != this->clients.end ( ) ; ++client )
	{
		( * client )->update ( ) ;
	}
	
	if ( this->keepAliveTimer.getElapsedTime ( ).asSeconds ( ) > 5.0f )
	{
		for ( auto client = this->clients.begin ( ) ; client != this->clients.end ( ) ; ++client )
		{
			Tortuga::Packet packet = Tortuga::Packet::writeClientKeepAlivePacket ( { ARC::Randomizer::getNumber ( 0 , 100 ) } ) ;
		
			( * client )->send ( packet ) ;
		}
		
		this->keepAliveTimer.restart ( ) ;
	}
}
