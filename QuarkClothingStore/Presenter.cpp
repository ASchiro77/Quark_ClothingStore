#include "Presenter.h"
#include "IView.h"
#include "Seller.h"
#include "Setup.h"
#include "Shirt.h"
#include "Pants.h"

Presenter::Presenter(IView* view) : m_view(view)
{
	Setup setup = Setup();
	m_seller = setup.getSeller();
	m_store = setup.getStore();
	m_view->setSellerData(m_seller);
	m_view->setStoreData(m_store);
}

Presenter::~Presenter()
{
	delete m_seller;
	delete m_store;
};

void Presenter::getQuoteHistory()
{
	auto quoteHistory = m_seller->getQuoteHistory();
	m_view->setQuoteHistory(quoteHistory);
}

std::string Presenter::buildGarmentCode(int garmentType, bool shortSleeve, bool maoNeck, bool slim, int qualityType) {
	std::string aux = "";
	if (garmentType == 1) {
		aux += "S";
		if (shortSleeve) { aux += "S"; }
		if (maoNeck) { aux += "M"; }
	}
	else {
		aux += "P";
		if (slim) { aux += "S"; }
	}

	if (qualityType == 1) {
		aux += STANDARD_DESCRIPTION;
	}
	else {
		aux += PREMIUM_DESCRIPTION;
	}

	return aux;
};

void Presenter::getStock(int garmentType, bool shortSleeve, bool maoNeck, bool slim, int qualityType)
{
	int stock = m_store->getStock( this->buildGarmentCode(garmentType, shortSleeve, maoNeck, slim, qualityType) );
	m_view->setStock(stock);
}

void Presenter::saveQuote(int garmentType, bool shortSleeve, bool maoNeck, bool slim, int qualityType, float unitPrice, int quantity)
{
	std::string garmentCode = this->buildGarmentCode(garmentType, shortSleeve, maoNeck, slim, qualityType);

	Garment* g;
	if (garmentType == 1) {
		g = new Shirt(shortSleeve, maoNeck, quantity, unitPrice, qualityType);
	}
	else {
		g = new Pants(slim, quantity, unitPrice, qualityType);
	}

	float total = quantity * unitPrice;

	if (shortSleeve) {
		total = total - (total * 0.1); //- 10%
	}

	if (maoNeck) {
		total = total + (total * 0.03); // + 3%
	}

	if (slim) {
		total = total - (total * 0.12); // -12%
	}

	if (qualityType == 1) {
		total = total + (total * 0.3); // + 30%
	}
	idQuote++;
	Quote quote = Quote(idQuote, m_seller->getSellerCode(), quantity, total, g);

	m_seller->addQuote(quote);
	m_store->discountStock(garmentCode, quantity);
}
