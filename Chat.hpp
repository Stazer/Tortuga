#pragma once

#include <ARC.hpp>

namespace Tortuga
{
	class Server ;
	class ChatUser ;

	class Chat
	{
		private :
			Tortuga::Server & server ;
			
			ARC::Vector <ARC::SharedPointer <Tortuga::ChatUser>> chatUsers ;
			
		public :
			Chat ( Tortuga::Server & server ) ;
			
			Tortuga::Server & getServer ( ) ;
			const Tortuga::Server & getServer ( ) const ;
			
			ARC::Vector <ARC::SharedPointer <Tortuga::ChatUser>> & getChatUsers ( ) ;
			const ARC::Vector <ARC::SharedPointer <Tortuga::ChatUser>> & getChatUsers ( ) const ;
			
			ARC::Void send ( const ARC::String & message ) ;
	} ;
}
