#include "Server.hpp"
#include "Application.hpp"
#include <ARC.hpp>

ARC::Return Application::main ( const ARC::Vector <ARC::String> & arguments )
{
	return Tortuga::Server::getInstance ( ).main ( arguments ) ;
}
