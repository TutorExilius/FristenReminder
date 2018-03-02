#include "contract.h"

#include <iomanip>
#include <sstream>

Contract::Contract( const size_t &id,
					const StringType &name,
					const DateType &startDate,
					const CurrencyType &basicFee,
					const PeriodType &chargePeriod,
					const PeriodType &contractDuration,
					const PeriodType &cancellationPeriod,
					const StringType &contactDetails,
					const StringType &comment )
: id{ id }
, name{ name }
, beginning{ startDate }
, basicFee{ basicFee }
, chargePeriod{ chargePeriod }
, term{ contractDuration }
, noticePeriod{ cancellationPeriod }
, contactDetails{ contactDetails }
, comment{ comment }
{
}

std::string Contract::toString() const
{
	std::stringstream out;

	const int width = 22;

	out << std::left << std::setw( width ) << "ID:" << this->id << '\n';
	out << std::left << std::setw( width ) << "Partner:" << this->name.toString() << '\n';
	out << std::left << std::setw( width ) << "Start:"  << this->beginning.toString() << '\n';
	out << std::left << std::setw( width ) << "Basic-Fee:" << this->basicFee.toString() << '\n';
	out << std::left << std::setw( width ) << "Charge-Period:"<< this->chargePeriod.toString() << '\n';
	out << std::left << std::setw( width ) << "Durataion:" << this->term.toString() << '\n';
	out << std::left << std::setw( width ) << "Cancellation-Period:"  << this->noticePeriod.toString() << '\n';
	out << std::left << std::setw( width ) << "Contract-Details:" << this->contactDetails.toString() << '\n';
	out << std::left << std::setw( width ) << "Note:" << this->comment.toString() << '\n';

	return out.str();
}