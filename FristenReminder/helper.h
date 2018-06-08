#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <vector>

namespace Helper
{
	std::string normalize( const std::string &value );
	std::string toUpper( const std::string &str );
	void clearScreen();
	void pauseSreen();
	std::string replace( std::string str, const char oldChar, const char newChar );
	std::vector<std::string> splitStringToVector( const std::string &line, const char seperator );
	std::string trim( const std::string &value );
};

#endif // HELPER_H