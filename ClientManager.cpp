#include "ClientManager.hpp"
#include "Client.hpp"
#include "Server.hpp"

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

ARC::Void Tortuga::ClientManager::update ( )
{
	if ( this->selector.wait ( ARC::Time ( ) ) )
	{
		if ( this->selector.isReady ( this->server ) )
		{
			ARC::SharedPointer <Tortuga::Client> client ( new Tortuga::Client ( * this ) ) ;
			
			if ( this->server.accept ( * client ) == ARC::Socket::Done )
			{
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
						this->selector.remove ( ** client ) ;
						client = this->clients.erase ( client ) ;
					}
				}
			}
		}
	}
}
