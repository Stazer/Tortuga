#pragma once

#include <ARC.hpp>
#include <Tortuga/Protocol/Packet.hpp>

namespace Tortuga
{
	class LoginSuccessPacket : public Tortuga::Packet
	{
		private :
			ARC::String uuid ;
			ARC::String name ;
		
			ARC::Void read ( Tortuga::PacketReader & packetReader ) ;
			ARC::Void write ( Tortuga::PacketWriter & packetWriter ) const ;
			
		public :
			LoginSuccessPacket ( Tortuga::PacketReader & packetReader ) ;
			LoginSuccessPacket ( const ARC::String & uuid , const ARC::String & name ) ;
		
			ARC::Void setUUID ( const ARC::String & uuid ) ;
			const ARC::String & getUUID ( ) const ;
			
			ARC::Void setName ( const ARC::String & name ) ;
			const ARC::String & getName ( ) const ;
	} ;
}
