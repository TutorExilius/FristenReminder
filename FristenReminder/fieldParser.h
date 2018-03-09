#ifndef FIELDVALUE_H
#define FIELDVALUE_H

#include <string>

class FieldParserBase
{
public:
	FieldParserBase() = default;
	virtual ~FieldParserBase() = default;
	virtual bool take( std::string fieldValue ) = 0;
};

template<typename T>
class FieldParser : public FieldParserBase
{
public:
	FieldParser( const bool optional, T defaultValue )
	: optional{ optional }
	, value{ defaultValue }
	{
	}

	virtual ~FieldParser() = default;

	inline T& getValue()
	{
		return this->value;
	}

	inline bool isOptional() const
	{
		return this->optional;
	}

private:
	bool optional;
protected:
	T value;
};

#endif // FIELDVALUE_H
