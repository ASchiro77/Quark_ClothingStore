#include "Seller.h"
#include "Shirt.h"
#include "Pants.h"
#include <string>

Seller::Seller(std::string name, std::string lastName, std::string sellerCode)
{
	this->name = name;
	this->lastName = lastName;
	this->sellerCode = sellerCode;
}

void Seller::addQuote(int garmentType, bool shortSleeve, bool maoNeck, bool slim, int qualityType, float unitPrice, int quantity) 
{
	Garment* g;
	if (garmentType == 1) {
		g = new Shirt(shortSleeve, maoNeck, quantity, unitPrice, qualityType);
	}
	else {
		g = new Pants(slim, quantity, unitPrice, qualityType);
	}

	float total = quantity * unitPrice;

	if (shortSleeve) {
		total = total - (total * 0.1); //- 10%
	}

	if (maoNeck) {
		total = total + (total * 0.03); // + 3%
	}

	if (slim) {
		total = total - (total * 0.12); // -12%
	}

	if (qualityType == 1) {
		total = total + (total * 0.3); // + 30%
	}
	int idQuote = this->quoteHistory.size() + 1;;
	Quote quote = Quote(idQuote, this->sellerCode, quantity, total, g);
	this->quoteHistory.push_back(quote);
}