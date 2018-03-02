#ifndef CONTRACTMANAGER_H
#define CONTRACTMANAGER_H

#include "contract.h"
#include "parser.h"
#include "periodType.h"

#include <string>
#include <vector>

class ContractManager
{
public:
	static std::string normalize( const std::string &value );
	explicit ContractManager( const std::string &csvFile );

	std::string toString() const;

private:
	void parse( std::ifstream &inFile );

	const std::string csvFile;
	std::vector<Contract> contracts;
	Parser parser;
};

#endif