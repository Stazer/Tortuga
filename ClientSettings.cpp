#include "ClientSettings.hpp"
#include "Client.hpp"
#include "Packet.hpp"

Tortuga::ClientSettings::ClientSettings ( const ARC::String & locale , const ARC::UnsignedChar viewDistance , const ARC::UnsignedChar chatFlags , const ARC::Bool chatColors , const ARC::UnsignedChar difficulty , const ARC::Bool showCape ) :
	locale ( locale ) ,
	viewDistance ( viewDistance ) ,
	chatFlags ( chatFlags ) ,
	chatColors ( chatColors ) ,
	difficulty ( difficulty ) ,
	showCape ( showCape )
{
}

ARC::Void Tortuga::ClientSettings::setLocale ( const ARC::String & locale )
{
	this->locale = locale ;
}
const ARC::String & Tortuga::ClientSettings::getLocale ( ) const
{
	return this->locale ;
}

ARC::Void Tortuga::ClientSettings::setViewDistance ( const ARC::UnsignedChar viewDistance )
{
	this->viewDistance = viewDistance ;
}
ARC::UnsignedChar Tortuga::ClientSettings::getViewDistance ( ) const
{
	return this->viewDistance ;
}

ARC::Void Tortuga::ClientSettings::setChatFlags ( const ARC::UnsignedChar chatFlags )
{
	this->chatFlags = chatFlags ;
}
ARC::UnsignedChar Tortuga::ClientSettings::getChatFlags ( ) const
{
	return this->chatFlags ;
}

ARC::Void Tortuga::ClientSettings::setChatColors ( const ARC::Bool chatColors )
{
	this->chatColors = chatColors ;
}
ARC::Bool Tortuga::ClientSettings::getChatColors ( ) const
{
	return this->chatColors ;
}

ARC::Void Tortuga::ClientSettings::setDifficulty ( const ARC::UnsignedChar difficulty )
{
	this->difficulty = difficulty ;
}
ARC::UnsignedChar Tortuga::ClientSettings::getDifficulty ( ) const
{
	return this->difficulty ;
}

ARC::Void Tortuga::ClientSettings::setShowCape ( const ARC::Bool showCape )
{
	this->showCape = showCape ;
}
ARC::Bool Tortuga::ClientSettings::getShowCape ( ) const
{
	return this->showCape ;
}

