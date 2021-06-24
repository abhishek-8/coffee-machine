#include <bits/stdc++.h>
#include "recipe.cpp"

using namespace std;

class Beverage {
    Recipe* recipe;
    string name;

    public:
    Beverage(string name) {
        set_name(name);
        init_recipe();
    }

    void add_recipe_ingredient (Ingredient* i, int quantity) {
        this->recipe->add_ingredient (i, quantity);
    }

    void set_name (string name) {
        this->name = name;
    }

    string get_name() {
        return this->name;
    }

    map <Ingredient*, int> ingredients() {
        return this->recipe->ingredients_requirement();
    }

    void init_recipe() {
        this->recipe = new Recipe();
    }

};
