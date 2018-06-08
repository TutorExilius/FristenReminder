#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <regex>
#include <iostream>

#include "dateType.h"
#include "contractManager.h"
#include "helper.h"

int main( int argc, char *argv[] )
{
	try
	{
		setlocale( LC_ALL, "German" ); 
		std::cin.imbue( std::locale( "german" ) );
		std::cout.imbue( std::locale( "german" ) );

		ContractManager contractManager{ "../testdaten.csv" };
		contractManager.start();

		Helper::pauseSreen();
	}
	catch( const std::string &error )
	{
		std::cerr << "Exception: " << error << std::endl;
		
		Helper::pauseSreen();

		return -1;
	}
	catch( const char *error )
	{
		std::cerr << "Exception: " << error << std::endl;

		Helper::pauseSreen();

		return -1;
	}
	catch( ... )
	{
		std::cerr << "Exception: " << "Unhandled Exception" << std::endl;

		Helper::pauseSreen();

		return -1;
	}

	return 0;
}