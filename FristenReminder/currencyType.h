#ifndef CURRENCY_H
#define CURRENCY_H

#include "currencyCode.h"

#include <string>

class CurrencyType
{
	friend class CurrencyParser;
public:
	static CurrencyCode strToCurrencyCode( const std::string &currencyCodeStr );
	static std::string  currencyCodeToStr( const CurrencyCode &CurrencyCode );

	CurrencyType( const float &amount = 0.0f, const CurrencyCode &currencyCode = CurrencyCode::EUR );
	CurrencyType( const float &amount, const std::string &currencyCodeStr );

	std::string toString() const;
private:
	float amount;
	CurrencyCode currencyCode;
};

#endif // CURRENCY_H