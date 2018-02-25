#include "contract.h"

#include <iomanip>
#include <sstream>

Contract::Contract( const size_t &id,
					const std::string &partner,
					const Date &startDate,
					const Currency &basicFee,
					const Period &chargePeriod,
					const Period &contractDuration,
					const Period &cancellationPeriod,
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

std::string Contract::toString() const
{
	std::stringstream out;

	const int width = 22;

	out << std::left << std::setw( width ) << "ID:" << this->id << '\n';
	out << std::left << std::setw( width ) << "Partner:" << this->partner << '\n';
	out << std::left << std::setw( width ) << "Start:"  << this->startDate.toString() << '\n';
	out << std::left << std::setw( width ) << "Basic-Fee:" << this->basicFee.toString() << '\n';
	out << std::left << std::setw( width ) << "Charge-Period:"<< this->chargePeriod.toString() << '\n';
	out << std::left << std::setw( width ) << "Durataion:" << this->contractDuration.toString() << '\n';
	out << std::left << std::setw( width ) << "Cancellation-Period:"  << this->cancellationPeriod.toString() << '\n';
	out << std::left << std::setw( width ) << "Contract-Details:" << this->contactDetails << '\n';
	out << std::left << std::setw( width ) << "Note:" << this->note << '\n';

	return out.str();
}