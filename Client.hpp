#pragma once

#include <ARC.hpp>
#include "Player.hpp"
#include "Packet.hpp"

namespace Tortuga
{
	class Server ;
	class ClientManager ;
	class ChatUser ;

	class Client : public ARC::TCPClient
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
			Type type ;
			
			ARC::SharedPointer <Tortuga::ChatUser> chatUser ;
			
			ARC::SharedPointer <Tortuga::Player> player ;
			
			ARC::String locale ;
			ARC::UnsignedChar viewDistance ;
			ARC::UnsignedChar chatFlags ;
			ARC::Bool chatColors ;
			ARC::UnsignedChar difficulty ;
			ARC::Bool showCape ;
			
			ARC::Void onReceive ( ) ;		
			
		public :
			Client ( ) ;
			
			Tortuga::Server & getServer ( ) ;
			const Tortuga::Server & getServer ( ) const ;
			
			ARC::SharedPointer <Tortuga::ChatUser> & getChatUser ( ) ;
			const ARC::SharedPointer <Tortuga::ChatUser> & getChatUser ( ) const ;
			
			ARC::SharedPointer <Tortuga::Player> & getPlayer ( ) ;
			const ARC::SharedPointer <Tortuga::Player> & getPlayer ( ) const ;
			
			const ARC::String & getLocale ( ) const ;
			ARC::UnsignedChar getViewDistance ( ) const ;
			ARC::UnsignedChar getChatFlags ( ) const ;
			ARC::Bool getChatColors ( ) const ;
			ARC::UnsignedChar getDifficulty ( ) const ;
			ARC::Bool getShowCape ( ) const ;
			
			// TODO: move to status
			ARC::Void handleStatusKeepAlive ( Tortuga::Packet & packet ) ;
			ARC::Void handleStatusRequest ( Tortuga::Packet & packet ) ;
			
			ARC::Void handleClientHandshake ( Tortuga::Packet & packet ) ;
			ARC::Void handleClientKeepAlive ( Tortuga::Packet & packet ) ;
			ARC::Void handleClientLoginStart ( Tortuga::Packet & packet ) ;
			ARC::Void handleClientSettings ( Tortuga::Packet & packet ) ;
	} ;
}
