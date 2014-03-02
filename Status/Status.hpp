#pragma once

#include <ARC.hpp>

namespace Tortuga
{
	class Status
	{
		private :
			ARC::String version ;
			ARC::UnsignedShort protocol ;
			ARC::UnsignedShort maximalPlayers ;
			ARC::UnsignedShort onlinePlayers ;			
			ARC::String text ;
			
		public :
			Status ( const ARC::String & version = "1.7.5" , const ARC::UnsignedShort protocol = 4 , const ARC::UnsignedShort maximalPlayers = 0 , const ARC::UnsignedShort onlinePlayers = 0 , const ARC::String & text = "" ) ;
			
			operator ARC::Buffer ( ) ;
			
			ARC::Void setVersion ( const ARC::String & version ) ;
			const ARC::String & getVersion ( ) const ;
			
			ARC::Void setProtocol ( const ARC::UnsignedShort protocol ) ;
			const ARC::UnsignedShort getProtocol ( ) const ;
			
			ARC::Void setMaximalPlayers ( const ARC::UnsignedShort maximalPlayers ) ;
			const ARC::UnsignedShort getMaximalPlayers ( ) const ;
			
			ARC::Void setOnlinePlayers ( const ARC::UnsignedShort onlinePlayers ) ;
			const ARC::UnsignedShort getOnlinePlayers ( ) const ;
			
			ARC::Void setText ( const ARC::String & text ) ;
			const ARC::String & getText ( ) const ;
	} ;
}
