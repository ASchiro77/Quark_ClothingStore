#pragma once
#include <string>
#include "Quality.h"
#ifndef GARMENT_H
#define GARMENT_H

class Garment
{
public:
	int getStock() { return this->stock; }
	void setStock(int stock) { this->stock = stock; }
	float getUnitPrice() { return this->unitPrice; }
	std::string getName() { return this->name; }
	virtual const std::string GetDesc() = 0;
	virtual const std::string GetCode() = 0;

	std::string getCompleteDescription()
	{
		return this->GetDesc() + " - " + this->quality.getDescription();
	};

	std::string getGarmentCode()
	{
		return this->GetCode() + this->quality.getDescription();
	};

protected:
	Quality quality;
	int stock = 0;
	float unitPrice = 0;
	std::string name;
};
#endif



