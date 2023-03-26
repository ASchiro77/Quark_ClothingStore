#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include "View.h"
#include "Presenter.h"
#include "Seller.h"
#include <algorithm>
#include <vector>

const std::string ANY_KEY_MESSAGE = "Escribe cualquier tecla para continuar.";
const std::string INVALID_OPTION_MESSAGE = "La opción ingresada es inválida, por favor reintente.";

View::View()
{
	SetConsoleTitleW(L"COTIZADOR EXPRESS - MENÚ PRINCIPAL");
	setlocale(LC_ALL, "es_Es");
	m_presenter = new Presenter(this);
	showMainMenu();
}

View::~View()
{
	delete m_presenter;
	delete m_seller;
	delete m_store;
	//std::for_each(m_quoteHistory.begin(), m_quoteHistory.end(), [](const auto& itr) { delete (itr.second); });
	m_quoteHistory.clear();
}

void View::showText(const char* text)
{
	std::cout << text << std::endl;
}

void View::showText(const std::string& text)
{
	std::cout << text << std::endl;
}

void View::showTitle(const std::string& text)
{
	showText("COTIZADOR EXPRESS - " + text);
	showText("---------------------------------------------------------------------");
	showText("Presiona 3 para volver al menú principal");
	showText("---------------------------------------------------------------------");
	showText("");
}

bool View::isDigit(const std::string& text) {

	for (int i = 0; i < text.size(); i++) {
		if (!isdigit(text[i])) {
			return false;
		}
	}
	return true;
}

void View::showErrorMessage(const std::string& message)
{
	std::string optionString = "";
	bool isValidOption = true;

	do
	{
		std::system("cls");
		showTitle("COTIZAR");

		showText(message);
		
		std::cin >> optionString;
		if (optionString == "3")
		{
			isValidOption = true;
		}
		else
		{
			showText(INVALID_OPTION_MESSAGE);
			std::cin.get();
		}

	} while (!isValidOption);

	showMainMenu();
}


int View::showStep(const std::string & step, const std::string& stepDesc, const std::vector<std::string> opt, const std::string& title)
{
	std::string optionString = "";
	bool isValidOption = true;

	do
	{
		std::system("cls");
		showTitle("COTIZAR");

		if (title != "") {
			showText(title);
		}

		showText("PASO " + step + ": " + stepDesc);

		int i = 1;
		for (auto& item : opt)
		{
			showText(std::to_string(i) + ") " + item);
			i++;
		}

		std::cin >> optionString;
		if (optionString == "3")
		{
			isValidOption = true;
		}
		else 
		{
			if(!this->isDigit(optionString) && opt.size() <= stoi(optionString))
			{
				showText(INVALID_OPTION_MESSAGE);
				std::cin.get();
			}
			
			return stoi(optionString);
		}
		std::cin.get();
	} while (!isValidOption);

	showMainMenu();
}



float View::showUnitPrice(const std::string& step, const std::string& stepDesc) {

	std::string optionString = "";
	bool isValidOption = true;

	do
	{
		std::system("cls");
		showTitle("COTIZAR");
		showText("PASO " + step + ": " + stepDesc);

		std::cin >> optionString;
		if (optionString == "3")
		{
			isValidOption = true;
		}
		else
		{
			if (!this->isDigit(optionString))
			{
				showText(INVALID_OPTION_MESSAGE);
				std::cin.get();
			}

			return stof(optionString);
		}
		std::cin.get();
	} while (!isValidOption);

	showMainMenu();
}



void View::setStock(const int stock)
{
	m_stock = stock;
}

void View::setSellerData(const Seller* seller) 
{
	m_seller = (Seller*)seller;
}

void View::setStoreData(const Store* store)
{
	m_store = (Store*)store;
}

void View::setError(const std::string m)
{
	this->showErrorMessage(m);
}

void View::setQuoteHistory(const std::vector<Quote> his)
{
	m_quoteHistory = his;
}


void View::showQuoteHistoryItem(Quote item)
{
	showText("Número de identificación: " + std::to_string(item.getId()));
	showText("Fecha y Hora de la cotización: " + item.getDateTime());
	showText("Código del Vendedor: " + item.getSellerCode());
	showText("Prenda cotizada: " + item.getGarment());
	showText("Precio unitario: " + std::to_string(item.getGarmentUnitPrice()));
	showText("Cantidad de unidades cotizadas: " + std::to_string(item.getQuantity()));
	showText("Precio Final: " + std::to_string(item.getQuoteResult()));
	showText("");
}

