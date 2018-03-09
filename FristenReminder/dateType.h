#ifndef DATETYPE_H
#define DATETYPE_H

#include <string>
using std::size_t;
using std::string;

class Date
{
	friend class DateParser;

public:
	enum class Month { NONE, JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OKT, NOV, DEC };

	Date( const size_t day = 1,
		  const Date::Month month = Date::Month::JAN,
		  const int year = 1900 );

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

#endif // DATETYPE_H
