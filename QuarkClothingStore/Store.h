#include <string>
#include <vector>
#include "Garment.h"

#ifndef STORE_H
#define STORE_H

class Store
{
public:
	Store(std::string name, std::string address, std::vector<Garment*> list);
	std::string getName() { return this->name; }
	std::string getAddress() { return this->address; }
	std::vector<Garment*> getList() { return this->garmentList; }
	int getStock(std::string garmentCode);
	void discountStock(std::string garmentCode, int quantity);
private:
	std::string name;
	std::string address;
	std::vector<Garment*> garmentList;
};
#endif

