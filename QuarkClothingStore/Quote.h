#include <string>
#include <ctime>
#include "Garment.h"
#ifndef QUOTE_H
#define QUOTE_H

class Quote
{
public:
	Quote(int id, std::string sellerCode, int quantity, float total, Garment* garment);
	int getId() { return this->identificationNumber; }
	std::string getSellerCode() { return this->sellerCode; }
	std::string getGarment() { return this->garment->getCompleteDescription(); }
	float getGarmentUnitPrice() { return this->garment->getUnitPrice(); };
	int getQuantity() { return this->quantity; }
	float getQuoteResult() { return this->quoteResult; }
	std::string getDateTime()
	{ 
		struct tm newtime;
		time_t now = this->datetimeCreated;
		localtime_s(&newtime, &now);
		int Month = 1 + newtime.tm_mon;
		int Year = 1900 + newtime.tm_year;
		int Day = newtime.tm_mday;

		std::string aux = std::to_string(Day) + "/" + std::to_string(Month) + "/" + std::to_string(Year);
		return aux;
	}
private:
	int identificationNumber;
	time_t datetimeCreated;
	std::string sellerCode;
	Garment* garment;
	int quantity;
	float quoteResult;
};
#endif







