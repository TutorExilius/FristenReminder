#include "contract.h"

#include <clocale>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

int main( int argc, char *argv[]  )
{
	std::setlocale( LC_ALL, "" );

	std::ifstream inFile{ "../testdaten.csv" };

	if( !inFile )
	{
		std::cerr << "File could not opened" << std::endl;
		return -1;
	}

	std::vector<Contract> contracts;

	std::string idStr;
	size_t id = 0;

	std::string partner;

	std::string startDateStr;
	Date startDate;

	std::string basicFeeStr;
	float basicFee = 0.0f;

	std::string chargePeriod;

	std::string contractDuration;

	std::string cancellationPeriod;

	std::string contactDetails;	

	std::string note;

	size_t lineCounter = 0;
	std::string line;
	while( !inFile.eof() )
	{
		++lineCounter;

		getline( inFile, line );

		if( line.size() > 0 )
		{
			std::stringstream ss;
			ss << line;

			getline( ss, idStr, ',' );
			idStr = idStr.substr( 1, idStr.size() - 2 );

			getline( ss, partner, ',' );
			partner = partner.substr( 1, partner.size() - 2 );

			getline( ss, startDateStr, ',' );
			startDateStr = startDateStr.substr( 1, startDateStr.size() - 2 );

			getline( ss, basicFeeStr, ',' );
			basicFeeStr = basicFeeStr.substr( 1, basicFeeStr.size() - 2 );

			getline( ss, chargePeriod, ',' );
			chargePeriod = chargePeriod.substr( 1, chargePeriod.size() - 2 );

			getline( ss, contractDuration, ',' );
			contractDuration = contractDuration.substr( 1, contractDuration.size() - 2 );

			getline( ss, cancellationPeriod, ',' );
			cancellationPeriod = cancellationPeriod.substr( 1, cancellationPeriod.size() - 2 );

			getline( ss, contactDetails, ',' );
			contactDetails = contactDetails.substr( 1, contactDetails.size() - 2 );

			getline( ss, note );
			note = note.substr( 1, note.size() - 2 );
			/*
			std::cout << idStr << std::endl;
			std::cout << partner << std::endl;
			std::cout << startDateStr << std::endl;
			std::cout << basicFeeStr << std::endl;
			std::cout << chargePeriod << std::endl;
			std::cout << contractDuration << std::endl;
			std::cout << cancellationPeriod << std::endl;
			std::cout << contactDetails << std::endl;
			std::cout << note << std::endl;
			*/

			if( lineCounter > 1 )
			{
				std::stringstream tmp;
				tmp << idStr;
				tmp >> id;

				tmp << basicFeeStr;
				tmp >> basicFee;

				contracts.emplace_back( Contract{
					id,
					partner,
					startDate,
					basicFee,
					chargePeriod,
					contractDuration,
					cancellationPeriod,
					contactDetails,
					note
				} );
			}
		}
	}

	inFile.close();

	std::cout << "countContracts: " << contracts.size() << std::endl;
	

	system( "PAUSE" );
	return 0;
}