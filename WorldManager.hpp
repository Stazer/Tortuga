#pragma once

#include <ARC.hpp>
#include "World.hpp"

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
			
			ARC::List <Tortuga::World> worlds ;
			Tortuga::World * defaultWorld ;
			
		public :
			WorldManager ( Tortuga::Server & server ) ;
			
			Tortuga::Server & getServer ( ) ;
			const Tortuga::Server & getServer ( ) const ;
			
			ARC::List <Tortuga::World> & getWorlds ( ) ;
			const ARC::List <Tortuga::World> & getWorlds ( ) const ;
			
			ARC::Void setDefaultWorld ( Tortuga::World & defaultWorld ) ;
			Tortuga::World & getDefaultWorld ( ) ;
			const Tortuga::World & getDefaultWorld ( ) const ;
	} ;
}
