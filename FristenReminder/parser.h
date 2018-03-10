#ifndef PARSER_H
#define PARSER_H

#include <memory>
#include <string>
#include <vector>
#include "fieldDict.h"

// Forward-Declarations
class Contract;
class FieldValue;

class Parser
{
public:
	Parser();

	std::shared_ptr<Contract> parse( const int lineCounter, const std::string &line );
	std::string print( const Contract& contract ) const;

	const std::vector<std::string>& getFieldOrder() const
	{
		return this->fieldOrder;
	}

private:
	FieldDict knownFieldValues;
	std::vector<std::string> fieldOrder;
};

#endif // PARSER_H