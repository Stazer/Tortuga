#pragma once

#include <ARC.hpp>
#include <Tortuga/Chat/ChatUser.hpp>
#include <Tortuga/Player.hpp>
#include <Tortuga/Difficulty.hpp>

namespace Tortuga
{
	class Server ;
	class ClientManager ;
	class ChatUser ;
	class Player ;
	class Packet ;

	class Client : public ARC::TCPSocket
	{
		public :
			enum Type
			{
				None = 0 ,
				Status = 1 ,
				Login = 2 ,
				Player = 3
			} ;
	
		private :
			Tortuga::ClientManager & clientManager ;
		
			ARC::Buffer buffer ;
			
			Type type ;
			
			Tortuga::ChatUser chatUser ;
			Tortuga::Player player ;
						
			ARC::String locale ;
			ARC::UnsignedChar viewDistance ;
			ARC::UnsignedChar chatFlags ;
			ARC::Bool chatColors ;
			Tortuga::Difficulty::Type difficulty ;
			ARC::Bool showCape ;
			
		public :
			Client ( Tortuga::ClientManager & clientManager ) ;
			
			Tortuga::ClientManager & getClientManager ( ) ;
			const Tortuga::ClientManager & getClientManager ( ) const ;			
			
			ARC::Void setBuffer ( const ARC::Buffer & buffer ) ;
			ARC::Buffer & getBuffer ( ) ;
			const ARC::Buffer & getBuffer ( ) const ;
			
			Tortuga::Server & getServer ( ) ;
			const Tortuga::Server & getServer ( ) const ;
			
			Tortuga::ChatUser & getChatUser ( ) ;
			const Tortuga::ChatUser & getChatUser ( ) const ;
			
			Tortuga::Player & getPlayer ( ) ;
			const Tortuga::Player & getPlayer ( ) const ;
			
			const ARC::String & getLocale ( ) const ;
			ARC::UnsignedChar getViewDistance ( ) const ;
			ARC::UnsignedChar getChatFlags ( ) const ;
			ARC::Bool getChatColors ( ) const ;
			Tortuga::Difficulty::Type getDifficulty ( ) const ;
			ARC::Bool getShowCape ( ) const ;
			
			ARC::Bool update ( ) ;
	} ;
}
