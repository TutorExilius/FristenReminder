#include <clocale>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <regex>
#include <iostream>

#include "dateType.h"
#include "contractManager.h"

int main( int argc, char *argv[] )
{
	try
	{
		ContractManager contractManager{ "../testdaten.csv" };

		std::cout << contractManager.toString() << std::endl;
		std::cin.get();
	}
	catch( const std::string &error )
	{
		std::cerr << "Exception: " << error << std::endl;
		return -1;
	}
	catch( const char *error )
	{
		std::cerr << "Exception: " << error << std::endl;
		return -1;
	}
	catch( ... )
	{
		std::cerr << "Exception: " << "Unhandled Exception" << std::endl;
		return -1;
	}

	return 0;
}