#pragma once

#include <ARC.hpp>
#include "Player.hpp"
#include "ClientSettings.hpp"
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
			
			Tortuga::ClientSettings clientSettings ;
			
			Tortuga::Player player ;
			
			ARC::Void onReceive ( ) ;
			
			ARC::Void handleClientHandshake ( Tortuga::Packet & packet ) ;
			
			ARC::Void handleStatusKeepAlive ( Tortuga::Packet & packet ) ;
			ARC::Void handleStatusRequest ( Tortuga::Packet & packet ) ;
		
		public :
			Client ( ) ;
			
			Tortuga::Server & getServer ( ) ;
			const Tortuga::Server & getServer ( ) const ;
			
			ARC::Void setClientSettings ( const Tortuga::ClientSettings & clientSettings ) ;
			Tortuga::ClientSettings & getClientSettings ( ) ;
			const Tortuga::ClientSettings & getClientSettings ( ) const ;
			
			ARC::SharedPointer <Tortuga::ChatUser> & getChatUser ( ) ;
			const ARC::SharedPointer <Tortuga::ChatUser> & getChatUser ( ) const ;
			
			Tortuga::Player & getPlayer ( ) ;
			const Tortuga::Player & getPlayer ( ) const ;
	} ;
}
