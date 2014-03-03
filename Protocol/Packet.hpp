#pragma once

#include <ARC.hpp>

namespace Tortuga
{
	class PacketReader ;
	class PacketWriter ;

	class Packet
	{
		protected :
			virtual ARC::Void read ( Tortuga::PacketReader & packetReader ) ;
			virtual ARC::Void write ( Tortuga::PacketWriter & packetWriter ) const ;
			
		public :
			Packet ( ) ;
			Packet ( Tortuga::PacketReader & reader ) ;
			
			virtual ~Packet ( ) ;
		
			operator ARC::Buffer ( ) const ;
			
			enum OperationCodes
			{
				Example = 0x00 ,
				
				StatusRequest = 0x00 ,
				StatusResponse = 0x00 ,
				StatusKeepAlive = 0x01 ,
			
				Handshake = 0x00 ,
				LoginStart = 0x00 ,
				LoginSuccess = 0x02 ,
				KeepAlive = 0x00 ,
				Disconnect = 0x00 ,
				
				ChatMessageFromServer = 0x02 ,
				ChatMessageToServer = 0x01 ,
				
				JoinGame = 0x01 ,
				ClientSettings = 0x15 ,
				
				SpawnPosition = 0x05 ,
				TimeUpdate = 0x03 ,
				WorldChunk = 0x21 ,
				
				PlayerPositionAndLookFromServer = 0x08 ,
				PlayerPositionAndLookToServer = 0x06 ,
							
			/*	PlayerAbilities = 0x13 ,
				PlayerOnGround = 0x03 ,
				PlayerPosition = 0x04 ,
				PlayerLook = 0x05*/
				
			} ;
	} ;
}
