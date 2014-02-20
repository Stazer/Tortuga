#pragma once

#include <ARC.hpp>

namespace Tortuga
{
	class Client ;

	class Packet
	{
		private :
			ARC::Vector <ARC::UnsignedChar> buffer ;
			ARC::UnsignedInt position ;
			
		public :
			Packet ( const ARC::Vector <ARC::UnsignedChar> & buffer = ARC::Vector <ARC::UnsignedChar> ( ) ) ;
		
			operator ARC::Buffer ( ) const ;
		
			ARC::Void sendWith ( Tortuga::Client & client ) ;
			
			const ARC::Vector <ARC::UnsignedChar> getBuffer ( ) const ;
			
			ARC::UnsignedInt getPosition ( ) const ;
			ARC::Void setPosition ( const ARC::UnsignedInt position ) ;
			
			ARC::Void clear ( ) ;
			
			ARC::UnsignedChar readChar ( ) ;
			ARC::UnsignedShort readShort ( ) ;
			ARC::UnsignedInt readInt ( ) ;
			ARC::UnsignedLong readLong ( ) ;
			ARC::UnsignedInt readVariableInt ( ) ;
			ARC::Float readFloat ( ) ;
			ARC::Double readDouble ( ) ;
			ARC::String readString ( ) ;
			ARC::Bool readBool ( ) ;	
			
			ARC::Void writeChar ( const ARC::UnsignedChar value ) ;
			ARC::Void writeShort ( const ARC::UnsignedShort value ) ;
			ARC::Void writeInt ( const ARC::UnsignedInt value ) ;
			ARC::Void writeLong ( const ARC::UnsignedLong value ) ;
			ARC::Void writeVariableInt ( ARC::UnsignedInt value ) ;
			ARC::Void writeFloat ( const ARC::Float value ) ;
			ARC::Void writeDouble ( const ARC::Double value ) ;
			ARC::Void writeString ( const ARC::String & value ) ;
			ARC::Void writeBool ( const ARC::Bool value ) ;
			
			static Tortuga::Packet write ( const Tortuga::Packet & packet ) ;
			static Tortuga::Packet write ( const ARC::Vector <ARC::UnsignedChar> & buffer ) ;
			
			static Tortuga::Packet read ( Tortuga::Packet packet ) ;
			static Tortuga::Packet read ( const ARC::Vector <ARC::UnsignedChar> & buffer ) ;
			
			enum OperationCodes
			{
				// Client
				ClientHandshake = 0x00 ,		
				ClientLoginStart = 0x00 ,
				ClientLoginSuccess = 0x02 ,
				ClientKeepAlive = 0x00 ,
				ClientJoinGame = 0x01 ,
				ClientSettings = 0x15 ,
				ClientDisconnect = 0x00 ,
				
				// Status
				StatusRequest = 0x00 ,
				StatusResponse = 0x00 ,
				StatusKeepAlive = 0x01 ,
				
				// Chat
				ChatMessageFromServer = 0x02 ,
				ChatMessageToServer = 0x01 ,
				
				// World
				WorldSpawnPosition = 0x05 ,
				WorldTimeUpdate = 0x03 ,
				WorldChunkData = 0x21 ,
				
				// Player
				PlayerAbilities = 0x13 ,
				PlayerOnGround = 0x03 ,
				PlayerPosition = 0x04 ,
				PlayerLook = 0x05 ,
				PlayerPositionAndLookFromServer = 0x08 ,
				PlayerPositionAndLookToServer = 0x06
			} ;
						
			// Client
			struct ClientHandshakeData
			{
				ARC::UnsignedInt protocol ;
				ARC::String serverAddress ;
				ARC::UnsignedShort serverPort ;
				ARC::UnsignedInt state ;
			} ;			
			static Tortuga::Packet::ClientHandshakeData readClientHandshakePacket ( Tortuga::Packet & packet )
			{
				return { packet.readVariableInt ( ) , packet.readString ( ) , packet.readShort ( ) , packet.readVariableInt ( ) } ;
			}
			
			struct ClientLoginStartData
			{
				ARC::String username ;
			} ;			
			static Tortuga::Packet::ClientLoginStartData readClientLoginStartPacket ( Tortuga::Packet & packet )
			{
				return { packet.readString ( ) } ;
			}
			
			struct ClientLoginSuccessData
			{
				ARC::String uuid ;
				ARC::String username ;
			} ;			
			static Tortuga::Packet writeClientLoginSuccessPacket ( const Tortuga::Packet::ClientLoginSuccessData & clientLoginSuccessData )
			{
				Tortuga::Packet packet ;
				
				packet.writeVariableInt ( Tortuga::Packet::ClientLoginSuccess ) ;				
				packet.writeString ( clientLoginSuccessData.uuid ) ;
				packet.writeString ( clientLoginSuccessData.username ) ;
				
				return Tortuga::Packet::write ( packet ) ;
			}
			
