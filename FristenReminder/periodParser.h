#ifndef PERIODPARSER_H
#define PERIODPARSER_H

#include "fieldParser.h"
#include "periodType.h"

class PeriodParser : public FieldParser<Period>
{
public:
	PeriodParser( const bool optional, const Period &value = {} );
	virtual ~PeriodParser() = default;

	virtual bool take( std::string fieldValue ) override;
};

#endif