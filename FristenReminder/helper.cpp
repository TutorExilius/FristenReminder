#include "helper.h"

#include <algorithm>

namespace Helper
{
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
}