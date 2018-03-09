#include "stringType.h"

StringType::StringType( const std::string &fieldName, 				
						const bool optional,
						const std::string &value )
: FieldValue{ fieldName, optional }
, value{ value }
{
}

StringType::~StringType()
{
}

std::string StringType::toString() const
{
	return this->value;
}

bool StringType::take( std::string fieldValue )
{
	if( fieldValue.size() > 0 )
	{
		this->value = fieldValue;
		return true;
	}
	else
	{
		if( this->isOptional() )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
