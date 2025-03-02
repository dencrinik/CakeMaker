#include "CommandPanel.h"
#include "CommandTaker.hpp"
#include <iostream>

std::list<std::string> CommandPanel::recipes;

void CommandPanel::showProducts() {
	std::cout << "Lista de retete disponibile pentru cumparare:\n";
	for (const auto& recipe : recipes) {
		std::cout << " - " << recipe << "\n";
	}
	std::cout << "\n";
}

void CommandPanel::selectProduct(const std::string& name) {
	CommandTaker::takeCommand(name);
}

void CommandPanel::selectProduct(const std::string& name, int nrOfProducts) {
	auto cakes = CommandTaker::takeCommand(name, nrOfProducts);
}

void CommandPanel::showProductsInCarousel() {
	CommandTaker::showProductsInCarousel();
}

void CommandPanel::addRecipe(const std::string& recipe) {
	recipes.push_back(recipe);
}