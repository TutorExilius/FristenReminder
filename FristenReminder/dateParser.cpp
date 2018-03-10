#include "dateParser.h"

DateParser::DateParser( const bool optional,
                        const Date &value )
: FieldParser<Date> { optional, value }
{
}

bool DateParser::take( std::string fieldValue )
{
	Date date = Date::strToDate( fieldValue );
    if( !date.isValidDate( date ) )
    {
        return false;
    }
	this->value = date;
    return true;
}
