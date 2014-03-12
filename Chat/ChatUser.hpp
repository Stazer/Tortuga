#pragma once

#include <ARC.hpp>

namespace Tortuga
{
	class Chat ;
	class Client ;
	class Packet ;
	class ChatMessage ;

	class ChatUser
	{
		private :
			Tortuga::Client & client ;
			Tortuga::Chat & chat ;

			ARC::String name ;

		public :
			ChatUser ( Tortuga::Client & client , Tortuga::Chat & chat , const ARC::String & name = "" ) ;
			~ChatUser ( ) ;

			Tortuga::Chat & getChat ( ) ;
			const Tortuga::Chat & getChat ( ) const ;

			Tortuga::Client & getClient ( ) ;
			const Tortuga::Client & getClient ( ) const ;

			ARC::Void setName ( const ARC::String & name ) ;
			const ARC::String & getName ( ) const ;

			ARC::Void send ( const Tortuga::ChatMessage & chatMessage ) ;

			ARC::Void handleChatMessage ( Tortuga::Packet & packet ) ;
	} ;
}
