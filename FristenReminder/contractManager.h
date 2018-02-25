#ifndef CONTRACTMANAGER_H
#define CONTRACTMANAGER_H

#include <string>
#include <vector>

#include "contract.h"
#include "period.h"

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
};

#endif