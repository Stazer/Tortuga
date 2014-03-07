#pragma once

#include <ARC.hpp>

namespace Tortuga
{
    class PacketWriter ;
    class PacketReader ;

    class EntityMetadata
    {
        public :
            enum Index
            {
                Air = 0 ,

                Health = 6 ,
                PotionEffectColor = 7 ,
                IsPotionEffectAmbiet = 8 ,
                NumberOfArrowsInEntity = 9 ,
                NameTag = 10 ,
                AlwaysShowNameTag = 11
            } ;

            class Record
            {
                private :
                    ARC::UnsignedChar type ;
                    ARC::SharedPointer <ARC::Void> value ;

                public :
                    enum Type
                    {
                        Char = 0 ,
                        Short = 1 ,
                        Int = 2 ,
                        Float = 3 ,
                        String = 4 ,
                        // TODO
                        // Slot = 5 ,
                        // Position = 6 ,
                        None
                    } ;

                    Record ( ) ;
                    Record ( const ARC::SignedChar charValue ) ;
                    Record ( const ARC::SignedShort shortValue ) ;
                    Record ( const ARC::SignedInt intValue ) ;
                    Record ( const ARC::Float floatValue ) ;
                    Record ( const ARC::String stringValue ) ;

                    const Tortuga::EntityMetadata::Record::Type getType ( ) const ;

                    ARC::Void setCharValue ( const ARC::SignedChar charValue ) ;
                    ARC::SignedChar getCharValue ( ) const ;

                    ARC::Void setShortValue ( const ARC::SignedShort shortValue ) ;
                    ARC::SignedShort getShortValue ( ) const ;

                    ARC::Void setIntValue ( const ARC::SignedInt intValue ) ;
                    ARC::SignedInt getIntValue ( ) const ;

                    ARC::Void setFloatValue ( const ARC::Float floatValue ) ;
                    ARC::Float getFloatValue ( ) const ;

                    ARC::Void setStringValue ( const ARC::String & stringValue ) ;
                    ARC::String getStringValue ( ) const ;
            } ;

        private :
            ARC::UnorderedMap <ARC::UnsignedInt , Tortuga::EntityMetadata::Record> records ;

        public :
            EntityMetadata ( const ARC::UnorderedMap <ARC::UnsignedInt , Tortuga::EntityMetadata::Record> & records = ARC::UnorderedMap <ARC::UnsignedInt , Tortuga::EntityMetadata::Record> ( ) ) ;

            ARC::UnorderedMap <ARC::UnsignedInt , Tortuga::EntityMetadata::Record> & getRecords ( ) ;
            const ARC::UnorderedMap <ARC::UnsignedInt , Tortuga::EntityMetadata::Record> & getRecords ( ) const ;

            ARC::Void read ( Tortuga::PacketReader & packetReader ) ;
            ARC::Void write ( Tortuga::PacketWriter & packetWriter ) const ;
    } ;
}
