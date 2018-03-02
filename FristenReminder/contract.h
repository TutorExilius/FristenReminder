#ifndef CONTRACT_H
#define CONTRACT_H

#include "dateType.h"
#include "currencyType.h"
#include "periodtype.h"
#include "stringType.h"

#include <string>

class Contract
{
public:
	explicit Contract( const size_t &id,
					   const StringType &name,
					   const DateType &beginning,
					   const CurrencyType &basicFee,
					   const PeriodType &chargePeriod,
					   const PeriodType &term,
					   const PeriodType &noticePeriod,
					   const StringType &contactDetails,
					   const StringType &comment );

	std::string toString() const;

private:
	const size_t id;
	StringType name;
	DateType beginning;
	CurrencyType basicFee;
	PeriodType chargePeriod;
	PeriodType term;
	PeriodType noticePeriod;
	StringType contactDetails;
	StringType comment;
};

#endif // CONTRACT_H