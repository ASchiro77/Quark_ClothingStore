#include "Store.h"
#include <string>

Store::Store(std::string name, std::string address, std::vector<Garment*> list)
{
	this->name = name;
	this->address = address;
	this->garmentList = list;
}

int Store::getStock(int garmentType, bool shortSleeve, bool maoNeck, bool slim, int qualityType)
{
	std::string garmentCode = this->buildGarmentCode(garmentType,shortSleeve,maoNeck,slim,qualityType);
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

void Store::discountStock(int garmentType, bool shortSleeve, bool maoNeck, bool slim, int qualityType,int quantity)
{
	std::string garmentCode = this->buildGarmentCode(garmentType, shortSleeve, maoNeck, slim, qualityType);
	for (auto& item : this->garmentList)
	{
		if (item->getGarmentCode() == garmentCode) {
			item->setStock(item->getStock() - quantity);
		}
	}

}

std::string Store::buildGarmentCode(int garmentType, bool shortSleeve, bool maoNeck, bool slim, int qualityType) {
	std::string aux = "";
	if (garmentType == 1) {
		aux += "S";
		if (shortSleeve) { aux += "S"; }
		if (maoNeck) { aux += "M"; }
	}
	else {
		aux += "P";
		if (slim) { aux += "S"; }
	}

	if (qualityType == 1) {
		aux += STANDARD_DESCRIPTION;
	}
	else {
		aux += PREMIUM_DESCRIPTION;
	}

	return aux;
};