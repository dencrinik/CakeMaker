#pragma once
#include <string>

class CommandPanel {
public:
	void showProducts();
	void selectProduct(const std::string& name);
	void selectProduct(const std::string& name, int nrOfProducts);
	void showProductsInCarousel();
};