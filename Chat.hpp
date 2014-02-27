#pragma once

#include <ARC.hpp>

namespace Tortuga
{
	class Server ;
	class ChatUser ;
	class ChatMessage ;

	class Chat
	{
		private :
			Tortuga::Server & server ;
			
			ARC::List <ARC::SharedPointer <Tortuga::ChatUser>> chatUsers ;
			
		public :
			Chat ( Tortuga::Server & server ) ;
			
			Tortuga::Server & getServer ( ) ;
			const Tortuga::Server & getServer ( ) const ;
			
			ARC::List <ARC::SharedPointer <Tortuga::ChatUser>> & getChatUsers ( ) ;
			const ARC::List <ARC::SharedPointer <Tortuga::ChatUser>> & getChatUsers ( ) const ;
	
			ARC::Void broadcast ( const Tortuga::ChatMessage & message ) ;
			ARC::Void send ( const Tortuga::ChatMessage & message ) ;
	} ;
}
