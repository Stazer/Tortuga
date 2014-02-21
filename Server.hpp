#pragma once

#include <ARC.hpp>
#include "Client.hpp"

namespace Tortuga
{
	class Server : public ARC::Singleton <Tortuga::Server> , public ARC::TCPServer <Tortuga::Client>
	{
		private :			
			ARC::Thread threadHandle ;
			ARC::Void thread ( ) ;
			
			ARC::Bool running ;
			
			ARC::Void onConnect ( ARC::SharedPointer <Tortuga::Client> & client ) ;
			ARC::Void onDisconnect ( typename ARC::List <ARC::SharedPointer <Tortuga::Client>>::iterator & client ) ;
			ARC::Void onReceive ( typename ARC::List <ARC::SharedPointer <Tortuga::Client>>::iterator & client ) ;

		public :
			Server ( ) ;
			
			ARC::Void setRunning ( const ARC::Bool running ) ;
			ARC::Bool getRunning ( ) const ;
	
			ARC::Return main ( const ARC::Vector <ARC::String> & arguments ) ;
			
			ARC::Void update ( ) ;
	} ;
}
