#ifndef PARSER_H
#define PARSER_H

#include <map>
#include <memory>
#include <string>
#include <vector>

// Forward-Declarations
class Contract;
class FieldValue;

class Parser
{
public:
	Parser();

	std::shared_ptr<Contract> parse( const int lineCounter, const std::string &line );

	const std::vector<std::string>& getFieldOrder() const
	{
		return this->fieldOrder;
	}

private:
	std::map<std::string, FieldValue*> knownFieldValues;
	std::vector<std::string> fieldOrder;
};

#endif // PARSER_H