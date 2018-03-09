#include "periodParser.h"

PeriodParser::PeriodParser( const bool optional,
                            const Period &value )
: FieldParser<Period> { optional, value }
{
}

bool PeriodParser::take( std::string fieldValue )
{
    std::stringstream ss;
    ss << fieldValue;

    float chargePeriodFloat = 0.0f;
    std::string chargePeriodUnitStr;

    ss >> chargePeriodFloat;
    ss >> chargePeriodUnitStr;

    Period period = { chargePeriodFloat, Period::strToTimeUnit( chargePeriodUnitStr ) };

    if( period.unit == TimeUnit::ERROR )
    {
        return false;
    }
    this->value = period;
    return true;
}