			struct ClientJoinGameData
			{
				ARC::UnsignedInt entityIdentification ;
				ARC::UnsignedChar gamemode ;
				ARC::SignedChar dimension ;
				ARC::UnsignedChar difficulty ;
				ARC::UnsignedChar maximalPlayers ;
				ARC::String levelType ;
			} ;
			static Tortuga::Packet writeClientJoinGamePacket ( const Tortuga::Packet::ClientJoinGameData & clientJoinGameData )
			{
				Tortuga::Packet packet ;
				
				packet.writeVariableInt ( Tortuga::Packet::ClientJoinGame ) ;
				packet.writeInt ( clientJoinGameData.entityIdentification ) ;
				packet.writeChar ( clientJoinGameData.gamemode ) ;
				packet.writeChar ( clientJoinGameData.dimension ) ;
				packet.writeChar ( clientJoinGameData.difficulty ) ;
				packet.writeChar ( clientJoinGameData.maximalPlayers ) ;
				packet.writeString ( clientJoinGameData.levelType ) ;
				
				return Tortuga::Packet::write ( packet ) ;
			}		
			
			struct ClientKeepAliveData
			{
				ARC::UnsignedInt number ;
			} ;
			static Tortuga::Packet::ClientKeepAliveData readClientKeepAlivePacket ( Tortuga::Packet & packet )
			{
				return { packet.readInt ( ) } ;
			}
			static Tortuga::Packet writeClientKeepAlivePacket ( const Tortuga::Packet::ClientKeepAliveData & clientKeepAliveData )
			{
				Tortuga::Packet packet ;
				
				packet.writeVariableInt ( Tortuga::Packet::ClientKeepAlive ) ;
				packet.writeInt ( clientKeepAliveData.number ) ;
				
				return Tortuga::Packet::write ( packet ) ;
			}			
			
			struct ClientSettingsData
			{
				ARC::String locale ;
				ARC::UnsignedChar viewDistance ;
				ARC::UnsignedChar chatFlags ;
				ARC::Bool chatColors ;
				ARC::UnsignedChar difficulty ;
				ARC::Bool showCape ;
			} ;
			static Tortuga::Packet::ClientSettingsData readClientSettingsPacket ( Tortuga::Packet & packet )
			{
				return { packet.readString ( ) , packet.readChar ( ) , packet.readChar ( ) , packet.readBool ( ) , packet.readChar ( ) , packet.readBool ( ) } ;
			}
			
			struct ClientDisconnectData
			{
				ARC::String reason ;
			} ;
			static Tortuga::Packet writeClientDisconnectPacket ( const Tortuga::Packet::ClientDisconnectData & clientDisconnectData )
			{
				Tortuga::Packet packet ;
				
				packet.writeVariableInt ( Tortuga::Packet::ClientDisconnect ) ;
				packet.writeString ( clientDisconnectData.reason ) ;
				
				return packet ;
			}
			
			// Status
			struct StatusRequestData
			{
			} ;			
			static Tortuga::Packet::StatusRequestData readStatusRequestPacket ( Tortuga::Packet & packet )
			{
				return Tortuga::Packet::StatusRequestData ( ) ;
			}
			
			struct StatusResponseData
			{
				ARC::String response ;
			} ;			
			static Tortuga::Packet writeStatusResponsePacket ( const Tortuga::Packet::StatusResponseData & statusResponseData )
			{
				Tortuga::Packet packet ;
				
				packet.writeVariableInt ( Tortuga::Packet::StatusResponse ) ;
				packet.writeString ( statusResponseData.response ) ;
				
				return Tortuga::Packet::write ( packet ) ;
			}
			
			struct StatusKeepAliveData
			{
				ARC::UnsignedLong time ;	
			} ;
			static Tortuga::Packet::StatusKeepAliveData readStatusKeepAlivePacket ( Tortuga::Packet & packet )
			{
				return { packet.readLong ( ) } ;
			}
			static Tortuga::Packet writeStatusKeepAlivePacket ( const Tortuga::Packet::StatusKeepAliveData & statusKeepAliveData )
			{
				Tortuga::Packet packet ;
				
				packet.writeVariableInt ( Tortuga::Packet::StatusKeepAlive ) ;
				packet.writeLong ( statusKeepAliveData.time ) ;
				
				return Tortuga::Packet::write ( packet ) ;
			}
			
