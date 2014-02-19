#pragma once

#include <ARC.hpp>
#include "Client.hpp"

namespace Tortuga
{
	class Server ;
	class Packet ;

	class ClientManager
	{	
		private :
			Tortuga::Server & server ;
			
			ARC::List <ARC::SharedPointer <Tortuga::Client>> clients ;
			
			ARC::SocketSelector selector ;
			
			ARC::Timer keepAliveTimer ;
			
		public :
			ClientManager ( Tortuga::Server & server ) ;
			
			Tortuga::Server & getServer ( ) ;
			const Tortuga::Server & getServer ( ) const ;
			
			ARC::List <ARC::SharedPointer <Tortuga::Client>> & getClients ( ) ;
			const ARC::List <ARC::SharedPointer <Tortuga::Client>> & getClients ( ) const ;
			
			ARC::Void initialize ( ) ;
			ARC::Void finalize ( ) ;
			
			ARC::Void update ( const ARC::Time & timeout = ARC::Time ( ) ) ;
	} ;
}
