#pragma once

#include <ARC.hpp>
#include "Player.hpp"
#include "ClientSettings.hpp"
#include "Packet.hpp"

namespace Tortuga
{
	class ClientManager ;
	class ChatUser ;

	class Client : public ARC::BufferedTCPClient
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
		
		public :
			Client ( ) ;
			
			ARC::Void setClientSettings ( const Tortuga::ClientSettings & clientSettings ) ;
			Tortuga::ClientSettings & getClientSettings ( ) ;
			const Tortuga::ClientSettings & getClientSettings ( ) const ;
			
			ARC::SharedPointer <Tortuga::ChatUser> & getChatUser ( ) ;
			const ARC::SharedPointer <Tortuga::ChatUser> & getChatUser ( ) const ;
			
			Tortuga::Player & getPlayer ( ) ;
			const Tortuga::Player & getPlayer ( ) const ;
			
			ARC::Void update ( ) ;
	} ;
}