void View::showQuoteHistory(bool onlyShowLastInput)
{
	std::string optionString = "";
	bool isValidOption = true;
	do
	{
		std::system("cls");
		showTitle("HISTORIAL DE COTIZACIONES");

		m_presenter->getQuoteHistory();

		if (onlyShowLastInput) {
			this->showQuoteHistoryItem(m_quoteHistory.back());
		}
		else {
			for (auto& item : m_quoteHistory)
			{
				this->showQuoteHistoryItem(item);
			}
		}

		showText("---------------------------------------------------------------------");
		showText("Presiona 3 para volver al menú principal");
		showText("---------------------------------------------------------------------");
		std::cin >> optionString;
		if (optionString == "3")
		{
			isValidOption = true;
		}
		std::cin.get();
	} while (!isValidOption);

	showMainMenu();
}

void View::ShowQuoteMenu()
{
	std::string optionString = "";
	bool isValidOption = true;

	bool shortSleeve = false;
	bool maoNeck = false;
	bool slim = false;

	int garment = showStep("1", "Seleccione la prenda a cotizar", { "Camisa", "Pantalón" });
	if (garment == 1) {
		shortSleeve = (1 == showStep("2.a", "La camisa a cotizar, ¿Es MangaCorta? ", {"Sí", "No"}));
		maoNeck = (1 == showStep("2.b", "La camisa a cotizar, ¿Es Cuello Mao? ", { "Sí", "No" }));

	}
	else {
		slim = (1 == showStep("2", "El Pantalón a cotizar, ¿Es Chupín? ", { "Sí", "No" }));
	}

	int quality = showStep("3", "Seleccione la calidad de la prenda", { "Standard", "Premium" });
	float unitPrice = showUnitPrice("4", "Ingreso el precio unitario de la prenda a cotizar");

	//getStock
	m_presenter->getStock(garment, shortSleeve, maoNeck, slim, quality);

	int quantity = showStep("5", "Ingreso la cantidad de unidades a cotizar", {}, "INFORMACION: EXISTE " + std::to_string(m_stock) + " DE UNIDADES EN STOCK DE LA PRENDA SELECCIONADA");
	
	if(quantity > m_stock){
		showErrorMessage("ERROR: STOCK NO DISPONIBLE");
	}

	m_presenter->saveQuote(garment, shortSleeve, maoNeck, slim, quality, unitPrice, quantity);

	this->showQuoteHistory(true);
}

void View::showHeaderMenu() 
{
	std::string title1 = m_store->getName() + " | " + m_store->getAddress();
	std::string title2 = m_seller->getName() + ", " + m_seller->getlastName() + " | " + m_seller->getSellerCode();

	showText("COTIZADOR EXPRESS - MENÚ PRINCIPAL");
	showText("---------------------------------------------------------------------");
	showText(title1);
	showText("---------------------------------------------------------------------");
	showText(title2);
	showText("");
}

void View::showMainMenu()
{
	std::string option;
	bool exitCondition = false;
	do
	{
		std::system("cls");;
		showHeaderMenu();
		showText("SELECCIONE UNA OPCIÓN DEL MENU");
		showText("");
		showText("1) Historial de Cotizaciones");
		showText("2) Realizar Cotización");
		showText("3) Salir");
		std::cin >> option;
		std::system("cls");
		runOption(option.c_str(), exitCondition);
		showText("");
		showText(ANY_KEY_MESSAGE);
		std::cin.get();
	} while (!exitCondition);
}

void View::runOption(const char* option, bool& exitCondition)
{
	auto str_option = std::string(option);

	if (str_option == "1")
	{
		showQuoteHistory(false);
		exitCondition = false;
	}
	else if (str_option == "2")
	{
		ShowQuoteMenu();
		std::cin.get();
		exitCondition = false;
	}
	else if (str_option == "3")
	{
		std::cout.flush();
		exit(EXIT_SUCCESS);
	}
	else
	{
		showText(INVALID_OPTION_MESSAGE);
		std::cin.get();
		exitCondition = false;
	}
}
