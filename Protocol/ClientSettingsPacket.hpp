#pragma once

#include <ARC.hpp>
#include <Tortuga/Protocol/Packet.hpp>

namespace Tortuga
{
	class ClientSettingsPacket : public Tortuga::Packet
	{
		private :
			ARC::String locale ;
			ARC::UnsignedChar viewDistance ;
			ARC::UnsignedChar chatFlags ;
			ARC::Bool chatColors ;
			ARC::UnsignedChar difficulty ;
			ARC::Bool showCape ;
		
			ARC::Void read ( Tortuga::PacketReader & packetReader ) ;
			ARC::Void write ( Tortuga::PacketWriter & packetWriter ) const ;
			
		public :
			ClientSettingsPacket ( Tortuga::PacketReader & packetReader ) ;
			ClientSettingsPacket ( const ARC::String & locale , const ARC::UnsignedChar viewDistance , const ARC::UnsignedChar chatFlags , const ARC::Bool chatColors , const ARC::UnsignedChar difficulty , const ARC::Bool showCape ) ;
			
			ARC::Void setLocale ( const ARC::String & locale ) ;
			const ARC::String & getLocale ( ) const ;
			
			ARC::Void setViewDistance ( const ARC::UnsignedChar viewDistance ) ;
			ARC::UnsignedChar getViewDistance ( ) const ;
			
			ARC::Void setChatFlags ( const ARC::UnsignedChar chatFlags ) ;
			ARC::UnsignedChar getChatFlags ( ) const ;
			
			ARC::Void setChatColors ( const ARC::Bool chatColors ) ;
			ARC::Bool getChatColors ( ) const ;
			
			ARC::Void setDifficulty ( const ARC::UnsignedChar difficulty ) ;
			ARC::UnsignedChar getDifficulty ( ) const ;
			
			ARC::Void setShowCape ( const ARC::Bool showCape ) ;
			ARC::Bool getShowCape ( ) const ;
	} ;
}
