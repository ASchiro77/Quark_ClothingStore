#pragma once
#ifndef PRESENTER_H
#define PRESENTER_H
#include <string>

class IView;
class Seller;
class Store;

class Presenter
{
private:
	IView* m_view = nullptr;
	Seller* m_seller = nullptr;
	Store* m_store = nullptr;
public:
	explicit Presenter(IView* view);
	~Presenter();
	void getQuoteHistory();
	void getStock(int garmentType, bool shortSleeve, bool maoNeck, bool slim, int qualityType);
	void saveQuote(int garmentType, bool shortSleeve, bool maoNeck, bool slim, int qualityType, float unitPrice, int quantity);
};
#endif //PRESENTER_H
