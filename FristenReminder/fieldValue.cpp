#include "fieldValue.h"

FieldValue::FieldValue( const std::string &fieldName, 
						const bool optional )
: fieldName{ fieldName }
, optional{ optional }
{
}

FieldValue::~FieldValue()
{
}