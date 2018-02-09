#include <clocale>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <regex>

#include "contractManager.h"

int main( int argc, char *argv[] )
{
	try
	{
		std::setlocale( LC_ALL, "" );
		ContractManager contractManager{ "../testdaten.csv" };
	}
	catch( const std::string &error )
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