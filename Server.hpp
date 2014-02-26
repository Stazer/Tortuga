#pragma once

#include <ARC.hpp>
#include "ClientManager.hpp"
#include "Chat.hpp"

namespace Tortuga
{
	class Server : public ARC::TCPListener
	{
		private :			
			Tortuga::ClientManager clientManager ;
			Tortuga::Chat chat ;
		
			ARC::Thread threadHandle ;
			ARC::Void thread ( ) ;
			
			ARC::Bool running ;
			
			ARC::Timer keepAliveTimer ;

		public :
			Server ( ) ;
			
			Tortuga::ClientManager & getClientManager ( ) ;
			const Tortuga::ClientManager & getClientManager ( ) const ;
			
			Tortuga::Chat & getChat ( ) ;
			const Tortuga::Chat & getChat ( ) const ;
			
			ARC::Void setRunning ( const ARC::Bool running ) ;
			ARC::Bool getRunning ( ) const ;
	
			ARC::Return main ( const ARC::Vector <ARC::String> & arguments ) ;
	} ;
}
