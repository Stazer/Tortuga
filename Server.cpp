#include "Client.hpp"
#include "Server.hpp"
#include <ARC.hpp>

ARC::Void Tortuga::Server::thread ( )
{
	while ( this->running )
	{
		this->clientManager.update ( ARC::milliseconds ( 20 ) ) ;
		this->statusManager.update ( ) ;
		this->chatManager.update ( ) ;
		this->worldManager.update ( ) ;
	}
}

Tortuga::Server::Server ( ) :
	threadHandle ( & Server::thread , this ) ,
	clientManager ( * this ) ,
	statusManager ( * this ) ,
	chatManager ( * this ) ,
	worldManager ( * this ) ,
	running ( true )
{
}

Tortuga::ClientManager & Tortuga::Server::getClientManager ( )
{
	return this->clientManager ;
}
const Tortuga::ClientManager & Tortuga::Server::getClientManager ( ) const
{
	return this->clientManager ;
}

Tortuga::StatusManager & Tortuga::Server::getStatusManager ( )
{
	return this->statusManager ;
}
const Tortuga::StatusManager & Tortuga::Server::getStatusManager ( ) const
{
	return this->statusManager ;
}

Tortuga::ChatManager & Tortuga::Server::getChatManager ( )
{
	return this->chatManager ;
}
const Tortuga::ChatManager & Tortuga::Server::getChatManager ( ) const
{
	return this->chatManager ;
}

ARC::Void Tortuga::Server::setRunning ( const ARC::Bool running )
{
	this->running = running ;
}
ARC::Bool Tortuga::Server::getRunning ( ) const
{
	return this->running ;
}

ARC::Return Tortuga::Server::main ( const ARC::Vector <ARC::String> & arguments )
{
	ARC::Return returnValue = ARC::Ok ;
	                       
	std::cout << " __ __|          |\n" ;
	std::cout << "    |  _ \\   __| __| |   |  _` |  _` |\n" ;
	std::cout << "    | (   | |    |   |   | (   | (   |\n" ;
	std::cout << "   _|\\___/ _|   \\__|\\__,_|\\__, |\\__,_|\n" ;
	std::cout << "                          |___/\n\n" ;
	std::cout << "               _,.---.---.---.--.._\n" ;
	std::cout << "            _.-' `--.`---.`---'-. _,`--.._\n" ;
	std::cout << "           /`--._ .'.     `.     `,`-.`-._\\\n" ;
	std::cout << "          ||   \\  `.`---.__`__..-`. ,'`-._/\n" ;
	std::cout << "     _  ,`\\ `-._\\   \\    `.    `_.-`-._,``-.\n" ;
	std::cout << "  ,`   `-_ \\/ `-.`--.\\    _\\_.-'\\__.-`-.`-._`.\n" ;
	std::cout << " (_.o> ,--. `._/'--.-`,--`  \\_.-'       \\`-._ \\\n" ;
	std::cout << "  `---'    `._ `---._/__,----`           `-. `-\\\n" ;
	std::cout << "            /_, ,  _..-'                    `-._\\\n" ;
	std::cout << "            \\_, \\/ ._(\n" ;
	std::cout << "             \\_, \\/ ._\\\n" ;
	std::cout << "              `._,\\/ ._\\\n" ;
	std::cout << "                `._// ./`-._\n" ;
	std::cout << "                  `-._-_-_.-'\n" ;
	
	while ( this->listen ( 25565 ) != ARC::Socket::Done ) ;
	
	this->clientManager.initialize ( ) ;
	this->statusManager.initialize ( ) ;
	this->chatManager.initialize ( ) ;
	
	this->threadHandle.launch ( ) ;
	
	std::cout << "Server started\n" ; 

	while ( this->running )
	{
		ARC::String command ;
	
		std::cin >> command ;
		
		if ( command == "status" )
		{
		}
		else if ( command == "shutdown" || command == "stop" )
		{
			this->running = false ;	
		}
		else if ( command == "restart" )
		{
			returnValue = ARC::Restart ;
			break ;
		}
	}
	
	this->running = false ;
	
	this->threadHandle.wait ( ) ;
	
	this->chatManager.finalize ( ) ;
	this->statusManager.finalize ( ) ;
	this->clientManager.finalize ( ) ;
			
	std::cout << "Server stopped\n" ;
	
	return returnValue ;
}
