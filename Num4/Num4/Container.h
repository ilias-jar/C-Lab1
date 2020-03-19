#pragma once

#include <iostream>
#include <fstream>
#include <list>

class Container {

public:
	std::ifstream* f_curr;
	std::list<double>* l_curr;
	bool isFilledFile;
	bool isFilledList;

	Container() : isFilledFile(false), isFilledList(false), f_curr(NULL), l_curr(NULL) {
	}

	std::ifstream& GenerateRandomFileLoop(const std::string fileName, const int M, const int count) const;

	std::ifstream& GenerateRandomFile(const std::string fileName, const int M, const int count) const;

	std::list<double>* FillListFromFile(std::ifstream& file) const;

	std::list<double>* ModifyContainer(std::list<double>& originList);

	std::list<double>* ModifyContainer( std::list<double>& originList,
		std::list<double>::iterator& begin,
		std::list<double>::iterator& end);

	std::list<double>* ModifyContainerTransform(std::list<double>& originList);

	std::list<double>* ModifyContainerFor_Each(std::list<double>& originList,
		std::list<double>::iterator& begin,
		std::list<double>::iterator& end);

	double Sum(const std::list<double>& List) const;

	double MidArifm(const std::list<double>& List) const;

	void Print(std::string fileName = "") const;
	
};