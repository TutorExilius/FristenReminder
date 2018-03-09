#ifndef CONTRACT_H
#define CONTRACT_H

#include "dateType.h"
#include "currencyType.h"
#include "periodType.h"

#include <string>
using std::size_t;

class Contract
{
public:
	explicit Contract( const size_t &id,
					   const std::string &name,
					   const Date &beginning,
					   const CurrencyType &basicFee,
					   const Period &chargePeriod,
					   const Period &term,
					   const Period &noticePeriod,
					   const std::string &contactDetails,
					   const std::string &comment );

	std::string toString() const;

	size_t getId() const;
	const std::string& getName() const;
	const Date& getBeginning() const;
	const CurrencyType& getBasicFee() const;
	const Period& getChargePeriod() const;
	const Period& getTerm() const;
	const Period& getNoticePeriod() const;
	const std::string& getContactDetails() const;
	const std::string& getComment() const;

private:
	const size_t id;
	std::string name;
	Date beginning;
	CurrencyType basicFee;
	Period chargePeriod;
	Period term;
	Period noticePeriod;
	std::string contactDetails;
	std::string comment;
};

#endif // CONTRACT_H