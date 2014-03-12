#pragma once

#include <ARC.hpp>
#include <Tortuga/Client/Client.hpp>

namespace Tortuga
{
	class Server ;

	class ClientManager
	{
		private :
			Tortuga::Server & server ;

			ARC::SocketSelector selector ;
			ARC::List <Tortuga::Client> clients ;

		public :
			ClientManager ( Tortuga::Server & server ) ;

			Tortuga::Server & getServer ( ) ;
			const Tortuga::Server & getServer ( ) const ;

			ARC::List <Tortuga::Client> & getClients ( ) ;
			const ARC::List <Tortuga::Client> & getClients ( ) const ;

			ARC::Void initialize ( ) ;

			ARC::Void update ( ) ;
	} ;
}
