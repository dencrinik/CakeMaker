#include "CommandPanel.h"
#include "CommandTaker.hpp"
#include <iostream>

int main() {
	CommandPanel::addRecipe("Tiramisu");
	CommandPanel::addRecipe("Lava Cake");
	CommandPanel::addRecipe("Papanasi");
	int opt;
	do {
		std::cout << "1. Afisare produse\n";
		std::cout << "2. Selectare produs\n";
		std::cout << "3. Selectare produs cu cantitate\n";
		std::cout << "4. Afisare produse in Carusel\n";
		std::cout << "5. Reumplere Carusel\n";
		std::cout << "6. Iesire\n";
		std::cout << "Alege o opțiune: ";
		std::cin >> opt;

		switch (opt) {
		case 1:
			CommandPanel::showProducts();
			break;
		case 2:
		{
			std::string name;
			std::cout << "Introduceti numele produsului: ";
			std::cin >> name;
			CommandPanel::selectProduct(name);
		}
		break;
		case 3:
		{
			std::string name;
			int nrOfProducts;
			std::cout << "Introduceti numele produsului si cantitatea: ";
			std::cin >> name >> nrOfProducts;
			CommandPanel::selectProduct(name, nrOfProducts);
		}
		break;
		case 4:
			CommandPanel::showProductsInCarousel();
			break;
		case 5:
			CommandTaker::refillCarousel();
			break;
		case 6:
			std::cout << "La revedere!\n";
			break;
		default:
			std::cout << "Optiune invalida. Incercati din nou.\n";
		}
	} while (opt != 6);

	return 0;
}