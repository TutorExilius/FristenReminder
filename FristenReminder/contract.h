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
	// Field-Name Definitions
	constexpr static char *NAME = "name";
	constexpr static char *BEGINNING = "beginning";
	constexpr static char *BASIC_FEE = "basicFee";
	constexpr static char *CHARGE_PERIOD = "chargePeriod";
	constexpr static char *COMMENT = "comment";
	constexpr static char *CONTACT_DETAILS = "contactDetails";
	constexpr static char *INITIAL_TERM = "initialTerm";
	constexpr static char *NOTICE_PERIOD = "noticePeriod";
	constexpr static char *RENEWAL_TERM = "renewalTerm";

	explicit Contract( const size_t &id,
					   const StringType &name,
					   const DateType &beginning,
					   const CurrencyType &basicFee,
					   const PeriodType &chargePeriod,
					   const PeriodType &initialTerm,
					   const PeriodType &renewalTerm,
					   const PeriodType &noticePeriod,
					   const StringType &contactDetails,
					   const StringType &comment );

	std::string toString() const;

	size_t getId() const;
	StringType getName() const;
	DateType getBeginning() const;
	CurrencyType getBasicFee() const;
	PeriodType getChargePeriod() const;
	PeriodType getInitialTerm() const;
	PeriodType getRenewalTerm() const;
	PeriodType getNoticePeriod() const;
	StringType getContactDetails() const;
	StringType getComment() const;

private:
	const size_t id;
	StringType name;
	DateType beginning;
	CurrencyType basicFee;
	PeriodType chargePeriod;
	PeriodType initialTerm;
	PeriodType renewalTerm;
	PeriodType noticePeriod;
	StringType contactDetails;
	StringType comment;
};

#endif // CONTRACT_H