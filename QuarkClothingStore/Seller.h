#include <string>
#include <vector>
#include "Quote.h"
#ifndef SELLER_H
#define SELLER_H

class Seller
{
public:
	Seller(std::string name, std::string lastName, std::string sellerCode);
	void addQuote(Quote quote);
	std::string getName() { return this->name; }
	std::string getSellerCode() { return this->sellerCode; }
	std::string getlastName() { return this->lastName; }
	std::vector<Quote> getQuoteHistory() { return this->quoteHistory; }
private:
	std::string name; 
	std::string lastName;
	std::string sellerCode;
	std::vector<Quote> quoteHistory;
};
#endif
