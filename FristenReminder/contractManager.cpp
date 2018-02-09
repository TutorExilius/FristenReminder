#include "contractManager.h"

#include <fstream>
#include <iostream>
#include <sstream>

std::string ContractManager::normalize( const std::string &value )
{
	std::string tmp = value;

	int fromPos = tmp.find_first_of( '"' );
	int toPos = tmp.find_last_of( '"' );

	if( fromPos != std::string::npos &&
		toPos != std::string::npos &&
		fromPos < toPos )
	{
		int n = value.size() - ( value.size() - toPos ) - fromPos;
		tmp = value.substr( fromPos + 1, n - 1 );
	}

	return tmp;
}

ContractManager::ContractManager( const std::string &csvFile )
: csvFile{ csvFile }
{
	std::ifstream inFile{ csvFile };
	

	if( !inFile )
	{
	//	Log{ "File could not opened" };
		throw std::string{ "Could not open File: " + csvFile };
	}

	try
	{
		this->parse( inFile );
	}
	catch( ... )
	{
		std::cerr << "Error while parsing" << std::endl;
	}

	inFile.close();
}

void ContractManager::parse( std::ifstream &inFile )
{
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

		std::getline( inFile, line );

		if( line.size() > 0 )
		{
			std::stringstream ss;
			ss << line;

			std::getline( ss, idStr, ',' );
			idStr = ContractManager::normalize( idStr );

			std::getline( ss, partner, ',' );
			partner = ContractManager::normalize( partner );

			std::getline( ss, startDateStr, ',' );
			startDateStr = ContractManager::normalize( startDateStr );

			std::getline( ss, basicFeeStr, ',' );
			basicFeeStr = ContractManager::normalize( basicFeeStr );

			std::getline( ss, chargePeriod, ',' );
			chargePeriod = ContractManager::normalize( chargePeriod );

			std::getline( ss, contractDuration, ',' );
			contractDuration = ContractManager::normalize( contractDuration );

			std::getline( ss, cancellationPeriod, ',' );
			cancellationPeriod = ContractManager::normalize( cancellationPeriod );

			std::getline( ss, contactDetails, ',' );
			contactDetails = ContractManager::normalize( contactDetails );

			std::getline( ss, note );
			note = ContractManager::normalize( note );

			std::cout << idStr << std::endl;
			std::cout << partner << std::endl;
			std::cout << startDateStr << std::endl;
			std::cout << basicFeeStr << std::endl;
			std::cout << chargePeriod << std::endl;
			std::cout << contractDuration << std::endl;
			std::cout << cancellationPeriod << std::endl;
			std::cout << contactDetails << std::endl;
			std::cout << note << std::endl;

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
}