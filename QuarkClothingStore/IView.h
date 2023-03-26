#pragma once
#ifndef IVIEW_H
#define IVIEW_H
#include <string>
#include <vector>

class Seller;
class Store;
class Quote;

class IView
{
public:
	virtual ~IView() = default;
	virtual void showText(const char* text) = 0;
	virtual void showText(const std::string& text) = 0;
	virtual int showStep(const std::string& text, const std::string& stepDesc, const std::vector<std::string> opt, const std::string& title = "") = 0;
	virtual void showErrorMessage(const std::string& message) = 0;
	virtual void setSellerData(const Seller* seller) = 0;
	virtual void setStoreData(const Store* store) = 0;
	virtual void setQuoteHistory(std::vector<Quote> his) = 0;
	virtual void setStock(const int stock) = 0;
	virtual void setError(const std::string message) = 0;
};
#endif // IVIEW_H
