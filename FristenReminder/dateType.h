#ifndef DATETYPE_H
#define DATETYPE_H

#include "fieldValue.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

class Date
{
	friend class DateType;

public:
	enum class Month { NONE, JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OKT, NOV, DEC };

	Date( const size_t day,
		  const Date::Month month,
		  const int year );

	static Date strToDate( const string &dateStr );
	static size_t monthToInt( const Month enumMonth );
	static Month intToMonth( const size_t month );
	static bool isValidDate( const size_t day, const Month month, const int year );
	static bool isValidDate( const Date &date );

	std::string toString() const;

private:
	size_t day;
	Month month;
	int year;
};

class DateType : public FieldValue
{
public:
	explicit DateType( const std::string &fieldName,
					   const bool optional,
					   const size_t day = 1,
					   const Date::Month month = Date::Month::JAN,
					   const int year = 1900 );
	explicit DateType( const std::string &fieldName, 
					   const bool optional,
					   const Date &date );

	DateType( const DateType& obj );
	DateType& operator=( const DateType& obj );
	~DateType();

	virtual std::string toString() const override;
	virtual bool take( std::string fieldValue ) override;

private:
	Date date;
};

#endif // DATETYPE_H
