#pragma once

#include <ARC.hpp>
#include <Tortuga/Client/ClientManager.hpp>
#include <Tortuga/Chat/Chat.hpp>
#include <Tortuga/World/WorldManager.hpp>

namespace Tortuga
{
	class Server : public ARC::TCPServerSocket
	{
		private :
			Tortuga::ClientManager clientManager ;
			Tortuga::Chat chat ;
			Tortuga::WorldManager worldManager ;

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
