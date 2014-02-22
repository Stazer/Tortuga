#include "Packet.hpp"
#include "Client.hpp"

Tortuga::Packet::Packet ( const ARC::Vector <ARC::UnsignedChar> & buffer ) :
	buffer ( buffer ) ,
	position ( 0 )
{
}

Tortuga::Packet::operator ARC::Buffer ( ) const
{
	return this->buffer ;
}

ARC::Void Tortuga::Packet::sendWith ( Tortuga::Client & client )
{
	client.send ( * this ) ;
}

const ARC::Vector <ARC::UnsignedChar> Tortuga::Packet::getBuffer ( ) const
{
	return this->buffer ;
}

ARC::UnsignedInt Tortuga::Packet::getPosition ( ) const
{
	return this->position ;
}
ARC::Void Tortuga::Packet::setPosition ( const ARC::UnsignedInt position )
{
	if ( this->buffer.size ( ) > position )
		this->position = position ;
}

ARC::Void Tortuga::Packet::writeChar ( const ARC::UnsignedChar value )
{
	this->buffer.push_back ( value ) ;
}
ARC::Void Tortuga::Packet::writeShort ( const ARC::UnsignedShort value )
{
	this->buffer.push_back ( ( value >> 8 ) & 0xFF ) ;
	this->buffer.push_back ( ( value ) & 0xFF ) ;
}
ARC::Void Tortuga::Packet::writeInt ( const ARC::UnsignedInt value )
{
	this->buffer.push_back ( ( value >> 24 ) & 0xFF ) ;
	this->buffer.push_back ( ( value >> 16 ) & 0xFF ) ;
	this->buffer.push_back ( ( value >> 8 ) & 0xFF ) ;
	this->buffer.push_back ( ( value ) & 0xFF ) ;
}
ARC::Void Tortuga::Packet::writeLong ( const ARC::UnsignedLong value )
{	
	this->buffer.push_back ( ( value >> 56 ) & 0xFF ) ;
	this->buffer.push_back ( ( value >> 48 ) & 0xFF ) ;
	this->buffer.push_back ( ( value >> 40 ) & 0xFF ) ;
	this->buffer.push_back ( ( value >> 32 ) & 0xFF ) ;
	this->buffer.push_back ( ( value >> 24 ) & 0xFF ) ;
	this->buffer.push_back ( ( value >> 16 ) & 0xFF ) ;
	this->buffer.push_back ( ( value >> 8 ) & 0xFF ) ;
	this->buffer.push_back ( ( value ) & 0xFF ) ;
}
ARC::Void Tortuga::Packet::writeVariableInt ( ARC::UnsignedInt value )
{
	if ( value == 0 )
		this->writeChar ( 0 ) ;
		
	ARC::SignedInt element = 0 ;
	
	for ( ; value ; ++element )
	{
		ARC::UnsignedChar newElement = value & 0x7F ;
		value >>= 7 ;
		
		if ( value )
			newElement |= 0x80 ;
			
		this->buffer.push_back ( newElement ) ;
	}
}
ARC::Void Tortuga::Packet::writeFloat ( const ARC::Float value )
{
	this->writeInt ( * ( reinterpret_cast <const ARC::UnsignedInt *> ( & value ) ) ) ;
}
ARC::Void Tortuga::Packet::writeDouble ( const ARC::Double value )
{
	this->writeLong ( * ( reinterpret_cast <const ARC::UnsignedLong *> ( & value ) ) ) ;
}
ARC::Void Tortuga::Packet::writeString ( const ARC::String & value )
{
	this->writeVariableInt ( value.size ( ) ) ;
	
	for ( auto iterator = value.begin ( ) ; iterator != value.end ( ) ; ++iterator )
	{
		this->writeChar ( * iterator ) ;
	}
}
ARC::Void Tortuga::Packet::writeBool ( const ARC::Bool value )
{
	this->writeChar ( value ? 1 : 0 ) ;
}

