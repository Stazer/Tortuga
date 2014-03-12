#pragma once

#include <ARC.hpp>
#include <Tortuga/Protocol/Packet.hpp>
#include <Tortuga/Location.hpp>
#include <Tortuga/Protocol/EntityMetadata.hpp>

namespace Tortuga
{
	class SpawnMobPacket : public Tortuga::Packet
	{
		private :
			ARC::UnsignedInt entityIdentification ;
			ARC::UnsignedChar type ;
			Tortuga::Location location ;
			ARC::Float headPitch ;
			ARC::Vector3SignedShort velocity ;
			Tortuga::EntityMetadata entityMetadata ;

			ARC::Void read ( Tortuga::PacketReader & packetReader ) ;
			ARC::Void write ( Tortuga::PacketWriter & packetWriter ) const ;

		public :
			SpawnMobPacket ( Tortuga::PacketReader & packetReader ) ;
			SpawnMobPacket ( ARC::UnsignedInt entityIdentification , ARC::UnsignedChar type , const Tortuga::Location & location , ARC::Float headPitch , const ARC::Vector3SignedShort & velocity , const Tortuga::EntityMetadata & entityMetadata ) ;

			ARC::Void setEntityIdentification ( ARC::UnsignedInt entityIdentification ) ;
			ARC::UnsignedInt getEntityIdentification ( ) const ;

			ARC::Void setType ( ARC::UnsignedChar type ) ;
			ARC::UnsignedChar getType ( ) const ;

			ARC::Void setLocation ( const Tortuga::Location & location ) ;
			Tortuga::Location & getLocation ( ) ;
			const Tortuga::Location & getLocation ( ) const ;

			ARC::Void setHeadPitch ( ARC::Float headPitch ) ;
			ARC::Float getHeadPitch ( ) const ;

			ARC::Void setVelocity ( const ARC::Vector3SignedShort & velocity ) ;
			ARC::Vector3SignedShort & getVelocity ( ) ;
			const ARC::Vector3SignedShort & getVelocity ( ) const ;

			ARC::Void setEntityMetadata ( const Tortuga::EntityMetadata & entityMetadata ) ;
			Tortuga::EntityMetadata & getEntityMetadata ( ) ;
			const Tortuga::EntityMetadata & getEntityMetadata ( ) const ;
	} ;
}
