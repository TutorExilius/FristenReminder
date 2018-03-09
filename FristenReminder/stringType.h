#ifndef STRINGTYPE_H
#define STRINGTYPE_H

#include "fieldValue.h"

#include <string>

class StringType :	public FieldValue
{
public:
	StringType( const std::string &fieldName, const bool optional,
				const std::string &value = "" );
	virtual ~StringType();

	virtual std::string toString() const override;
	virtual bool take( std::string fieldValue ) override;

private:
	std::string value;

};

#endif // STRINGTYPE_H