#pragma once

#include <ARC.hpp>

namespace Tortuga
{
	class ChatMessage
	{
		private :
			ARC::String text ;
			
		public :
			ChatMessage ( const ARC::String & text = "" ) ;
			
			operator ARC::Buffer ( ) const ;
			
			ARC::Void setText ( const ARC::String & text ) ;
			const ARC::String & getText ( ) const ;
	} ;
}
