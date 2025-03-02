#include "CakeMaker.hpp"
#include <thread>
#include <chrono>
#include <iostream>

Cake CakeMaker::takeCommand(const CakeRecipe& recipe) {
	std::cout << "Se reumple Caruselul Prajiturilor !\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	Cake cake = { recipe.name };
	return cake;
}