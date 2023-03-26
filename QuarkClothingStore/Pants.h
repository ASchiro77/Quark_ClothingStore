#pragma once
#ifndef PANTS_H
#define PANTS_H

#include "Garment.h"

class Pants : public Garment
{
public:
	Pants(bool s, int stock, float price, int quality)
	{
		this->slim = s;
		this->stock = stock;
		this->unitPrice = price;
		this->quality = Quality(quality);
		this->name = "Pantalón";
	};

	const std::string GetDesc() override
	{ 
		std::string aux = this->name; 
		if (slim) {
			aux = aux + " - " + "Chupín";
		}
		return  aux;
	}

	const std::string GetCode() override
	{
		std::string aux = "P";
		if (slim) {
			aux += "S";
		}
		return  aux;
	}

private:
	bool slim;
};
#endif

