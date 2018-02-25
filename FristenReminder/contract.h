#ifndef CONTRACT_H
#define CONTRACT_H

#include <string>

#include "date.h"
#include "currency.h"
#include "period.h"

class Contract
{
public:
	explicit Contract( const size_t &id,
					   const std::string &partner,
					   const Date &startDate,
					   const Currency &basicFee,
					   const Period &chargePeriod,
					   const Period &contractDuration,
					   const Period &cancellationPeriod,
					   const std::string &contactDetails,
					   const std::string &note = "" );

	std::string toString() const;

private:
	const size_t id;
	std::string partner;
	Date startDate;
	Currency basicFee;
	Period chargePeriod;		
	Period contractDuration;	
	Period cancellationPeriod;
	std::string contactDetails;	 // Todo: as Custom Type?
	std::string note;
};

#endif // CONTRACT_H