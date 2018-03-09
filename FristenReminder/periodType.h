#ifndef PERIODTYPE_H
#define PERIODTYPE_H

#include "fieldValue.h"

#include <string>
#include <sstream>

enum class TimeUnit{ ERROR, D, W, M, Y };

struct PeriodType : public FieldValue
{
	static TimeUnit strToTimeUnit( const std::string &timeUnitStr )
	{
		if( timeUnitStr == "D" )
			return TimeUnit::D;
		else if( timeUnitStr == "W" )
			return TimeUnit::W;
		else if( timeUnitStr == "M" )
			return TimeUnit::M;
		else if( timeUnitStr == "Y" )
			return TimeUnit::Y;
		else
			return TimeUnit::ERROR;
	}

	static std::string timeUnitToString( const TimeUnit &timeUnit )
	{
		switch( timeUnit )
		{
			case TimeUnit::D: return "D";
			case TimeUnit::W: return "W";
			case TimeUnit::M: return "M";
			case TimeUnit::Y: return "Y";

			case TimeUnit::ERROR:
			default: return "ERROR";
		}
	}

	PeriodType( const std::string &fieldName,
				const bool optional,
				const float &value = 0.0f,
				const TimeUnit &timeUnit = TimeUnit::M )
	: FieldValue{ fieldName, optional }
	, value{ value }
	, unit{ timeUnit }
	{
	}

	PeriodType( const std::string &fieldName,
				const bool optional, 
				const float &value, 
				const std::string &timeUnitStr )
	: PeriodType{ fieldName, optional, 
		value, PeriodType::strToTimeUnit( timeUnitStr ) }
	{
	}

	virtual std::string toString() const override
	{
		std::stringstream out;

		out << this->value << ' ' << PeriodType::timeUnitToString( this->unit );

		return out.str();
	}

	virtual bool take( std::string fieldValue ) override
	{
		std::stringstream ss;
		ss << fieldValue;

		float chargePeriodFloat = 0.0f;
		std::string chargePeriodUnitStr;

		ss >> chargePeriodFloat;
		ss >> chargePeriodUnitStr;

		this->value = chargePeriodFloat;
		this->unit = this->strToTimeUnit( chargePeriodUnitStr );

		if( this->unit != TimeUnit::ERROR )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	float value;
	TimeUnit unit;
};

#endif // PERIODTYPE_H
