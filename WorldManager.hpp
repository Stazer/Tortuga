#pragma once

#include <ARC.hpp>

namespace Tortuga
{
	class ChatUser ;
	class Server ;
	class Client ;
	class Packet ;
	
	class WorldManager
	{
		private :
			Tortuga::Server & server ;
			
			ARC::Vector <Tortuga::World> worlds ;
			
		public :
			WorldManager ( Tortuga::Server & server ) ;
			
			Tortuga::Server & getServer ( ) ;
			const Tortuga::Server & getServer ( ) const ;
			
			ARC::Vector <Tortuga::World> getWorlds ( ) ;
			const ARC::Vector <Tortuga::World> getWorlds ( ) const ;
	} ;
}
