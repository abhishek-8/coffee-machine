#include <bits/stdc++.h>
#include "ingredient.cpp"

using namespace std;

class Recipe {
    map <Ingredient*, int> ingredient_quantity;

    public:
    Recipe() {}

    void add_ingredient(Ingredient* i, int quantity) {
        this->ingredient_quantity[i] = quantity;
    }

    map <Ingredient*, int> ingredients_requirement() {
        return this->ingredient_quantity;
    }
};
