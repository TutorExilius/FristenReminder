#include "stringType.h"

StringType::StringType( const std::string &fieldName, 
						const std::string &value,
						const bool optional )
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