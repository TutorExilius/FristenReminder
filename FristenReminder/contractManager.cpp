#include "contractManager.h"

#include "helper.h"
#include "currencyType.h"
#include "dateType.h"
#include "periodType.h"

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
using std::endl;

ContractManager::ContractManager( const std::string &csvFile )
: csvFile{ csvFile }
{
	std::ifstream inFile{ this->csvFile };
	
	if( !inFile )
	{
	//	Log{ "File could not opened" };
		throw std::string{ "Could not open File: " + this->csvFile };
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
	int lineCounter = 0;

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

void ContractManager::start()
{
	int menuePoint = 0;

	do
	{
		Helper::clearScreen();

		this->printMenu();

		std::cout << "\nYour choice: ";
		std::cin >> menuePoint;

		std::cout << std::endl;

		this->handleMenuPoint( menuePoint );

		Helper::pauseSreen();

	} while( menuePoint != 0 );
}

void ContractManager::printMenu() const
{
	std::cout << "1. List all Entries" << std::endl;
	std::cout << "2. Save" << std::endl;
}

void ContractManager::handleMenuPoint( const int menuPoint )
{
	switch( menuPoint )
	{
		case 1:
			this->listAllEntries();
			break;

		case 2: this->save();
			break;

		default:
			std::cout << "Menu-Point is unknown" << std::endl;

	}
}

void ContractManager::listAllEntries() const
{
	std::cout << this->toString();
}

void ContractManager::save() const
{
	std::ofstream outFile( this->csvFile, std::ios::trunc );

	if( !outFile )
	{
		throw "Coult not open *" + this->csvFile + "' to save.";
	}

	// Fieldnames
	// Contract-Values
	for( int i = 0; i < this->parser.getFieldOrder().size(); i++ )
	{
		outFile << '"' << this->parser.getFieldOrder().at( i ) << '"';

		if( i < this->parser.getFieldOrder().size() - 1 )
		{
			outFile << ',';
		}
	}

	for( auto& contract : this->contracts )
	{
		outFile << '\n' << this->parser.print(contract);
	}

	outFile.flush();
	outFile.close();
}

std::string ContractManager::getFieldValue( const Contract &contract, const std::string &fieldValue ) const
{
	if( fieldValue == "name" )
	{
		return contract.getName();
	}
	else if( fieldValue == "beginning" )
	{
		return contract.getBeginning().toString();
	}
	else if( fieldValue == "basicFee" )
	{
		return contract.getBasicFee().toString();
	}
	else if( fieldValue == "chargePeriod" )
	{
		return contract.getChargePeriod().toString();
	}
	else if( fieldValue == "term" )
	{
		return contract.getTerm().toString();
	}
	else if( fieldValue == "noticePeriod" )
	{
		return contract.getNoticePeriod().toString();
	}
	else if( fieldValue == "comment" )
	{
		return contract.getComment();
	}
	else if( fieldValue == "contactDetails" )
	{
		return contract.getContactDetails();
	}
	else
	{
		return "ERROR";
	}
}
