#include "Quote.h"
#include <string>
#include <ctime>  
#include "Garment.h"

Quote::Quote(int id, std::string sellerCode, int quantity, float total, Garment* garment)
{
    this->identificationNumber = id;
    this->sellerCode = sellerCode;
    this->quantity = quantity;
    this->garment = garment;
    this->datetimeCreated = time(0);
    this->quoteResult = total;

}
