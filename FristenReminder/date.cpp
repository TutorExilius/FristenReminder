#include "date.h"

#include <sstream>
using std::stringstream;

Date Date::strToDate( const string &dateStr )
{
	stringstream ss;

	ss << dateStr;

	size_t day = 0;
	size_t month = 0;
	int year = 0;

	char tmp;

	ss >> day >> tmp >> month >> tmp >> year;

	if( ss.eof() && Date::isValidDate( day, Date::intToMonth( month ), year ) )
	{
		return Date{ day, Date::intToMonth(month), year };
	}
	else
	{
		throw "Invalid Date Format";
	}	
}

size_t Date::monthToInt( const Month month )
{
	switch( month )
	{
		case Month::JAN: return 1;
		case Month::FEB: return 2;
		case Month::MAR: return 3;
		case Month::APR: return 4;
		case Month::MAY: return 5;
		case Month::JUN: return 6;
		case Month::JUL: return 7;
		case Month::AUG: return 8;
		case Month::SEP: return 9;
		case Month::OKT: return 10;
		case Month::NOV: return 11;
		case Month::DEC: return 12;

		case Month::NONE:
		default:		 return 0;
	}
}

Date::Month Date::intToMonth( const size_t month )
{
	switch( month )
	{
		case 1: return Month::JAN;
		case 2: return Month::FEB;
		case 3: return Month::MAR;
		case 4: return Month::APR;
		case 5: return Month::MAY;
		case 6: return Month::JUN;
		case 7: return Month::JUL;
		case 8: return Month::AUG;
		case 9: return Month::SEP;
		case 10: return Month::OKT;
		case 11: return Month::NOV;
		case 12: return Month::DEC;

		default: return Month::NONE;
	}
}

bool Date::isValidDate( const size_t day, const Month enumMonth, const int year )
{
	size_t month = Date::monthToInt( enumMonth );

	//check month
	if( month >= 1 && month <= 12 )
	{
		//check days
		if( ( day >= 1 && day <= 31 ) && ( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 ) )
			return true;
		else if( ( day >= 1 && day <= 30 ) && ( month == 4 || month == 6 || month == 9 || month == 11 ) )
			return true;
		else if( ( day >= 1 && day <= 28 ) && ( month == 2 ) )
			return true;
		else if( day == 29 && month == 2 && ( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) ) )
			return true;
		else
			return false;
	}
	else
	{
		return false;
	}
}

bool Date::isValidDate( const Date &date )
{
	return Date::isValidDate( date.day, date.month, date.year );
}

Date::Date( const size_t day, const Month month, const int year )
: day{ day }
, month{ month }
, year{ year } 
{
	if( !Date::isValidDate( *this ) )
	{
		throw "Invalid Date Format";
	}
}

Date::Date( const string &dateStr )
{
	*this = Date::strToDate( dateStr );
}

Date::Date( const Date& obj )
: Date{ obj.day, obj.month, obj.year }
{
}

Date& Date::operator=( const Date& obj )
{
	this->day = obj.day;
	this->month = obj.month;
	this->year = obj.year;

	return *this;
}


Date::~Date()
{
}
