#include "stringParser.h"

StringParser::StringParser( const bool optional,
							const std::string &value )
: FieldParser<std::string> { optional, value }
{
}

bool StringParser::take( std::string fieldValue )
{
	if( fieldValue.size() > 0 )
	{
		this->value = fieldValue;
		return true;
	}
	return this->isOptional();
}
