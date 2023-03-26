#pragma once
#include <string>
#include "Seller.h"
#include "Store.h"
#ifndef SETUP_H
#define SETUP_H

class Setup
{
public:
	Setup();
	Seller* getSeller() { return this->seller; };
	Store* getStore() { return this->store; };
private:
	Seller* seller;
	Store* store;
};
#endif







