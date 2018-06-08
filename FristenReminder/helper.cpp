#include "helper.h"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

namespace Helper
{
	/*
	 *
	 *
	 */
	std::string normalize( const std::string &value )
	{
		std::string tmp = value;

		size_t fromPos = tmp.find_first_of( '"' );
		size_t toPos = tmp.find_last_of( '"' );

		if( fromPos != std::string::npos &&
			toPos != std::string::npos &&
			fromPos < toPos )
		{
			int n = value.size() - ( value.size() - toPos ) - fromPos;
			tmp = value.substr( fromPos + 1, n - 1 );
		}

		return tmp;
	}

	std::string toUpper( const std::string &str )
	{
		std::string strToUpper = str;

		std::transform( str.begin(), str.end(), strToUpper.begin(),
						[]( unsigned char c ){ return toupper( c ); } // correct
		);

		return strToUpper;
	}

	void clearScreen()
	{
		system( "CLS" );
	}

	void pauseSreen()
	{
		system( "PAUSE" );
	}

	std::string replace( std::string str, const char oldChar, const char newChar )
	{
		for( int i = 0; i < str.size(); i++ )
		{
			if( str[i] == oldChar )
			{
				str[i] = newChar;
			}
		}

		return str;
	}

	std::vector<std::string> splitStringToVector( const std::string &line, const char seperator )
	{
		std::vector<std::string> splitted;

		std::stringstream ss;
		ss << line;

		std::string splittedString;

		while( std::getline( ss, splittedString, seperator ) )
		{
			splitted.push_back( splittedString );
		}

		return splitted;
	}

	std::string trim( const std::string &value )
	{
		std::string copy = value;
		
		// trimBegin
		int pos = copy.find_first_not_of( " \t\n\v\f\r" );
		if( pos > 0 )
		{
			copy = copy.erase( 0, pos );
		}

		// trimEnd
		pos = copy.find_last_not_of( " \t\n\v\f\r" );
		if( pos != std::string::npos )
		{
			copy = copy.erase( pos + 1 );
		}
	
		return copy;
	}
}