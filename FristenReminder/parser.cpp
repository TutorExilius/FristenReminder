#include "parser.h"

#include "contract.h"

#include "currencyType.h"
#include "dateType.h"
#include "helper.h"
#include "periodType.h"
#include "stringType.h"

#include <iostream>
#include <sstream>

Parser::Parser()
{
	this->knownFieldValues["name"] = new StringType{ "name", false };
	this->knownFieldValues["beginning"] = new DateType{ "beginning", false };
	this->knownFieldValues["basicFee"] = new CurrencyType{ "basicFee", false };
	this->knownFieldValues["chargePeriod"] = new PeriodType{ "chargePeriod", false };
	this->knownFieldValues["term"] = new PeriodType{ "term", false };
	this->knownFieldValues["noticePeriod"] = new PeriodType{ "noticePeriod", false };
	this->knownFieldValues["comment"] = new StringType{ "comment", true };
	this->knownFieldValues["contactDetails"] = new StringType{ "contactDetails", true };
}

std::shared_ptr<Contract> Parser::parse( const int lineCounter, const std::string &line )
{
	std::shared_ptr<Contract> contract = nullptr;
	
	std::stringstream ss;
	ss << line;

	if( lineCounter > 1 ) // read field-entries
	{
		if( this->fieldOrder.size() == 0 )
		{
			throw "Fieldnames are missing! Read line 1 first!";
		}
		else
		{
			std::string field;
			int valueNumber = 1;

			while( !ss.eof() )
			{
				if( valueNumber < this->knownFieldValues.size() )
				{
					std::getline( ss, field, ',' );
				}
				else
				{
					std::getline( ss, field );
				}
	
				field = Helper::normalize( field );

				const std::string fieldName = this->fieldOrder[valueNumber - 1];

				if( this->knownFieldValues.find( fieldName ) == this->knownFieldValues.end() )
				{
					return nullptr;
				}
				else if( !this->knownFieldValues[fieldName]->take( field ) )
				{
					return nullptr;
				}

				++valueNumber;
			}

			// dynamic_cast need to be checked for nullptr
			contract = std::make_shared<Contract>(
				Contract{ 
						   static_cast<size_t>( lineCounter - 1 ),
						   *( dynamic_cast<StringType*>(this->knownFieldValues["name"])),
						   *( dynamic_cast<DateType*>(this->knownFieldValues["beginning"]) ),
						   *( dynamic_cast<CurrencyType*>(this->knownFieldValues["basicFee"]) ),
						   *( dynamic_cast<PeriodType*>(this->knownFieldValues["chargePeriod"]) ),
						   *( dynamic_cast<PeriodType*>(this->knownFieldValues["term"]) ),
						   *( dynamic_cast<PeriodType*>(this->knownFieldValues["noticePeriod"]) ),
						   *( dynamic_cast<StringType*>(this->knownFieldValues["contactDetails"]) ),
						   *( dynamic_cast<StringType*>(this->knownFieldValues["comment"]) ) 
				}
			);
		}
	}
	else // read field-names
	{
		std::string field;
		int fieldNumber = 1;

		while( !ss.eof() )
		{
			if( fieldNumber < this->knownFieldValues.size() )
			{
				std::getline( ss, field, ',' );
			}
			else
			{
				std::getline( ss, field );
			}

			if( field.size() != 0 )
			{
				field = Helper::normalize( field );
				this->fieldOrder.emplace_back( field );
			}

			++fieldNumber;
		}
	}

	return contract;
}