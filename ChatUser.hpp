#pragma once

#include <ARC.hpp>

namespace Tortuga
{
	class ChatManager ;
	class Client ;

	class ChatUser
	{
		private :
			Tortuga::ChatManager & chatManager ;
			Tortuga::Client & client ;
		
			ARC::String name ;
			
		public :
			ChatUser ( Tortuga::ChatManager & chatManager , Tortuga::Client & client , const ARC::String & name = "" ) ;
			
			Tortuga::ChatManager & getChatManager ( ) ;
			const Tortuga::ChatManager & getChatManager ( ) const ;
			
			Tortuga::Client & getClient ( ) ;
			const Tortuga::Client & getClient ( ) const ;
			
			ARC::Void setName ( const ARC::String & name ) ;
			const ARC::String & getName ( ) const ;
	} ;
}
