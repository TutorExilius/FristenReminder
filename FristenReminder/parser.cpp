#include "parser.h"

#include "contract.h"

#include "currencyType.h"
#include "dateType.h"
#include "helper.h"
#include "periodType.h"
#include "stringType.h"

#include <iostream>
#include <sstream>
#include <vector>

Parser::Parser()
{
	this->knownFieldValues[Contract::NAME] = new StringType{ Contract::NAME, false };
	this->knownFieldValues[Contract::BEGINNING] = new DateType{ Contract::BEGINNING, false };
	this->knownFieldValues[Contract::BASIC_FEE] = new CurrencyType{ Contract::BASIC_FEE, false };
	this->knownFieldValues[Contract::CHARGE_PERIOD] = new PeriodType{ Contract::CHARGE_PERIOD, false };
	this->knownFieldValues[Contract::INITIAL_TERM] = new PeriodType{ Contract::INITIAL_TERM, false };
	this->knownFieldValues[Contract::RENEWAL_TERM] = new PeriodType{ Contract::RENEWAL_TERM, false };
	this->knownFieldValues[Contract::NOTICE_PERIOD] = new PeriodType{ Contract::NOTICE_PERIOD, false };
	this->knownFieldValues[Contract::COMMENT] = new StringType{ Contract::COMMENT, true };
	this->knownFieldValues[Contract::CONTACT_DETAILS] = new StringType{ Contract::CONTACT_DETAILS, true };
}

std::shared_ptr<Contract> Parser::parse( const int lineCounter, const std::string &line )
{
	std::shared_ptr<Contract> contract = nullptr;

	std::stringstream ss;
	ss << line;

	std::vector<string> commaSeperatedValues = Helper::splitStringToVector( line, ',' );

	if( !(this->hasValidDataStructures( commaSeperatedValues )) )
	{
		return nullptr;
	}

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

			for (const auto &val : commaSeperatedValues)
			{
				const std::string fieldName = this->fieldOrder[valueNumber - 1];

				if( this->knownFieldValues.count(fieldName) > 0 )
				{
					if (!this->knownFieldValues[fieldName]->take(
						Helper::normalize(Helper::trim(val))))
					{
						return nullptr;
					}
				}
				else
				{
					throw "Unknown Field-Name '" + fieldName + "'";
				}

				++valueNumber;				
			} 
			/*
			
			std::string field;
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
			*/
			// dynamic_cast need to be checked for nullptr
			contract = std::make_shared<Contract>(
				Contract{ 
						   static_cast<size_t>( lineCounter - 1 ),
						   *( dynamic_cast<StringType*>(this->knownFieldValues[Contract::NAME])),
						   *( dynamic_cast<DateType*>(this->knownFieldValues[Contract::BEGINNING]) ),
						   *( dynamic_cast<CurrencyType*>(this->knownFieldValues[Contract::BASIC_FEE]) ),
						   *( dynamic_cast<PeriodType*>(this->knownFieldValues[Contract::CHARGE_PERIOD]) ),
						   *( dynamic_cast<PeriodType*>(this->knownFieldValues[Contract::INITIAL_TERM]) ),
						   *( dynamic_cast<PeriodType*>(this->knownFieldValues[Contract::RENEWAL_TERM])),
						   *( dynamic_cast<PeriodType*>(this->knownFieldValues[Contract::NOTICE_PERIOD]) ),
						   *( dynamic_cast<StringType*>(this->knownFieldValues[Contract::CONTACT_DETAILS]) ),
						   *( dynamic_cast<StringType*>(this->knownFieldValues[Contract::COMMENT]) ) 
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

bool Parser::hasValidDataStructures( const std::vector<std::string> &values ) const
{
	for( const auto &value : values )
	{
		std::string val = Helper::trim( value );

		if( val.size() == 0 || val[0] == '"' && val[val.size() - 1] == '"' )
		{
			val = val.erase( val.size() - 1, 1 );
			val = val.erase( 0, 1 );

			size_t quotePos = val.find( '"' );
			while( quotePos != std::string::npos )
			{
				if( val[quotePos - 1] != '\\' )
				{
					return false;
				}
				
				val = val.substr( quotePos + 1 );
				quotePos = val.find( '"' );
			}
		}
		else
		{
			return false;
		}
	}

	return true;
}
