#pragma once
#include <string>
#include "CakeRecipe.hpp"

class Cake {
public:
	std::string name;

	Cake(const std::string& cakeName);

	Cake(const CakeRecipe& cakeRecipe);
};