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
	int getStock(int garmentType, bool shortSleeve, bool maoNeck, bool slim, int qualityType);
	void discountStock(int garmentType, bool shortSleeve, bool maoNeck, bool slim, int qualityType, int quantity);
private:
	std::string name;
	std::string address;
	std::vector<Garment*> garmentList;
	std::string buildGarmentCode(int garmentType, bool shortSleeve, bool maoNeck, bool slim, int qualityType);
};
#endif