ARC::UnsignedChar Tortuga::Packet::readChar ( )
{
	if ( this->position < this->buffer.size ( ) )
		return this->buffer [ this->position++ ] ;
		
	return 0 ;
}
ARC::UnsignedShort Tortuga::Packet::readShort ( )
{
	return ( ( static_cast <ARC::UnsignedShort> ( this->readChar ( ) ) ) << 8 ) |
	       ( ( static_cast <ARC::UnsignedShort> ( this->readChar ( ) ) ) ) ;
}
ARC::UnsignedInt Tortuga::Packet::readInt ( )
{
	return ( ( static_cast <ARC::UnsignedInt> ( this->readChar ( ) ) ) << 24 ) |
	       ( ( static_cast <ARC::UnsignedInt> ( this->readChar ( ) ) ) << 16 ) |
	       ( ( static_cast <ARC::UnsignedInt> ( this->readChar ( ) ) ) << 8 ) |
	       ( ( static_cast <ARC::UnsignedInt> ( this->readChar ( ) ) ) ) ;
}
ARC::UnsignedLong Tortuga::Packet::readLong ( )
{
	return ( ( static_cast <ARC::UnsignedLong> ( this->readChar ( ) ) ) << 56 ) |
	       ( ( static_cast <ARC::UnsignedLong> ( this->readChar ( ) ) ) << 48 ) |
	       ( ( static_cast <ARC::UnsignedLong> ( this->readChar ( ) ) ) << 40 ) |
	       ( ( static_cast <ARC::UnsignedLong> ( this->readChar ( ) ) ) << 32 ) |
	       ( ( static_cast <ARC::UnsignedLong> ( this->readChar ( ) ) ) << 24 ) |
	       ( ( static_cast <ARC::UnsignedLong> ( this->readChar ( ) ) ) << 16 ) |
	       ( ( static_cast <ARC::UnsignedLong> ( this->readChar ( ) ) ) << 8 ) |
	       ( ( static_cast <ARC::UnsignedLong> ( this->readChar ( ) ) ) ) ;
}
ARC::UnsignedInt Tortuga::Packet::readVariableInt ( )
{
	ARC::UnsignedChar data [ 4 ] ;
	ARC::UnsignedInt bufferSize = 0 ;
	
	do
	{
		if ( bufferSize == 4 )
			return -1 ;
			
		data [ bufferSize++ ] = this->readChar ( ) ;
	} while ( data [ bufferSize - 1 ] & 0x80 ) ;
	
	ARC::UnsignedInt value = 0 ;
	
	for ( ARC::SignedInt element = bufferSize - 1 ; element >= 0 ; --element )
	{
		value <<= 7 ;
		value |= ( data [ element ] & 0x7F ) ;
	}
	
	return value ;
}
ARC::Float Tortuga::Packet::readFloat ( )
{
	ARC::UnsignedInt value = this->readInt ( ) ;
	
	return * ( reinterpret_cast <ARC::Float *> ( & value ) ) ;
}
ARC::Double Tortuga::Packet::readDouble ( )
{
	ARC::UnsignedLong value = this->readLong ( ) ;
	
	return * ( reinterpret_cast <ARC::Double *> ( & value ) ) ;
}
ARC::String Tortuga::Packet::readString ( )
{
	ARC::SignedInt length = this->readVariableInt ( ) ;
	
	ARC::String value = "" ;
	
	for ( ARC::SignedInt element = 0 ; element < length ; ++element )
	{
		value.push_back ( this->readChar ( ) ) ;
	}
	
	return value ;
}
ARC::Bool Tortuga::Packet::readBool ( )
{
	return this->readChar ( ) == false ;
}

