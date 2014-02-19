#pragma once

#include <ARC.hpp>
#include <iostream>
#include "ClientManager.hpp"
#include "StatusManager.hpp"
#include "ChatManager.hpp"
#include "WorldManager.hpp"

namespace Tortuga
{
	class Server : public ARC::TCPServer
	{
		private :			
			ARC::Thread threadHandle ;
			ARC::Void thread ( ) ;
			
			Tortuga::ClientManager clientManager ;
			Tortuga::StatusManager statusManager ;
			Tortuga::ChatManager chatManager ;
			Tortuga::WorldManager worldManager ;
			
			ARC::Bool running ;

		public :
			Server ( ) ;
			
			Tortuga::ClientManager & getClientManager ( ) ;
			const Tortuga::ClientManager & getClientManager ( ) const ;
			
			Tortuga::StatusManager & getStatusManager ( ) ;
			const Tortuga::StatusManager & getStatusManager ( ) const ;
			
			Tortuga::ChatManager & getChatManager ( ) ;
			const Tortuga::ChatManager & getChatManager ( ) const ;
			
			Tortuga::WorldManager & getWorldManager ( ) ;
			const Tortuga::WorldManager & getWorldManager ( ) const ;
			
			ARC::Void setRunning ( const ARC::Bool running ) ;
			ARC::Bool getRunning ( ) const ;
	
			ARC::Return main ( const ARC::Vector <ARC::String> & arguments ) ;
	} ;
}
