#pragma once

#include <ARC.hpp>
#include <Tortuga/Protocol/Packet.hpp>
#include <Tortuga/Location.hpp>

namespace Tortuga
{
	class SpawnPlayerPacket : public Tortuga::Packet
	{
		private :
            ARC::UnsignedInt entityIdentification ;
            ARC::String uuid ;
            ARC::String name ;
            Tortuga::Location location ;
            ARC::UnsignedShort item ;

			ARC::Void read ( Tortuga::PacketReader & packetReader ) ;
			ARC::Void write ( Tortuga::PacketWriter & packetWriter ) const ;

		public :
			SpawnPlayerPacket ( Tortuga::PacketReader & packetReader ) ;
			SpawnPlayerPacket ( const ARC::UnsignedInt entityIdentification , const ARC::String & uuid , const ARC::String & name , const Tortuga::Location & location , const ARC::UnsignedShort item ) ;

            ARC::Void setEntityIdentification ( const ARC::UnsignedInt entityIdentification ) ;
            ARC::UnsignedInt getEntityIdentification ( ) const ;

            ARC::Void setUUID ( const ARC::String & uuid ) ;
            const ARC::String & getUUID ( ) const ;

            ARC::Void setName ( const ARC::String & name ) ;
            const ARC::String & getName ( ) const ;

            ARC::Void setLocation ( const Tortuga::Location & location ) ;
            Tortuga::Location & getLocation ( ) ;
            const Tortuga::Location & getLocation ( ) const ;

            ARC::Void setItem ( const ARC::UnsignedShort item ) ;
            const ARC::UnsignedShort getItem ( ) const ;
	} ;
}
