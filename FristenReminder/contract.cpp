#include "contract.h"

#include <iomanip>
#include <sstream>

Contract::Contract( const size_t &id,
					const StringType &name,
					const DateType &beginning,
					const CurrencyType &basicFee,
					const PeriodType &chargePeriod,
					const PeriodType &initialTerm,
					const PeriodType &renewalTerm,
					const PeriodType &noticePeriod,
					const StringType &contactDetails,
					const StringType &comment )
: id{ id }
, name{ name }
, beginning{ beginning }
, basicFee{ basicFee }
, chargePeriod{ chargePeriod }
, initialTerm{ initialTerm }
, renewalTerm{ renewalTerm }
, noticePeriod{ noticePeriod }
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
	out << std::left << std::setw( width ) << "Initial-Term:" << this->initialTerm.toString() << '\n';
	out << std::left << std::setw( width ) << "Renewal-Term:" << this->renewalTerm.toString() << '\n';
	out << std::left << std::setw( width ) << "Notice-Period:"  << this->noticePeriod.toString() << '\n';
	out << std::left << std::setw( width ) << "Contract-Details:" << this->contactDetails.toString() << '\n';
	out << std::left << std::setw( width ) << "Note:" << this->comment.toString() << '\n';

	return out.str();
}

size_t Contract::getId() const
{
	return this->id;
}

StringType Contract::getName() const
{
	return this->name;
}

DateType Contract::getBeginning() const
{
	return this->beginning;
}

CurrencyType Contract::getBasicFee() const
{
	return this->basicFee;
}

PeriodType Contract::getChargePeriod() const
{
	return this->chargePeriod;
}

PeriodType Contract::getInitialTerm() const
{
	return this->initialTerm;
}

PeriodType Contract::getRenewalTerm() const
{
	return this->renewalTerm;
}

PeriodType Contract::getNoticePeriod() const
{
	return this->noticePeriod;
}

StringType Contract::getContactDetails() const
{
	return this->contactDetails;
}

StringType Contract::getComment() const
{
	return this->comment;
}