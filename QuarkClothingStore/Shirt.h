#pragma once
#ifndef SHIRT_H
#define SHIRT_H

#include "Garment.h"

class Shirt : public Garment
{
public:
	Shirt(bool ss, bool mn, int s, float price, int quality) 
	{
		 this->shortSleeve = ss; 
		 this->maoNeck = mn; 
		 this->stock = s; 
		 this->unitPrice = price;
		 this->quality = Quality(quality);
		 this->name = "Camisa";
	};

	const std::string GetDesc() override
	{
		std::string aux = this->name;
		if (shortSleeve) {
			aux = aux + " - " + "Manga Corta";
		}

		if (maoNeck) {
			aux = aux + " - " + "Cuello Mao";
		}

		return  aux;
	}

	const std::string GetCode() override
	{
		std::string aux = "S";
		if (shortSleeve) {
			aux += "S";
		}

		if (maoNeck) {
			aux += aux + "M";
		}

		return  aux;
	}

private:
	bool shortSleeve;
	bool maoNeck;
};
#endif

