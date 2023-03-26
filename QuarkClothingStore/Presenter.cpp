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
	try {
		auto quoteHistory = m_seller->getQuoteHistory();
		m_view->setQuoteHistory(quoteHistory);
	}
	catch (int e) {
		m_view->setError("Error en al obtener el hitorial de cotizaciones.Error: " + std::to_string(e));
	}
}

void Presenter::getStock(int garmentType, bool shortSleeve, bool maoNeck, bool slim, int qualityType)
{
	try {
		int stock = m_store->getStock(garmentType, shortSleeve, maoNeck, slim, qualityType);
		m_view->setStock(stock);
	}
	catch (int e) {
		m_view->setError("Error en al obtener el stock.Error: " + std::to_string(e));
	}
}

void Presenter::saveQuote(int garmentType, bool shortSleeve, bool maoNeck, bool slim, int qualityType, float unitPrice, int quantity)
{
	try {
		m_seller->addQuote(garmentType, shortSleeve, maoNeck, slim, qualityType, unitPrice, quantity);
		m_store->discountStock(garmentType, shortSleeve, maoNeck, slim, qualityType, quantity);
	}
	catch(int e){
		m_view->setError("Error en al guardar la cotización.Error: " + std::to_string(e));
	}
	
}
