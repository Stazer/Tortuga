#pragma once

#include <ARC.hpp>
#include <Tortuga/Protocol/Packet.hpp>

namespace Tortuga
{
	class LoginStartPacket : public Tortuga::Packet
	{
		private :
			ARC::String name ;
		
			ARC::Void read ( Tortuga::PacketReader & packetReader ) ;
			ARC::Void write ( Tortuga::PacketWriter & packetWriter ) const ;
			
		public :
			LoginStartPacket ( Tortuga::PacketReader & packetReader ) ;
			LoginStartPacket ( const ARC::String & name ) ;
		
			ARC::Void setName ( const ARC::String & name ) ;
			const ARC::String & getName ( ) const ;
	} ;
}