Tortuga::Packet Tortuga::Packet::write ( const Tortuga::Packet & packet )
{
	return Tortuga::Packet::write ( packet.getBuffer ( ) ) ;
}
Tortuga::Packet Tortuga::Packet::write ( const ARC::Vector <ARC::UnsignedChar> & buffer )
{
	Tortuga::Packet newPacket ;
	
	newPacket.writeVariableInt ( buffer.size ( ) ) ;
	
	newPacket.buffer.insert ( newPacket.buffer.end ( ) , buffer.begin ( ) , buffer.end ( ) ) ;
	
	return newPacket ;
}

Tortuga::Packet Tortuga::Packet::read ( Tortuga::Packet packet )
{
	const ARC::UnsignedInt packetSize = packet.readVariableInt ( ) ;
	
	if ( packetSize > 0 )
	{
		packet.buffer.resize ( packetSize + 1 ) ;
	}
	else
		packet.buffer.clear ( ) ;
	
	return packet ;
}
Tortuga::Packet Tortuga::Packet::read ( const ARC::Vector <ARC::UnsignedChar> & buffer )
{
	return Tortuga::Packet::read ( Tortuga::Packet ( buffer ) ) ;
}

Tortuga::Packet::ClientHandshakeData Tortuga::Packet::readClientHandshakePacket ( Tortuga::Packet & packet )
{
	return { packet.readVariableInt ( ) , packet.readString ( ) , packet.readShort ( ) , packet.readVariableInt ( ) } ;
}

Tortuga::Packet::ClientLoginStartData Tortuga::Packet::readClientLoginStartPacket ( Tortuga::Packet & packet )
{
	return { packet.readString ( ) } ;
}

Tortuga::Packet Tortuga::Packet::writeClientLoginSuccessPacket ( const Tortuga::Packet::ClientLoginSuccessData & clientLoginSuccessData )
{
	Tortuga::Packet packet ;
			
	packet.writeVariableInt ( Tortuga::Packet::ClientLoginSuccess ) ;				
	packet.writeString ( clientLoginSuccessData.uuid ) ;
	packet.writeString ( clientLoginSuccessData.username ) ;
				
	return Tortuga::Packet::write ( packet ) ;
}

Tortuga::Packet Tortuga::Packet::writeClientJoinGamePacket ( const Tortuga::Packet::ClientJoinGameData & clientJoinGameData )
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

Tortuga::Packet::ClientKeepAliveData Tortuga::Packet::readClientKeepAlivePacket ( Tortuga::Packet & packet )
{
	return { packet.readInt ( ) } ;
}
Tortuga::Packet Tortuga::Packet::writeClientKeepAlivePacket ( const Tortuga::Packet::ClientKeepAliveData & clientKeepAliveData )
{
	Tortuga::Packet packet ;
				
	packet.writeVariableInt ( Tortuga::Packet::ClientKeepAlive ) ;
	packet.writeInt ( clientKeepAliveData.number ) ;
				
	return Tortuga::Packet::write ( packet ) ;
}

Tortuga::Packet::ClientSettingsData Tortuga::Packet::readClientSettingsPacket ( Tortuga::Packet & packet )
{
	return { packet.readString ( ) , packet.readChar ( ) , packet.readChar ( ) , packet.readBool ( ) , packet.readChar ( ) , packet.readBool ( ) } ;
}

Tortuga::Packet Tortuga::Packet::writeClientDisconnectPacket ( const Tortuga::Packet::ClientDisconnectData & clientDisconnectData )
{
	Tortuga::Packet packet ;
				
	packet.writeVariableInt ( Tortuga::Packet::ClientDisconnect ) ;
	packet.writeString ( clientDisconnectData.reason ) ;
				
	return packet ;
}

Tortuga::Packet::StatusRequestData Tortuga::Packet::readStatusRequestPacket ( Tortuga::Packet & packet )
{
	return Tortuga::Packet::StatusRequestData ( ) ;
}

