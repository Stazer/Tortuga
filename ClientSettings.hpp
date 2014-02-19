#pragma once

#include <ARC.hpp>

namespace Tortuga
{
	class Client ;
	class Packet ;
	
	class ClientSettings
	{
		private :
			ARC::String locale ;
			ARC::UnsignedChar viewDistance ;
			ARC::UnsignedChar chatFlags ;
			ARC::Bool chatColors ;
			ARC::UnsignedChar difficulty ;
			ARC::Bool showCape ;
		
		public :
			ClientSettings ( const ARC::String & locale = "" , const ARC::UnsignedChar viewDistance = 0 , const ARC::UnsignedChar chatFlags = 0 , const ARC::Bool chatColors = false , const ARC::UnsignedChar difficulty = 0 , const ARC::Bool showCape = false ) ;
			
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
