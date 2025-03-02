#include "CommandTaker.hpp"
#include <iostream>
#include <thread>
#include <chrono>

std::list<CakeRecipe> CommandTaker::CarouselOfCakes;
CakeMaker CommandTaker::cakeMaker;

Cake CommandTaker::takeCommand(const std::string& recipeName) {
	CakeRecipe recipe(recipeName);
	if (checkCarouselOfCakes()) {
		auto it = CarouselOfCakes.begin();
		Cake cake(*it);
		CarouselOfCakes.erase(it);
		std::cout << "Prajitura '" << cake.name << "' preluata din Caruselul Prajiturilor.\n";
		return cake;
	}
	else {
		return cakeMaker.takeCommand(recipe);
	}
}

std::list<Cake> CommandTaker::takeCommand(const std::string& recipeName, int nrOfCakes) {
	CakeRecipe recipe(recipeName);
	std::list<Cake> cakes;
	if (checkCarouselOfCakes()) {
		for (int i = 0; i < nrOfCakes && !CarouselOfCakes.empty(); i++) {
			Cake cake = { CarouselOfCakes.front().name };
			CarouselOfCakes.pop_front();
			cakes.push_back(cake);
		}
		std::cout << "Preluare " << cakes.size() << " prajituri din Caruselul Prajiturilor.\n";
	}
	else {
		cakes.push_back(cakeMaker.takeCommand(recipe));
	}
	return cakes;
}

std::list<Cake> CommandTaker::getCakesFromCarousel() {
	return std::list<Cake>(CarouselOfCakes.begin(), CarouselOfCakes.end());
}

bool CommandTaker::checkCarouselOfCakes() {
	return !CarouselOfCakes.empty();
}

void CommandTaker::refillCarousel() {
	while (CarouselOfCakes.size() < 12) {
		if (CarouselOfCakes.size() <= 4)
		{
			CakeRecipe recipe("Tiramisu");
			Cake cake = cakeMaker.takeCommand(recipe);
			CarouselOfCakes.push_back({ recipe.name });
		}
		if (CarouselOfCakes.size() > 4 && CarouselOfCakes.size() <= 8)
		{
			CakeRecipe recipe("LavaCake");
			Cake cake = cakeMaker.takeCommand(recipe);
			CarouselOfCakes.push_back({ recipe.name });
		}
		if (CarouselOfCakes.size() > 8 && CarouselOfCakes.size() <= 12)
		{
			CakeRecipe recipe("Papanasi");
			Cake cake = cakeMaker.takeCommand(recipe);
			CarouselOfCakes.push_back({ recipe.name });
		}
	}
	std::cout << "Caruselul Prajiturilor a fost reumplut.\n";
}

void CommandTaker::showProductsInCarousel() {
	std::cout << "Produsele din Caruselul Prajiturilor:\n";
	for (const auto& cake : CarouselOfCakes) {
		std::cout << " - " << cake.name << "\n";
	}
}