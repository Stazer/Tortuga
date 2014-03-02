#include <Tortuga/Protocol/ClientSettingsPacket.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

ARC::Void Tortuga::ClientSettingsPacket::read ( Tortuga::PacketReader & packetReader )
{
	this->locale = packetReader.readString ( ) ;
	this->viewDistance = packetReader.readChar ( ) ;
	this->chatFlags = packetReader.readChar ( ) ;
	this->chatColors = packetReader.readBool ( ) ;
	this->difficulty = packetReader.readChar ( ) ;
	this->showCape = packetReader.readBool ( ) ;
}
ARC::Void Tortuga::ClientSettingsPacket::write ( Tortuga::PacketWriter & packetWriter ) const
{
	packetWriter.writeVariableInt ( Tortuga::Packet::ClientSettings ) ;
	packetWriter.writeString ( this->locale ) ;
	packetWriter.writeChar ( this->viewDistance ) ;
	packetWriter.writeChar ( this->chatFlags ) ;
	packetWriter.writeBool ( this->chatColors ) ;
	packetWriter.writeChar ( this->difficulty ) ;
	packetWriter.writeBool ( this->showCape ) ;
}

Tortuga::ClientSettingsPacket::ClientSettingsPacket ( Tortuga::PacketReader & packetReader )
{
	this->read ( packetReader ) ;
}
Tortuga::ClientSettingsPacket::ClientSettingsPacket ( const ARC::String & locale , const ARC::UnsignedChar viewDistance , const ARC::UnsignedChar chatFlags , const ARC::Bool chatColors , const ARC::UnsignedChar difficulty , const ARC::Bool showCape ) :
	locale ( locale ) ,
	viewDistance ( viewDistance ) ,
	chatFlags ( chatFlags ) ,
	chatColors ( chatColors ) ,
	difficulty ( difficulty ) ,
	showCape ( showCape )
{
}

ARC::Void Tortuga::ClientSettingsPacket::setLocale ( const ARC::String & locale )
{
	this->locale = locale ;
}
const ARC::String & Tortuga::ClientSettingsPacket::getLocale ( ) const
{
	return this->locale ;
}
			
ARC::Void Tortuga::ClientSettingsPacket::setViewDistance ( const ARC::UnsignedChar viewDistance )
{
	this->viewDistance = viewDistance ;
}
ARC::UnsignedChar Tortuga::ClientSettingsPacket::getViewDistance ( ) const
{
	return this->viewDistance ;
}
			
ARC::Void Tortuga::ClientSettingsPacket::setChatFlags ( const ARC::UnsignedChar chatFlags )
{
	this->chatFlags = chatFlags ;
}
ARC::UnsignedChar Tortuga::ClientSettingsPacket::getChatFlags ( ) const
{
	return this->chatFlags ;
}
			
ARC::Void Tortuga::ClientSettingsPacket::setChatColors ( const ARC::Bool chatColors )
{
	this->chatColors = chatColors ;
}
ARC::Bool Tortuga::ClientSettingsPacket::getChatColors ( ) const
{
	return this->chatColors ;
}
			
ARC::Void Tortuga::ClientSettingsPacket::setDifficulty ( const ARC::UnsignedChar difficulty )
{
	this->difficulty = difficulty ;
}
ARC::UnsignedChar Tortuga::ClientSettingsPacket::getDifficulty ( ) const
{
	return this->difficulty ;
}
			
ARC::Void Tortuga::ClientSettingsPacket::setShowCape ( const ARC::Bool showCape )
{
	this->showCape = showCape ;
}
ARC::Bool Tortuga::ClientSettingsPacket::getShowCape ( ) const
{
	return this->showCape ;
}
