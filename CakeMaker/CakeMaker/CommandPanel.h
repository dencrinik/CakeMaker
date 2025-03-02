#pragma once
#include <string>
#include <list>

class CommandTaker;

class CommandPanel {
private:
	static std::list<std::string> recipes;

public:
	static void showProducts();
	static void selectProduct(const std::string& name);
	static void selectProduct(const std::string& name, int nrOfProducts);
	static void showProductsInCarousel();
	static void addRecipe(const std::string& recipe);
	static void removeRecipe(const std::string& recipe);
};