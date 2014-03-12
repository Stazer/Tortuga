#include <Tortuga/Client/ClientManager.hpp>
#include <Tortuga/Client/Client.hpp>
#include <Tortuga/Server/Server.hpp>

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

ARC::List <Tortuga::Client> & Tortuga::ClientManager::getClients ( )
{
	return this->clients ;
}
const ARC::List <Tortuga::Client> & Tortuga::ClientManager::getClients ( ) const
{
	return this->clients ;
}

ARC::Void Tortuga::ClientManager::initialize ( )
{
	this->selector.add ( this->server ) ;
}

ARC::Void Tortuga::ClientManager::update ( )
{
	if ( this->selector.wait ( ARC::milliseconds ( 20 ) ) )
	{
		if ( this->selector.update ( this->server ) )
		{
            Tortuga::Client client ( * this ) ;

			if ( this->server.accept ( client ) == ARC::Socket::Done )
			{
				this->selector.add ( client ) ;
				this->clients.push_back ( client ) ;
			}
		}
		else
		{
			for ( auto client = this->clients.begin ( ) ; client != this->clients.end ( ) ; ++client )
			{
				if ( this->selector.update ( ( * client ) ) )
				{
					if ( ! client->update ( ) )
					{
						this->selector.remove ( * client ) ;
						client = this->clients.erase ( client ) ;
					}
				}
			}
		}
	}
}
