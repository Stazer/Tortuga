#pragma once

#include <ARC.hpp>

namespace Tortuga
{
	class ClientManager ;
	class Chat ;
	class WorldManager ;

	class Server : public ARC::TCPListener
	{
		private :			
			ARC::SharedPointer <Tortuga::ClientManager> clientManager ;
			ARC::SharedPointer <Tortuga::Chat> chat ;
			ARC::SharedPointer <Tortuga::WorldManager> worldManager ;
		
			ARC::Thread threadHandle ;
			ARC::Void thread ( ) ;
			
			ARC::Bool running ;

		public :
			Server ( ) ;
			
			Tortuga::ClientManager & getClientManager ( ) ;
			const Tortuga::ClientManager & getClientManager ( ) const ;
			
			Tortuga::Chat & getChat ( ) ;
			const Tortuga::Chat & getChat ( ) const ;
			
			Tortuga::WorldManager & getWorldManager ( ) ;
			const Tortuga::WorldManager & getWorldManager ( ) const ;
			
			ARC::Void setRunning ( const ARC::Bool running ) ;
			ARC::Bool getRunning ( ) const ;
	
			ARC::Return main ( const ARC::Vector <ARC::String> & arguments ) ;
	} ;
}
