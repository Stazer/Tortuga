#pragma once

#include <ARC.hpp>
#include "Client.hpp"

namespace Tortuga
{
	class Server ;
	class Client ;
	class Packet ;

	class StatusManager
	{	
		private :
			Tortuga::Server & server ;
			
		public :
			StatusManager ( Tortuga::Server & server ) ;
			
			Tortuga::Server & getServer ( ) ;
			const Tortuga::Server & getServer ( ) const ;
			
			ARC::Void initialize ( ) ;
			ARC::Void finalize ( ) ;
			
			ARC::Void update ( ) ;
	} ;
}
