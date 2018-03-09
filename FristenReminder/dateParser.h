#ifndef DATEPARSER_H
#define DATEPARSER_H

#include "fieldParser.h"
#include "dateType.h"

class DateParser : public FieldParser<Date>
{
public:
	DateParser( const bool optional, const Date &value = {} );
	virtual ~DateParser() = default;

	virtual bool take( std::string fieldValue ) override;
};


#endif