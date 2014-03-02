#pragma once

#include <ARC.hpp>
#include <Tortuga/Client/ClientManager.hpp>

namespace Tortuga
{
	class Server : public ARC::TCPListener
	{
		private :			
			Tortuga::ClientManager clientManager ;
		
			ARC::Thread threadHandle ;
			ARC::Void thread ( ) ;
			
			ARC::Bool running ;

		public :
			Server ( ) ;
			
			Tortuga::ClientManager & getClientManager ( ) ;
			const Tortuga::ClientManager & getClientManager ( ) const ;
			
			ARC::Void setRunning ( const ARC::Bool running ) ;
			ARC::Bool getRunning ( ) const ;
	
			ARC::Return main ( const ARC::Vector <ARC::String> & arguments ) ;
	} ;
}
