#pragma once
#include "Cake.hpp"
#include "CakeRecipe.hpp"
class CakeMaker {
public:
	Cake takeCommand(const CakeRecipe& recipe);
};