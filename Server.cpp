#include "Server.hpp"
#include "Client.hpp"
#include "Packet.hpp"
#include "World.hpp"
#include "ClientManager.hpp"
#include "Chat.hpp"
#include "WorldManager.hpp"
#include <iostream>

ARC::Void Tortuga::Server::thread ( )
{
	while ( this->running )
	{
		this->getClientManager ( ).update ( ) ;
	}
}

Tortuga::Server::Server ( ) :
	clientManager ( new Tortuga::ClientManager ( * this ) ) ,
	chat ( new Tortuga::Chat ( * this ) ) ,
	worldManager ( new Tortuga::WorldManager ( * this ) ) ,
	threadHandle ( & Server::thread , this ) ,
	running ( true )
{
}

Tortuga::ClientManager & Tortuga::Server::getClientManager ( )
{
	return * this->clientManager ;
}
const Tortuga::ClientManager & Tortuga::Server::getClientManager ( ) const
{
	return * this->clientManager ;
}

Tortuga::Chat & Tortuga::Server::getChat ( )
{
	return * this->chat ;
}
const Tortuga::Chat & Tortuga::Server::getChat ( ) const
{
	return * this->chat ;
}

Tortuga::WorldManager & Tortuga::Server::getWorldManager ( )
{
	return * this->worldManager ;
}
const Tortuga::WorldManager & Tortuga::Server::getWorldManager ( ) const
{
	return * this->worldManager ;
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
	
	this->getClientManager ( ).initialize ( ) ;
	
	this->threadHandle.launch ( ) ;
	
	std::cout << "Server started\n" ;
	
	/*
		DEBUG
	*/
	this->getWorldManager ( ).getWorlds ( ).push_back ( ARC::SharedPointer <Tortuga::World> ( new Tortuga::World ( Tortuga::World::getTestWorld ( Tortuga::World ( this->getWorldManager ( ) ) ) ) ) ) ;
	this->getWorldManager ( ).setDefaultWorld ( ** this->getWorldManager ( ).getWorlds ( ).begin ( ) ) ;

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
