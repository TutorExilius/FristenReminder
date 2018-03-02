#ifndef PARSER_H
#define PARSER_H

#include <map>
#include <string>

// Forward-Declarations
class FieldValue;

class Parser
{
public:
	Parser();

	bool parse( const int lineCounter, const std::string &line );

private:
	std::map<std::string, FieldValue*> fields;

};

#endif // PARSER_H