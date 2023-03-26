#ifndef VIEW_H
#define VIEW_H

#include "IView.h"
#include "Seller.h"
#include "Store.h"
#include <string>

class Presenter;

class View : public IView
{
private:
	Presenter* m_presenter;
	Seller* m_seller;
	Store* m_store;
	int m_stock;
	std::vector<Quote> m_quoteHistory;
	void showMainMenu();
	void showHeaderMenu();
	void showTitle(const std::string& text);
	void showQuoteHistory(bool onlyShowLastInput);
	void ShowQuoteMenu();
	void showQuoteHistoryItem(Quote item);
	float showUnitPrice(const std::string& step, const std::string& stepDesc);
	bool isDigit(const std::string& text);
	void runOption(const char* option, bool& exitCondition);
public:
	View();
	~View() override;
	void showText(const char* text) override;
	void showText(const std::string& text) override;
	void showErrorMessage(const std::string& message) override;
	int showStep(const std::string& text, const std::string& stepDesc, const std::vector<std::string> opt, const std::string& title = "") override;
	void setSellerData(const Seller* seller) override;
	void setStoreData(const Store* store) override;
	void setQuoteHistory(std::vector<Quote> his) override;
	void setStock(int stock) override;
	void setError(const std::string message) override;
};
#endif //VIEW_H
