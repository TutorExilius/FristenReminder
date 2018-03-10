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
	setlocale( LC_ALL, "de_DE.UTF-8" ); 
	std::cin.imbue( std::locale( "de_DE.UTF-8" ) );
	std::cout.imbue( std::locale( "de_DE.UTF-8" ) );
	ContractManager contractManager{ "../testdaten.csv" };

	contractManager.start();

	return 0;
}