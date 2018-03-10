#include "contract.h"

#include <iomanip>
#include <sstream>

Contract::Contract( const size_t &id,
					const std::string &name,
					const Date &startDate,
					const CurrencyType &basicFee,
					const Period &chargePeriod,
					const Period &contractDuration,
					const Period &cancellationPeriod,
					const std::string &contactDetails,
					const std::string &comment )
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
	out << std::left << std::setw( width ) << "Partner:" << this->name << '\n';
	out << std::left << std::setw( width ) << "Start:"  << this->beginning.toString() << '\n';
	out << std::left << std::setw( width ) << "Basic-Fee:" << this->basicFee.toString() << '\n';
	out << std::left << std::setw( width ) << "Charge-Period:"<< this->chargePeriod.toString() << '\n';
	out << std::left << std::setw( width ) << "Durataion:" << this->term.toString() << '\n';
	out << std::left << std::setw( width ) << "Cancellation-Period:"  << this->noticePeriod.toString() << '\n';
	out << std::left << std::setw( width ) << "Contract-Details:" << this->contactDetails << '\n';
	out << std::left << std::setw( width ) << "Note:" << this->comment << '\n';

	return out.str();
}

size_t Contract::getId() const
{
	return this->id;
}

const std::string& Contract::getName() const
{
	return this->name;
}

const Date& Contract::getBeginning() const
{
	return this->beginning;
}

const CurrencyType& Contract::getBasicFee() const
{
	return this->basicFee;
}

const Period& Contract::getChargePeriod() const
{
	return this->chargePeriod;
}

const Period& Contract::getTerm() const
{
	return this->term;
}

const Period& Contract::getNoticePeriod() const
{
	return this->noticePeriod;
}

const std::string& Contract::getContactDetails() const
{
	return this->contactDetails;
}

const std::string& Contract::getComment() const
{
	return this->comment;
}