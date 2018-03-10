#include "currencyParser.h"

#include <sstream>

CurrencyParser::CurrencyParser( const bool optional,
                                const CurrencyType &value )
: FieldParser<CurrencyType> { optional, value }
{
}

bool CurrencyParser::take( std::string fieldValue )
{
	std::stringstream ss;
	ss << fieldValue;

	float chargePeriodFloat = 0.0f;
	std::string chargePeriodUnitStr;

	ss >> chargePeriodFloat;
	ss >> chargePeriodUnitStr;

	CurrencyType result = CurrencyType { chargePeriodFloat, CurrencyType::strToCurrencyCode( chargePeriodUnitStr ) };
	if( result.currencyCode == CurrencyCode::ERROR )
	{
		return false;
	}
	this->value = result;
	return true;
}
