#ifndef STRINGTYPE_H
#define STRINGTYPE_H

#include "fieldValue.h"

#include <string>

class StringType :	public FieldValue
{
public:
	StringType( const std::string &fieldName, const std::string &value,
				const bool optional );
	virtual ~StringType();

	virtual std::string toString() const override;

private:
	std::string value;

};

#endif // STRINGTYPE_H