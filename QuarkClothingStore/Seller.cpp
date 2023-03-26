#include "Seller.h"
#include <string>

Seller::Seller(std::string name, std::string lastName, std::string sellerCode)
{
	this->name = name;
	this->lastName = lastName;
	this->sellerCode = sellerCode;
}

void Seller::addQuote(Quote quote)
{
	this->quoteHistory.push_back(quote);
}