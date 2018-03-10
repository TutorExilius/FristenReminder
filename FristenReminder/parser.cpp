#include "parser.h"

#include "contract.h"

#include "fieldParser.h"
#include "stringParser.h"
#include "currencyParser.h"
#include "dateParser.h"
#include "periodParser.h"
#include "helper.h"

#include <iostream>
#include <sstream>
#include <memory>

namespace {

	ReflectableField<Contract, std::string> NAME = {"name", &Contract::getName};
	ReflectableField<Contract, Date> BEGINNING = {"beginning", &Contract::getBeginning};
	ReflectableField<Contract, CurrencyType> BASICFEE = {"basicFee", &Contract::getBasicFee};
	ReflectableField<Contract, Period> CHARGEPERIOD = {"chargePeriod", &Contract::getChargePeriod};
	ReflectableField<Contract, Period> TERM = {"term", &Contract::getTerm};
	ReflectableField<Contract, Period> NOTICEPERIOD = {"noticePeriod", &Contract::getNoticePeriod};
	ReflectableField<Contract, std::string> COMMENT = {"comment", &Contract::getComment};
	ReflectableField<Contract, std::string> CONTACTDETAILS = {"contactDetails", &Contract::getContactDetails};
}

Parser::Parser()
{
	this->knownFieldValues.put(NAME, std::make_shared<StringParser>(false));;
	this->knownFieldValues.put(BEGINNING, std::make_shared<DateParser>(false));
	this->knownFieldValues.put(BASICFEE,  std::make_shared<CurrencyParser>(false));
	this->knownFieldValues.put(CHARGEPERIOD, std::make_shared<PeriodParser>(false));
	this->knownFieldValues.put(NOTICEPERIOD, std::make_shared<PeriodParser>(false));
	this->knownFieldValues.put(TERM,  std::make_shared<PeriodParser>(false));
	this->knownFieldValues.put(COMMENT, std::make_shared<StringParser>(true));
	this->knownFieldValues.put(CONTACTDETAILS, std::make_shared<StringParser>(true));
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

				if( this->knownFieldValues.find( fieldName ) == nullptr
					|| !this->knownFieldValues.find( fieldName )->take( field ) )
				{
					return nullptr;
				}

				++valueNumber;
			}

			// dynamic_cast need to be checked for nullptr
			contract = std::make_shared<Contract>(
				Contract{ 
						   static_cast<size_t>( lineCounter - 1 ),
						   this->knownFieldValues[NAME],
						   this->knownFieldValues[BEGINNING],
						   this->knownFieldValues[BASICFEE],
						   this->knownFieldValues[CHARGEPERIOD],
						   this->knownFieldValues[TERM],
						   this->knownFieldValues[NOTICEPERIOD],
						   this->knownFieldValues[CONTACTDETAILS],
						   this->knownFieldValues[COMMENT]
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

std::string Parser::print( const Contract& contract ) const
{
	std::stringstream ss;
	auto it = this->getFieldOrder().begin();
	auto end = this->getFieldOrder().end();
	while(it != end)
	{
		const std::string& fieldName = *it;
		
		if(fieldName == NAME.getFieldID()) {
			ss << '"' << NAME.getFieldValue(contract) << '"';
		}
		else if(fieldName == BEGINNING.getFieldID()) {
			ss << '"' << BEGINNING.getFieldValue(contract).toString() << '"';
		}
		else if(fieldName == BASICFEE.getFieldID()) {
			ss << '"' << BASICFEE.getFieldValue(contract).toString() << '"';
		}
		else if(fieldName == CHARGEPERIOD.getFieldID()) {
			ss << '"' << CHARGEPERIOD.getFieldValue(contract).toString() << '"';
		}
		else if(fieldName == TERM.getFieldID()) {
			ss << '"' << TERM.getFieldValue(contract).toString() << '"';
		}
		else if(fieldName == NOTICEPERIOD.getFieldID()) {
			ss << '"' << NOTICEPERIOD.getFieldValue(contract).toString() << '"';
		}
		else if(fieldName == COMMENT.getFieldID()) {
			ss << '"' << COMMENT.getFieldValue(contract) << '"';
		}
		else if(fieldName == CONTACTDETAILS.getFieldID()) {
			ss << '"' << CONTACTDETAILS.getFieldValue(contract) << '"';
		}

		++it;
		if(it != end) {
			ss << ',';
		}
	}

	return ss.str();
}
