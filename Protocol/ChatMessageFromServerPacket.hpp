#pragma once

#include <ARC.hpp>
#include <Tortuga/Protocol/Packet.hpp>

namespace Tortuga
{
	class ChatMessageFromServerPacket : public Tortuga::Packet
	{
		private :
			ARC::String message ;
		
			ARC::Void read ( Tortuga::PacketReader & packetReader ) ;
			ARC::Void write ( Tortuga::PacketWriter & packetWriter ) const ;
			
		public :
			ChatMessageFromServerPacket ( Tortuga::PacketReader & packetReader ) ;
			ChatMessageFromServerPacket ( const ARC::String & message ) ;
			
			ARC::Void setMessage ( const ARC::String & message ) ;
			const ARC::String & getMessage ( ) const ;
	} ;
}
