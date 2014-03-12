#pragma once

#include <ARC.hpp>
#include <Tortuga/Protocol/Packet.hpp>

namespace Tortuga
{
	class HandshakePacket : public Tortuga::Packet
	{
		private :
			ARC::UnsignedInt protocol ;
			ARC::String serverAddress ;
			ARC::UnsignedShort serverPort ;
			ARC::UnsignedInt state ;

			ARC::Void read ( Tortuga::PacketReader & packetReader ) ;
			ARC::Void write ( Tortuga::PacketWriter & packetWriter ) const ;

		public :
			HandshakePacket ( Tortuga::PacketReader & packetReader ) ;
			HandshakePacket ( ARC::UnsignedInt protocol , const ARC::String & serverAddress , ARC::UnsignedShort serverPort , ARC::UnsignedInt state ) ;

			ARC::Void setProtocol ( ARC::UnsignedInt protocol ) ;
			ARC::UnsignedInt getProtocol ( ) const ;

			ARC::Void setServerAddress ( const ARC::String & serverAddress ) ;
			const ARC::String & getServerAddress ( ) const ;

			ARC::Void setServerPort ( ARC::UnsignedShort serverPort ) ;
			ARC::UnsignedShort getServerPort ( ) const ;

			ARC::Void setState ( ARC::UnsignedInt state ) ;
			ARC::UnsignedInt getState ( ) const ;
	} ;
}
