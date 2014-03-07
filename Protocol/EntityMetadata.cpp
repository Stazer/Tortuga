#include <Tortuga/Protocol/EntityMetadata.hpp>
#include <Tortuga/Protocol/PacketReader.hpp>
#include <Tortuga/Protocol/PacketWriter.hpp>

Tortuga::EntityMetadata::Record::Record ( ) :
    type ( Tortuga::EntityMetadata::Record::None )
{
}
Tortuga::EntityMetadata::Record::Record ( const ARC::SignedChar charValue ) :
    type ( Tortuga::EntityMetadata::Record::Char ) ,
    value ( new ARC::SignedChar ( charValue ) )
{
}
Tortuga::EntityMetadata::Record::Record ( const ARC::SignedShort shortValue ) :
    type ( Tortuga::EntityMetadata::Record::Short ) ,
    value ( new ARC::SignedShort ( shortValue ) )
{
}
Tortuga::EntityMetadata::Record::Record ( const ARC::SignedInt intValue ) :
    type ( Tortuga::EntityMetadata::Record::Int ) ,
    value ( new ARC::SignedInt ( intValue ) )
{
}
Tortuga::EntityMetadata::Record::Record ( const ARC::Float floatValue ) :
    type ( Tortuga::EntityMetadata::Record::Float ) ,
    value ( new ARC::Float ( floatValue ) )
{
}
Tortuga::EntityMetadata::Record::Record ( const ARC::String stringValue ) :
    type ( Tortuga::EntityMetadata::Record::String ) ,
    value ( new ARC::String ( stringValue ) )
{
}

const Tortuga::EntityMetadata::Record::Type Tortuga::EntityMetadata::Record::getType ( ) const
{
    return static_cast <Tortuga::EntityMetadata::Record::Type> ( this->type ) ;
}

ARC::Void Tortuga::EntityMetadata::Record::setCharValue ( const ARC::SignedChar charValue )
{
    if ( this->type == Tortuga::EntityMetadata::Record::Char )
        this->value = ARC::SharedPointer <ARC::Void> ( new ARC::SignedChar ( charValue ) ) ;
}
ARC::SignedChar Tortuga::EntityMetadata::Record::getCharValue ( ) const
{
    return ( this->type == Tortuga::EntityMetadata::Record::Char ) ? * reinterpret_cast <ARC::SignedChar *> ( this->value.get ( ) ) : 0 ;
}

ARC::Void Tortuga::EntityMetadata::Record::setShortValue ( const ARC::SignedShort shortValue )
{
    if ( this->type == Tortuga::EntityMetadata::Record::Short )
        this->value = ARC::SharedPointer <ARC::Void> ( new ARC::SignedShort ( shortValue ) ) ;
}
ARC::SignedShort Tortuga::EntityMetadata::Record::getShortValue ( ) const
{
    return ( this->type == Tortuga::EntityMetadata::Record::Short ) ? * reinterpret_cast <ARC::SignedShort *> ( this->value.get ( ) ) : 0 ;
}

ARC::Void Tortuga::EntityMetadata::Record::setIntValue ( const ARC::SignedInt intValue )
{
    if ( this->type == Tortuga::EntityMetadata::Record::Int )
        this->value = ARC::SharedPointer <ARC::Void> ( new ARC::SignedInt ( intValue ) ) ;
}
ARC::SignedInt Tortuga::EntityMetadata::Record::getIntValue ( ) const
{
    return ( this->type == Tortuga::EntityMetadata::Record::Int ) ? * reinterpret_cast <ARC::SignedInt *> ( this->value.get ( ) ) : 0 ;
}

ARC::Void Tortuga::EntityMetadata::Record::setFloatValue ( const ARC::Float floatValue )
{
    if ( this->type == Tortuga::EntityMetadata::Record::Float )
        this->value = ARC::SharedPointer <ARC::Void> ( new ARC::Float ( floatValue ) ) ;
}
ARC::Float Tortuga::EntityMetadata::Record::getFloatValue ( ) const
{
    return ( this->type == Tortuga::EntityMetadata::Record::Float ) ? * reinterpret_cast <ARC::Float *> ( this->value.get ( ) ) : 0 ;
}

ARC::Void Tortuga::EntityMetadata::Record::setStringValue ( const ARC::String & stringValue )
{
    if ( this->type == Tortuga::EntityMetadata::Record::String )
        this->value = ARC::SharedPointer <ARC::Void> ( new ARC::String ( stringValue ) ) ;
}
ARC::String Tortuga::EntityMetadata::Record::getStringValue ( ) const
{
    return ( this->type == Tortuga::EntityMetadata::Record::String ) ? * reinterpret_cast <ARC::String *> ( this->value.get ( ) ) : 0 ;
}

Tortuga::EntityMetadata::EntityMetadata ( const ARC::UnorderedMap <ARC::UnsignedInt , Tortuga::EntityMetadata::Record> & records ) :
    records ( records )
{
}

ARC::UnorderedMap <ARC::UnsignedInt , Tortuga::EntityMetadata::Record> & Tortuga::EntityMetadata::getRecords ( )
{
    return this->records ;
}
const ARC::UnorderedMap <ARC::UnsignedInt , Tortuga::EntityMetadata::Record> & Tortuga::EntityMetadata::getRecords ( ) const
{
    return this->records ;
}

ARC::Void Tortuga::EntityMetadata::read ( Tortuga::PacketReader & packetReader )
{
    // TODO ;)
}
ARC::Void Tortuga::EntityMetadata::write ( Tortuga::PacketWriter & packetWriter ) const
{

	/*packetWriter.writeChar ( ( 3 << 5 ) | 6 ) ;
	packetWriter.writeFloat ( 55.0f ) ;
    packetWriter.writeChar ( 0x7F ) ;*/

    for ( auto & record : this->records )
    {
        packetWriter.writeChar ( ( static_cast <ARC::UnsignedChar> ( record.second.getType ( ) ) << 5 ) | record.first ) ;

        switch ( record.second.getType ( ) )
        {
            case Tortuga::EntityMetadata::Record::Char :
            {
                packetWriter.writeChar ( record.second.getCharValue ( ) ) ;
                break ;
            }
            case Tortuga::EntityMetadata::Record::Short :
            {
                packetWriter.writeShort ( record.second.getShortValue ( ) ) ;
                break ;
            }
            case Tortuga::EntityMetadata::Record::Int :
            {
                packetWriter.writeInt ( record.second.getIntValue ( ) ) ;
                break ;
            }
            case Tortuga::EntityMetadata::Record::Float :
            {
                packetWriter.writeFloat ( record.second.getFloatValue ( ) ) ;
                break ;
            }
            case Tortuga::EntityMetadata::Record::String :
            {
                packetWriter.writeString ( record.second.getStringValue ( ) ) ;
                break ;
            }
        }
    }

    packetWriter.writeChar ( 0x7F ) ;
}
