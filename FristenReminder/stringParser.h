#ifndef STRINGTYPE_H
#define STRINGTYPE_H

#include "fieldParser.h"
#include <string>

class StringParser : public FieldParser<std::string>
{
public:
	StringParser( const bool optional, const std::string &value = "" );
	virtual ~StringParser() = default;

	virtual bool take( std::string fieldValue ) override;
};

#endif // STRINGTYPE_H