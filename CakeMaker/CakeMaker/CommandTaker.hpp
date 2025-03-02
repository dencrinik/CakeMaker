#pragma once
#include <list>
#include "Cake.hpp"
#include "CakeMaker.hpp"
#include "CakeRecipe.hpp"

class CommandTaker {
private:
	static std::list<CakeRecipe> CarouselOfCakes;
	static CakeMaker cakeMaker;

public:
	static Cake takeCommand(const std::string& recipe);
	static std::list<Cake> takeCommand(const std::string& recipe, int nrOfCakes);
	static std::list<Cake> getCakesFromCarousel();
	static bool checkCarouselOfCakes();
	static void refillCarousel();
	static void showProductsInCarousel();
};