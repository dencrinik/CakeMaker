#include "Cake.hpp"
#include "CakeRecipe.hpp"

Cake::Cake(const std::string& cakeName) : name(cakeName) {}

Cake::Cake(const CakeRecipe& cakeRecipe) : name(cakeRecipe.name) {}