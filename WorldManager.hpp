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
			
		public :
			WorldManager ( Tortuga::Server & server ) ;
			
			Tortuga::Server & getServer ( ) ;
			const Tortuga::Server & getServer ( ) const ;
					
			ARC::Void initialize ( ) ;
			ARC::Void finalize ( ) ;
			
			ARC::Void update ( ) ;
	} ;
}
