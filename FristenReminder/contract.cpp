#include "contract.h"

Contract::Contract( const size_t &id,
					const std::string &partner,
					const Date &startDate,
					const float &basicFee,
					const std::string &chargePeriod,
					const std::string &contractDuration,
					const std::string &cancellationPeriod,
					const std::string &contactDetails, 
					const std::string &note )
: id{ id }
, partner{ partner }
, startDate{ startDate }
, basicFee{ basicFee }
, chargePeriod{ chargePeriod }
, contractDuration{ contractDuration }
, cancellationPeriod{ cancellationPeriod }
, contactDetails{ contactDetails }
, note{ note }
{
}