#ifndef DATE_H
#define DATE_H

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

class Date
{
public:
	enum class Month { NONE, JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OKT, NOV, DEC };

	static Date strToDate( const string &dateStr );
	static size_t monthToInt( const Month enumMonth );
	static Month intToMonth( const size_t month );
	static bool isValidDate( const size_t day, const Month month, const int year );
	static bool Date::isValidDate( const Date &date );

	explicit Date( const size_t day, const Month month, const int year );
	explicit Date( const string &dateStr );

	Date( const Date& obj );
	Date& operator=( const Date& obj );
	~Date();

	std::string toString() const;

private:
	Date() = delete;

	size_t day;
	Month month;
	int year;
};

#endif // DATE_H
