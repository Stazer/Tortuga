#pragma once

#include <ARC.hpp>
#include <Tortuga/Difficulty.hpp>

namespace Tortuga
{
	class Server ;
	class ClientManager ;
	class ChatUser ;
	class PlayerEntity ;
	class Packet ;
	class Entity ;
    class World ;

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
			Tortuga::ClientManager & clientManager ;

			ARC::Timer keepAliveTimer ;

			ARC::Buffer buffer ;

			Type type ;

			Tortuga::ChatUser * chatUser ;
			Tortuga::PlayerEntity * playerEntity ;

			ARC::String locale ;
			ARC::UnsignedChar viewDistance ;
			ARC::UnsignedChar chatFlags ;
			ARC::Bool chatColors ;
			Tortuga::Difficulty::Type difficulty ;
			ARC::Bool showCape ;

		public :
			Client ( Tortuga::ClientManager & clientManager ) ;
			~Client ( ) ;

			Tortuga::ClientManager & getClientManager ( ) ;
			const Tortuga::ClientManager & getClientManager ( ) const ;

			Tortuga::Server & getServer ( ) ;
			const Tortuga::Server & getServer ( ) const ;

			Tortuga::ChatUser * getChatUser ( ) ;
			const Tortuga::ChatUser * getChatUser ( ) const ;

			Tortuga::PlayerEntity * getPlayerEntity ( ) ;
			const Tortuga::PlayerEntity * getPlayerEntity ( ) const ;

			const ARC::String & getLocale ( ) const ;
			ARC::UnsignedChar getViewDistance ( ) const ;
			ARC::UnsignedChar getChatFlags ( ) const ;
			ARC::Bool getChatColors ( ) const ;
			Tortuga::Difficulty::Type getDifficulty ( ) const ;
			ARC::Bool getShowCape ( ) const ;

			ARC::Void joinWorld ( Tortuga::World & world ) ;

			ARC::Bool update ( ) ;
	} ;
}
