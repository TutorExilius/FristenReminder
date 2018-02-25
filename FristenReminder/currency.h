#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>

#include "currencyCode.h"

class Currency
{
public:
	static CurrencyCode strToCurrencyCode( const std::string &currencyCodeStr );
	static std::string  currencyCodeToStr( const CurrencyCode &CurrencyCode );

	Currency( const float &amount, const CurrencyCode &currencyCode );
	Currency( const float &amount, const std::string &currencyCodeStr );

	std::string toString() const;

private:
	float amount;
	CurrencyCode currencyCode;
};

#endif // CURRENCY_H