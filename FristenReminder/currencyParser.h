#ifndef CURRENCYPARSER_H
#define CURRENCYPARSER_H

#include "fieldParser.h"
#include "currencyType.h"

class CurrencyParser : public FieldParser<CurrencyType>
{
public:
	CurrencyParser( const bool optional, const CurrencyType &value = {} );
	virtual ~CurrencyParser() = default;

	virtual bool take( std::string fieldValue ) override;
};

#endif