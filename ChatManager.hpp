#pragma once

#include <ARC.hpp>

namespace Tortuga
{
	class ChatUser ;
	class Server ;
	class Client ;
	class Packet ;
	
	class ChatManager
	{
		private :
			Tortuga::Server & server ;
		
			ARC::List <ARC::SharedPointer <Tortuga::ChatUser>> chatUsers ;
			
		public :
			ChatManager ( Tortuga::Server & server ) ;
			
			Tortuga::Server & getServer ( ) ;
			const Tortuga::Server & getServer ( ) const ;
		
			ARC::List <ARC::SharedPointer <Tortuga::ChatUser>> getChatUsers ( ) ;
			const ARC::List <ARC::SharedPointer <Tortuga::ChatUser>> getChatUsers ( ) const ;
			
			ARC::Void initialize ( ) ;
			ARC::Void finalize ( ) ;
			
			ARC::Void update ( ) ;
	} ;
}
