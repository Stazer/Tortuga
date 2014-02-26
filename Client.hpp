#pragma once

#include <ARC.hpp>

#include "Difficulty.hpp"

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
			
			ARC::SharedPointer <Tortuga::ChatUser> chatUser ;
			
			ARC::SharedPointer <Tortuga::Player> player ;
			
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
			
			// TODO: move to status
			ARC::Void handleStatusKeepAlive ( Tortuga::Packet & packet ) ;
			ARC::Void handleStatusRequest ( Tortuga::Packet & packet ) ;
			
			ARC::Void handleClientHandshake ( Tortuga::Packet & packet ) ;
			ARC::Void handleClientKeepAlive ( Tortuga::Packet & packet ) ;
			ARC::Void handleClientLoginStart ( Tortuga::Packet & packet ) ;
			ARC::Void handleClientSettings ( Tortuga::Packet & packet ) ;
	} ;
}