Tortuga::Packet Tortuga::Packet::writeStatusResponsePacket ( const Tortuga::Packet::StatusResponseData & statusResponseData )
{
	Tortuga::Packet packet ;
				
	packet.writeVariableInt ( Tortuga::Packet::StatusResponse ) ;
	packet.writeString ( statusResponseData.response ) ;
				
	return Tortuga::Packet::write ( packet ) ;
}

Tortuga::Packet::StatusKeepAliveData Tortuga::Packet::readStatusKeepAlivePacket ( Tortuga::Packet & packet )
{
	return { packet.readLong ( ) } ;
}

Tortuga::Packet Tortuga::Packet::writeStatusKeepAlivePacket ( const Tortuga::Packet::StatusKeepAliveData & statusKeepAliveData )
{
	Tortuga::Packet packet ;
				
	packet.writeVariableInt ( Tortuga::Packet::StatusKeepAlive ) ;
	packet.writeLong ( statusKeepAliveData.time ) ;
				
	return Tortuga::Packet::write ( packet ) ;
}

Tortuga::Packet::ChatMessageData readChatMessagePacket ( Tortuga::Packet & packet )
{
	return { packet.readString ( ) } ;
}
Tortuga::Packet writeChatMessagePacket ( const Tortuga::Packet::ChatMessageData & chatMessageData )
{
	Tortuga::Packet packet ;
	
	packet.writeVariableInt ( Tortuga::Packet::ChatMessageFromServer ) ;
	packet.writeString ( chatMessageData.message ) ;
	
	return Tortuga::Packet::write ( packet ) ;
}

Tortuga::Packet Tortuga::Packet::writeWorldSpawnPositionPacket ( const Tortuga::Packet::WorldSpawnPositionData & worldSpawnPositinData )
{
	Tortuga::Packet packet ;
				
	packet.writeVariableInt ( Tortuga::Packet::WorldSpawnPosition ) ;
	packet.writeInt ( worldSpawnPositinData.x ) ;
	packet.writeInt ( worldSpawnPositinData.y ) ;
	packet.writeInt ( worldSpawnPositinData.z ) ;
				
	return Tortuga::Packet::write ( packet ) ;
}

Tortuga::Packet Tortuga::Packet::writeWorldTimeUpdatePacket ( const Tortuga::Packet::WorldTimeUpdateData & worldTimeUpdateData )
{
	Tortuga::Packet packet ;
				
	packet.writeVariableInt ( Tortuga::Packet::WorldTimeUpdate ) ;
	packet.writeLong ( worldTimeUpdateData.age ) ;
	packet.writeLong ( worldTimeUpdateData.time ) ;
				
	return Tortuga::Packet::write ( packet ) ;
}

Tortuga::Packet Tortuga::Packet::writePlayerPositionAndLookPacket ( const Tortuga::Packet::PlayerPositionAndLookData & playerPositionAndLookData )
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
Tortuga::Packet::PlayerPositionAndLookData Tortuga::Packet::readPlayerPositionAndLookPacket ( Tortuga::Packet & packet )
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

Tortuga::Packet::PlayerOnGroundData Tortuga::Packet::readPlayerOnGroundPacket ( Tortuga::Packet & packet )
{
	return { packet.readBool ( ) } ;
}

Tortuga::Packet::PlayerPositionData Tortuga::Packet::readPlayerPositionPacket ( Tortuga::Packet & packet )
{
	Tortuga::Packet::PlayerPositionData playerPositionData ;
				
	playerPositionData.x = packet.readDouble ( ) ;
	playerPositionData.y = packet.readDouble ( ) ;
	packet.readDouble ( ) ; // headY
	playerPositionData.y = packet.readDouble ( ) ;
	playerPositionData.onGround = packet.readBool ( ) ;
				
	return playerPositionData ;
}

Tortuga::Packet::PlayerLookData Tortuga::Packet::readPlayerLookPacket ( Tortuga::Packet & packet )
{
	return { packet.readFloat ( ) , packet.readFloat ( ) , packet.readBool ( ) } ;
}
