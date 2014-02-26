#include "ChatMessage.hpp"
#include "Packet.hpp"

Tortuga::ChatMessage::ChatMessage ( const ARC::String & text ) :
	text ( text )
{
}

Tortuga::ChatMessage::operator ARC::Buffer ( ) const
{
	return Tortuga::Packet::writeChatMessagePacket ( { "{\"text\": \"" + this->text + "\"}" } ) ;
}

ARC::Void Tortuga::ChatMessage::setText ( const ARC::String & text )
{
	this->text = text ;
}
const ARC::String & Tortuga::ChatMessage::getText ( ) const
{
	return this->text ;
}
