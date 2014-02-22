#include "Server.hpp"
#include <iostream>

ARC::Void Tortuga::Server::thread ( )
{
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
			break ;
		}
	}
}


ARC::Void Tortuga::Server::onConnect ( ARC::SharedPointer <Tortuga::Client> & client )
{
	ARC::TCPServer <Tortuga::Client>::onConnect ( client ) ;
	
	std::cout << "Client connected ( " << client->getRemoteAddress ( ) << ":" << client->getRemotePort ( ) << " )\n" ;
}
ARC::Void Tortuga::Server::onDisconnect ( typename ARC::List <ARC::SharedPointer <Tortuga::Client>>::iterator & client )
{
	ARC::TCPServer <Tortuga::Client>::onDisconnect ( client ) ;
	
	std::cout << "Client disconnected ( " << ( * client )->getRemoteAddress ( ) << ":" << ( * client )->getRemotePort ( ) << " )\n" ;
}
ARC::Void Tortuga::Server::onReceive ( typename ARC::List <ARC::SharedPointer <Tortuga::Client>>::iterator & client )
{
	ARC::TCPServer <Tortuga::Client>::onReceive ( client ) ;
}

Tortuga::Server::Server ( ) :
	threadHandle ( & Server::thread , this ) ,
	running ( true )
{
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
	
	this->threadHandle.launch ( ) ;
	
	std::cout << "Server started\n" ; 

	while ( this->running )
	{
		this->update ( ) ;
	}
	
	this->threadHandle.wait ( ) ;
	
	std::cout << "Server stopped\n" ;
	
	return returnValue ;
}

ARC::Void Tortuga::Server::update ( )
{
	ARC::TCPClientManager <Tortuga::Client>::update ( ARC::milliseconds ( 20 ) , 1024 ) ;
	
	if ( this->keepAliveTimer.getElapsedTime ( ) >= ARC::seconds ( 5.0f ) )
	{
		for ( auto client : this->getClients ( ) )
		{
			client->send ( Tortuga::Packet::writeClientKeepAlivePacket ( { static_cast <ARC::UnsignedInt> ( ARC::Randomizer::getNumber ( 0 , 100  ) ) } ) ) ;
		}
		
		this->keepAliveTimer.restart ( ) ;
	}
}
