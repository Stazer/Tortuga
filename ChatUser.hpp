#pragma once

#include <ARC.hpp>

namespace Tortuga
{
	class Chat ;
	class Client ;
	class Packet ;

	class ChatUser
	{
		private :
			Tortuga::Chat & chat ;
			Tortuga::Client & client ;
		
			ARC::String name ;
			
		public :
			ChatUser ( Tortuga::Chat & chat , Tortuga::Client & client , const ARC::String & name = "" ) ;
			
			Tortuga::Chat & getChat ( ) ;
			const Tortuga::Chat & getChat ( ) const ;
			
			Tortuga::Client & getClient ( ) ;
			const Tortuga::Client & getClient ( ) const ;
			
			ARC::Void setName ( const ARC::String & name ) ;
			const ARC::String & getName ( ) const ;
			
			ARC::Void send ( const ARC::String & message ) ;
			ARC::Void broadcast ( const ARC::String & message ) ;
			
			ARC::Void handleChatMessage ( Tortuga::Packet & packet ) ;
	} ;
}
