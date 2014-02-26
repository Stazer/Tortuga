#pragma once

#include <ARC.hpp>
namespace Tortuga
{
	class ChatUser ;
	class Server ;
	class Client ;
	class Packet ;
	class World ;
	
	class WorldManager
	{
		private :
			Tortuga::Server & server ;
			
			ARC::Vector <ARC::SharedPointer <Tortuga::World>> worlds ;
			ARC::SharedPointer <Tortuga::World> defaultWorld ;
			
		public :
			WorldManager ( Tortuga::Server & server ) ;
			
			Tortuga::Server & getServer ( ) ;
			const Tortuga::Server & getServer ( ) const ;
			
			ARC::Vector <ARC::SharedPointer <Tortuga::World>> & getWorlds ( ) ;
			const ARC::Vector <ARC::SharedPointer <Tortuga::World>> & getWorlds ( ) const ;
			
			ARC::Void setDefaultWorld ( Tortuga::World & defaultWorld ) ;
			Tortuga::World & getDefaultWorld ( ) ;
			const Tortuga::World & getDefaultWorld ( ) const ;
	} ;
}
