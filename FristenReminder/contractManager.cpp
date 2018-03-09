#include "contractManager.h"

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>

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
	size_t lineCounter = 0;

	std::string line;
	while( !inFile.eof() )
	{
		++lineCounter;

		std::getline( inFile, line );

		if( line.size() > 0 )
		{
			std::shared_ptr<Contract> contract = this->parser.parse( lineCounter, line );
			
			if( contract != nullptr )
			{
				this->contracts.emplace_back( *contract );
			}

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