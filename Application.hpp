#pragma once

#include <ARC.hpp>

class Application : public ARC::Application
{
	public : 
		static ARC::Return main ( const ARC::Vector <ARC::String> & arguments ) ;
} ;
