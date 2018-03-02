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

	std::string name;

	std::string beginningStr;
	Date beginning{ 1, Date::Month::APR,1 };

	std::string basicFeeStr;
	float basicFee = 0.0f;
	std::string currencyCodeStr;

	std::string chargePeriodStr;
	float chargePeriodFloat = 0.0f;
	std::string chargePeriodUnitStr;

	std::string termStr;
	float termFloat = 0.0f;
	std::string termUnitStr;

	std::string cancellationPeriodStr;
	float cancellationPeriodFloat = 0.0f;
	std::string  cancellationPeriodUnitStr;

	std::string contactDetails;

	std::string comment;

	size_t lineCounter = 0;

	std::string line;
	while( !inFile.eof() )
	{
		++lineCounter;

		std::getline( inFile, line );

		if( line.size() > 0 )
		{
			this->parser.parse( lineCounter, line );
			/*
			std::stringstream ss;
			ss << line;

			std::getline( ss, idStr, ',' );
			idStr = ContractManager::normalize( idStr );

			std::getline( ss, name, ',' );
			name = ContractManager::normalize( name );

			std::getline( ss, beginningStr, ',' );
			beginningStr = ContractManager::normalize( beginningStr );

			std::getline( ss, basicFeeStr, ',' );
			basicFeeStr = ContractManager::normalize( basicFeeStr );

			std::getline( ss, chargePeriodStr, ',' );
			chargePeriodStr = ContractManager::normalize( chargePeriodStr );

			std::getline( ss, termStr, ',' );
			termStr = ContractManager::normalize( termStr );

			std::getline( ss, cancellationPeriodStr, ',' );
			cancellationPeriodStr = ContractManager::normalize( cancellationPeriodStr );

			std::getline( ss, contactDetails, ',' );
			contactDetails = ContractManager::normalize( contactDetails );

			std::getline( ss, comment );
			comment = ContractManager::normalize( comment );

			if( lineCounter > 1 )
			{
				std::stringstream tmp;
				tmp << idStr;
				tmp >> id;
				tmp.clear();
				tmp.sync();

				Date startDate{ beginningStr }; // "day.month.yearyear"

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

				tmp << termStr;
				tmp >> termFloat;
				tmp >> termUnitStr;
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
				Period contractDuration{ termFloat, termUnitStr };
				Period cancellationPeriod{ cancellationPeriodFloat, cancellationPeriodUnitStr };

				contracts.emplace_back( Contract{
					id,
					name,
					startDate,
					currency,
					chargePeriod,
					contractDuration,
					cancellationPeriod,
					contactDetails,
					comment
				} );
			}
			*/
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