#ifndef CONTRACT_H
#define CONTRACT_H

#include <string>

#include "date.h"
#include "currency.h"

class Contract
{
public:
	explicit Contract( const size_t &id,
					   const std::string &partner,
					   const Date &startDate,
					   const float &basicFee,
					   const std::string &chargePeriod,
					   const std::string &contractDuration,
					   const std::string &cancellationPeriod,
					   const std::string &contactDetails,
					   const std::string &note = "" );
private:
	const size_t id;
	std::string partner;
	Date startDate;
	Currency basicFee;
	std::string chargePeriod;		// Todo: as enum
	std::string contractDuration;	// Todo: as Custom Type
	std::string cancellationPeriod;	// Todo: as Custom Type
	std::string contactDetails;		// Todo: as Custom Type
	std::string note;
};

#endif // CONTRACT_H