			// World
			struct WorldSpawnPositionData
			{
				ARC::SignedInt x ;
				ARC::SignedInt y ;
				ARC::SignedInt z ;
			} ;
			static Tortuga::Packet writeWorldSpawnPositionPacket ( const Tortuga::Packet::WorldSpawnPositionData & worldSpawnPositinData )
			{
				Tortuga::Packet packet ;
				
				packet.writeVariableInt ( Tortuga::Packet::WorldSpawnPosition ) ;
				packet.writeInt ( worldSpawnPositinData.x ) ;
				packet.writeInt ( worldSpawnPositinData.y ) ;
				packet.writeInt ( worldSpawnPositinData.z ) ;
				
				return Tortuga::Packet::write ( packet ) ;
			}
			
			struct WorldTimeUpdateData
			{
				ARC::UnsignedLong age ;
				ARC::UnsignedLong time ;
			} ;
			static Tortuga::Packet writeWorldTimeUpdatePacket ( const Tortuga::Packet::WorldTimeUpdateData & worldTimeUpdateData )
			{
				Tortuga::Packet packet ;
				
				packet.writeVariableInt ( Tortuga::Packet::WorldTimeUpdate ) ;
				packet.writeLong ( worldTimeUpdateData.age ) ;
				packet.writeLong ( worldTimeUpdateData.time ) ;
				
				return Tortuga::Packet::write ( packet ) ;
			}
			
			// Player
			struct PlayerPositionAndLookData
			{
				ARC::Double x ;
				ARC::Double y ;
				ARC::Double z ;
				ARC::Float yaw ;
				ARC::Float pitch ;
				ARC::Bool onGround ;
			} ;
			static Tortuga::Packet writePlayerPositionAndLookPacket ( const Tortuga::Packet::PlayerPositionAndLookData & playerPositionAndLookData )
			{
				Tortuga::Packet packet ;
				
				packet.writeVariableInt ( Tortuga::Packet::PlayerPositionAndLookFromServer ) ;
				packet.writeDouble ( playerPositionAndLookData.x ) ;
				packet.writeDouble ( playerPositionAndLookData.y ) ;
				packet.writeDouble ( playerPositionAndLookData.z ) ;
				packet.writeFloat ( playerPositionAndLookData.yaw ) ;
				packet.writeFloat ( playerPositionAndLookData.pitch ) ;
				packet.writeBool ( playerPositionAndLookData.onGround ) ;
				
				return Tortuga::Packet::write ( packet ) ;
			}
			static Tortuga::Packet::PlayerPositionAndLookData readPlayerPositionAndLookPacket ( Tortuga::Packet & packet )
			{
				Tortuga::Packet::PlayerPositionAndLookData playerPositionAndLookData ;
				
				playerPositionAndLookData.x = packet.readDouble ( ) ;
				playerPositionAndLookData.y = packet.readDouble ( ) ;
				packet.readDouble ( ) ; // headY
				playerPositionAndLookData.z = packet.readDouble ( ) ;
				playerPositionAndLookData.yaw = packet.readFloat ( ) ;
				playerPositionAndLookData.pitch = packet.readFloat ( ) ;
				playerPositionAndLookData.onGround = packet.readBool ( ) ;
				
				return playerPositionAndLookData ;
			}
			
			struct PlayerOnGroundData
			{
				ARC::Bool onGround ;
			} ;
			static Tortuga::Packet::PlayerOnGroundData readPlayerOnGroundPacket ( Tortuga::Packet & packet )
			{
				return { packet.readBool ( ) } ;
			}
			
			struct PlayerPositionData
			{
				ARC::Double x ;
				ARC::Double y ;
				ARC::Double z ;
				ARC::Bool onGround ;			
			} ;
			static Tortuga::Packet::PlayerPositionData readPlayerPositionPacket ( Tortuga::Packet & packet )
			{
				Tortuga::Packet::PlayerPositionData playerPositionData ;
				
				playerPositionData.x = packet.readDouble ( ) ;
				playerPositionData.y = packet.readDouble ( ) ;
				packet.readDouble ( ) ; // headY
				playerPositionData.y = packet.readDouble ( ) ;
				playerPositionData.onGround = packet.readBool ( ) ;
				
				return playerPositionData ;
			}
			
			struct PlayerLookData
			{
				ARC::Float yaw ;
				ARC::Float pitch ;
				ARC::Bool onGround ;
			} ;
			static Tortuga::Packet::PlayerLookData readPlayerLookPacket ( Tortuga::Packet & packet )
			{
				return { packet.readFloat ( ) , packet.readFloat ( ) , packet.readBool ( ) } ;
			}
	} ;
}
