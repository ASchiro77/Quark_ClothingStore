#include "Setup.h"
#include <string>
#include "Shirt.h"
#include "Pants.h"

Setup::Setup()
{
    this->seller = new Seller("Andres", "Schiro", "ABC456");
    std::vector<Garment*> garmentList;

    Garment* g = new Shirt(true, true, 100, 10, 1);
    garmentList.push_back(g);
    Garment* g1 = new Shirt(true, true, 100, 10, 2);
    garmentList.push_back(g1);
    Garment* g2 = new Shirt(true, false, 150, 10, 1);
    garmentList.push_back(g2);
    Garment* g3 = new Shirt(true, false, 150, 10, 2);
    garmentList.push_back(g3);
    Garment* g4 = new Shirt(false, true, 75, 10, 1);
    garmentList.push_back(g4);
    Garment* g5 = new Shirt(false, true, 75, 10, 2);
    garmentList.push_back(g5);
    Garment* g6 = new Shirt(false, false, 175, 10, 1);
    garmentList.push_back(g6);
    Garment* g7 = new Shirt(false, false, 175, 10, 2);
    garmentList.push_back(g7);
    Garment* g8 = new Pants(true, 750, 10, 1);
    garmentList.push_back(g8);
    Garment* g9 = new Pants(true, 750, 10, 2);
    garmentList.push_back(g9);
    Garment* g10 = new Pants(false, 250, 10, 1);
    garmentList.push_back(g10);
    Garment* g11 = new Pants(false, 250, 10, 2);
    garmentList.push_back(g11);

    this->store = new Store("Quark C++", "Av. Siempre viva 123", garmentList);
}