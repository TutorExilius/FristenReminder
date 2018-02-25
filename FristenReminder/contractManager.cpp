#include "contractManager.h"

#include <algorithm>
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
	Date startDate{ 1, Date::Month::APR,1 };

	std::string basicFeeStr;
	float basicFee = 0.0f;
	std::string currencyCodeStr;

	std::string chargePeriodStr;
	float chargePeriodFloat = 0.0f;
	std::string chargePeriodUnitStr;

	std::string contractDurationStr;
	float contractDurationFloat = 0.0f;
	std::string contractDurationUnitStr;

	std::string cancellationPeriodStr;
	float cancellationPeriodFloat = 0.0f;
	std::string  cancellationPeriodUnitStr;

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

			std::getline( ss, chargePeriodStr, ',' );
			chargePeriodStr = ContractManager::normalize( chargePeriodStr );

			std::getline( ss, contractDurationStr, ',' );
			contractDurationStr = ContractManager::normalize( contractDurationStr );

			std::getline( ss, cancellationPeriodStr, ',' );
			cancellationPeriodStr = ContractManager::normalize( cancellationPeriodStr );

			std::getline( ss, contactDetails, ',' );
			contactDetails = ContractManager::normalize( contactDetails );

			std::getline( ss, note );
			note = ContractManager::normalize( note );

			/*
			std::cout << idStr << std::endl;
			std::cout << partner << std::endl;
			std::cout << startDateStr << std::endl;
			std::cout << basicFeeStr << std::endl;
			std::cout << chargePeriodStr << std::endl;
			std::cout << contractDurationStr << std::endl;
			std::cout << cancellationPeriodStr << std::endl;
			std::cout << contactDetails << std::endl;
			std::cout << note << std::endl;
			*/

			if( lineCounter > 1 )
			{
				std::stringstream tmp;
				tmp << idStr;
				tmp >> id;
				tmp.clear();
				tmp.sync();

				Date startDate{ startDateStr }; // "day.month.yearyear"

				tmp << basicFeeStr;
				tmp >> basicFee;
				tmp >> currencyCodeStr;
				tmp.clear();
				tmp.sync();

				tmp << chargePeriodStr;
				tmp >> chargePeriodFloat;
				tmp >> chargePeriodUnitStr;
				tmp.clear();
				tmp.sync();

				tmp << contractDurationStr;
				tmp >> contractDurationFloat;
				tmp >> contractDurationUnitStr;
				tmp.clear();
				tmp.sync();

				tmp << cancellationPeriodStr;
				tmp >> cancellationPeriodFloat;
				tmp >> cancellationPeriodUnitStr;
				tmp.clear();
				tmp.sync();

				std::transform( currencyCodeStr.begin(), currencyCodeStr.end(), currencyCodeStr.begin(),
						[]( unsigned char c ){ return toupper( c ); } // correct
				);

				Currency currency{ basicFee, currencyCodeStr };
				Period chargePeriod{ chargePeriodFloat, chargePeriodUnitStr };
				Period contractDuration{ contractDurationFloat, contractDurationUnitStr };
				Period cancellationPeriod{ cancellationPeriodFloat, cancellationPeriodUnitStr };

				contracts.emplace_back( Contract{
					id,
					partner,
					startDate,
					currency,
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

std::string ContractManager::toString() const
{
	std::stringstream out;

	for( const auto &contract : this->contracts )
	{
		out << contract.toString() << endl;
	}

	return out.str();
}