#ifndef HELPER_H
#define HELPER_H

#include <string>

namespace Helper
{
	std::string normalize( const std::string &value );
	std::string toUpper( const std::string &str );
	void clearScreen();
	void pauseSreen();
	std::string replace( std::string str, const char oldChar, const char newChar );
};

#endif // HELPER_H