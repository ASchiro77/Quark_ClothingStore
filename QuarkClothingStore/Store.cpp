#include "Store.h"
#include <string>

Store::Store(std::string name, std::string address, std::vector<Garment*> list)
{
	this->name = name;
	this->address = address;
	this->garmentList = list;
}

int Store::getStock(std::string garmentCode)
{
	std::string aux = "";
	for (auto& item : this->garmentList)
	{
		aux = item->getGarmentCode();
		if(aux == garmentCode) {
			return  item->getStock();
		}
	}

	return 0;
}

void Store::discountStock(std::string garmentCode,int quantity)
{
	for (auto& item : this->garmentList)
	{
		if (item->getGarmentCode() == garmentCode) {
			item->setStock(item->getStock() - quantity);
		}
	}

}