#include "Server.hpp"
#include "ClientManager.hpp"
#include "Client.hpp"
#include "Packet.hpp"
#include <iostream>

ARC::Void Tortuga::Server::thread ( )
{
	while ( this->running )
	{
		if ( this->keepAliveTimer.getElapsedTime ( ) >= ARC::seconds ( 5.0f ) )
		{
			for ( auto client : this->clientManager.getClients ( ) )
			{
				client->send ( Tortuga::Packet::writeClientKeepAlivePacket ( { static_cast <ARC::UnsignedInt> ( ARC::Randomizer::getNumber ( 0 , 100 ) ) } ) ) ;
			}
		
			this->keepAliveTimer.restart ( ) ;
		}
		
		this->clientManager.update ( ) ;
	}
}

Tortuga::Server::Server ( ) :
	clientManager ( * this ) ,
	chat ( * this ) ,
	worldManager ( * this ) ,
	threadHandle ( & Server::thread , this ) ,
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

Tortuga::Chat & Tortuga::Server::getChat ( )
{
	return this->chat ;
}
const Tortuga::Chat & Tortuga::Server::getChat ( ) const
{
	return this->chat ;
}

Tortuga::WorldManager & Tortuga::Server::getWorldManager ( )
{
	return this->worldManager ;
}
const Tortuga::WorldManager & Tortuga::Server::getWorldManager ( ) const
{
	return this->worldManager ;
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
			this->running = false ;
			returnValue = ARC::Restart ;
		}
	}
	
	this->threadHandle.terminate ( ) ;
	
	std::cout << "Server stopped\n" ;
	
	return returnValue ;
}
