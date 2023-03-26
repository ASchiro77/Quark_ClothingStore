#pragma once
#include <string>
#ifndef QUALITY_H
#define QUALITY_H
const std::string STANDARD_DESCRIPTION = "STANDARD";
const std::string PREMIUM_DESCRIPTION = "PREMIUM";

class Quality
{
public:
	Quality() {};
	Quality(int id)
	{
		this->identifier = id;
		if (id == 1) {
			this->decription = STANDARD_DESCRIPTION;
		}
		else
		{
			this->decription = PREMIUM_DESCRIPTION;
		};
	}
	std::string getDescription() { return this->decription; };

private: 
	int identifier = 0;
	std::string decription;
};
#endif



