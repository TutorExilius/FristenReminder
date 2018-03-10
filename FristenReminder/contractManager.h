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
	explicit ContractManager( const std::string &csvFile );

	void start();

private:
	std::string toString() const;
	void parse( std::ifstream &inFile );
	void printMenu() const;
	void handleMenuPoint( const int menuPoint );

	// Menu-Funcitons
	void listAllEntries() const;
	void save() const;

	const std::string csvFile;
	std::vector<Contract> contracts;
	Parser parser;
};

#endif