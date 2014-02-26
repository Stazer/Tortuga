#pragma once

#include <ARC.hpp>

namespace Tortuga
{	
	class Server ;
	class Client ;

	class ClientManager
	{
		private :
			Tortuga::Server & server ;
			
			ARC::SocketSelector selector ;
			ARC::List <ARC::SharedPointer <Tortuga::Client>> clients ;
			
			ARC::Timer keepAliveTimer ;
			
		public :
			ClientManager ( Tortuga::Server & server ) ;
			
			Tortuga::Server & getServer ( ) ;
			const Tortuga::Server & getServer ( ) const ;
		
			ARC::List <ARC::SharedPointer <Tortuga::Client>> & getClients ( ) ;
			const ARC::List <ARC::SharedPointer <Tortuga::Client>> & getClients ( ) const ;
			
			ARC::Void initialize ( ) ;
			
			ARC::Void update ( ) ;
	} ;
}
