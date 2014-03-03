#pragma once

#include <ARC.hpp>
#include <Tortuga/Protocol/Packet.hpp>

namespace Tortuga
{
	class ChatMessageToServerPacket : public Tortuga::Packet
	{
		private :
			ARC::String message ;
		
			ARC::Void read ( Tortuga::PacketReader & packetReader ) ;
			ARC::Void write ( Tortuga::PacketWriter & packetWriter ) const ;
			
		public :
			ChatMessageToServerPacket ( Tortuga::PacketReader & packetReader ) ;
			ChatMessageToServerPacket ( const ARC::String & message ) ;
			
			ARC::Void setMessage ( const ARC::String & message ) ;
			const ARC::String & getMessage ( ) const ;
	} ;
}
