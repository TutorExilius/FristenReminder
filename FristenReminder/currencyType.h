#ifndef CURRENCY_H
#define CURRENCY_H

#include "currencyCode.h"
#include "fieldValue.h"

#include <string>

class CurrencyType : public FieldValue
{
public:
	static CurrencyCode strToCurrencyCode( const std::string &currencyCodeStr );
	static std::string  currencyCodeToStr( const CurrencyCode &CurrencyCode );

	CurrencyType( const std::string &fieldName, const bool optional,
				  const float &amount, const CurrencyCode &currencyCode );
	CurrencyType( const std::string &fieldName, const bool optional,
				  const float &amount, const std::string &currencyCodeStr );

	std::string toString() const override;

private:
	float amount;
	CurrencyCode currencyCode;
};

#endif // CURRENCY_H