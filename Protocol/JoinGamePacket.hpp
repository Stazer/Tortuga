#pragma once

#include <ARC.hpp>
#include <Tortuga/Protocol/Packet.hpp>

namespace Tortuga
{
	class JoinGamePacket : public Tortuga::Packet
	{
		private :
			ARC::UnsignedInt entityIdentification ;
			ARC::UnsignedChar gamemode ;
			ARC::SignedChar dimension ;
			ARC::UnsignedChar difficulty ;
			ARC::UnsignedChar maximalPlayers ;
			ARC::String levelType ;
		
			ARC::Void read ( Tortuga::PacketReader & packetReader ) ;
			ARC::Void write ( Tortuga::PacketWriter & packetWriter ) const ;
			
		public :
			JoinGamePacket ( Tortuga::PacketReader & packetReader ) ;
			JoinGamePacket ( const ARC::UnsignedInt entityIdentification , const ARC::UnsignedChar gamemode , const ARC::SignedChar dimension , const ARC::UnsignedChar difficulty , const ARC::String & levelType ) ;
			
			ARC::Void setEntityIdentification ( const ARC::UnsignedInt entityIdentification ) ;
			ARC::UnsignedInt getEntityIdentification ( ) const ;
			
			ARC::Void setGamemode ( const ARC::UnsignedChar gamemode ) ;
			ARC::UnsignedChar getGamemode ( ) const ;
			
			ARC::Void setDimension ( const ARC::SignedChar dimension ) ;
			ARC::SignedChar getDimension ( ) const ;
			
			ARC::Void setDifficulty ( const ARC::UnsignedChar difficulty ) ;
			ARC::UnsignedChar getDifficulty ( ) const ;
			
			ARC::Void setMaximalPlayers ( const ARC::UnsignedChar maximalPlayers ) ;
			ARC::UnsignedChar getMaximalPlayers ( ) const ;
			
			ARC::Void setLevelType ( const ARC::String & levelType ) ;
			const ARC::String & getLevelType ( ) const ;
	} ;
}
