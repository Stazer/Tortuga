#include <Tortuga/Chat/ChatMessage.hpp>
#include <Tortuga/Protocol/ChatMessageFromServerPacket.hpp>

Tortuga::ChatMessage::ChatMessage ( const ARC::String & text ) :
	text ( text )
{
}

Tortuga::ChatMessage::operator ARC::Buffer ( ) const
{
	return Tortuga::ChatMessageFromServerPacket ( "{\"text\": \"" + this->text + "\"}" ) ;
}

ARC::Void Tortuga::ChatMessage::setText ( const ARC::String & text )
{
	this->text = text ;
}
const ARC::String & Tortuga::ChatMessage::getText ( ) const
{
	return this->text ;
}
