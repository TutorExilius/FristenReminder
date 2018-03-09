#ifndef FIELDVALUE_H
#define FIELDVALUE_H

#include <string>

class FieldValue
{
public:
	FieldValue( const std::string &fieldName, const bool optional );
	virtual ~FieldValue();

	virtual std::string toString() const = 0;
	virtual bool take( std::string fieldValue ) = 0;

	std::string getFieldName() const
	{
		return this->fieldName;
	}

	bool isOptional() const
	{
		return this->optional;
	}

private:
	std::string fieldName;
	bool optional;
};

#endif // FIELDVALUE_H
