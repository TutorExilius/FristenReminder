#ifndef PERIODTYPE_H
#define PERIODTYPE_H

#include <string>
#include <sstream>

enum class TimeUnit{ ERROR, D, W, M, Y };

struct Period
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

	Period( const float &value = 0.0f,
				const TimeUnit &timeUnit = TimeUnit::M )
	: value{ value }
	, unit{ timeUnit }
	{
	}

	Period( const float &value, 
				const std::string &timeUnitStr )
	: Period{ value, Period::strToTimeUnit( timeUnitStr ) }
	{
	}

	std::string toString() const
	{
		std::stringstream out;

		out << this->value << ' ' << Period::timeUnitToString( this->unit );

		return out.str();
	}

	float value;
	TimeUnit unit;
};

#endif // PERIODTYPE_H
