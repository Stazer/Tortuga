#include <Tortuga/Application.hpp>
#include <Tortuga/Server/Server.hpp>

ARC::Return Application::main ( const ARC::Vector <ARC::String> & arguments )
{
	return Tortuga::Server ( ).main ( arguments ) ;
}
