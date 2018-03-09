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
				  const float &amount = 0.0f, const CurrencyCode &currencyCode = CurrencyCode::EUR );
	CurrencyType( const std::string &fieldName, const bool optional,
				  const float &amount, const std::string &currencyCodeStr );

	virtual std::string toString() const override;
	virtual bool take( std::string fieldValue ) override;

private:
	float amount;
	CurrencyCode currencyCode;
};

#endif // CURRENCY_H