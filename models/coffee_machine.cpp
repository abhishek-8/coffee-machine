#include <bits/stdc++.h>
#include "beverage.cpp"
#include "store.cpp"

using namespace std;

class CoffeeMachine {
    // Private Members
    int num_of_outlets;
    Store* store; // Pointer to its store
    map < int, Beverage* > outlet_beverage; // maintains the mapping of outlet number with Beverage being processed
    queue <int> available_outlets; // maintains free outlets in a queue

    void detach_beverages_from_outlets() {
        outlet_beverage.clear();
    }

    // maps beverage to any available outlet number
    void assign_beverage_to_outlet(Beverage* b) {
        int assigned_outlet = available_outlets.front();
        available_outlets.pop();
        outlet_beverage[assigned_outlet] = b;
        cout << b->get_name() << " is being prepared at outlet number " << assigned_outlet << "\n";
    }

    // Return true/false indicating if all the ingredients required for the beverage are present or not
    bool ingredients_present(Beverage* b) {
        map <Ingredient*, int> ingredients = b->ingredients();

        for (auto i: ingredients) {
            Ingredient* ingredient_ptr = i.first;
            int required_quantity = i.second;

            if (this->store->available(ingredient_ptr->get_name(), required_quantity)) {
                continue;
            } else {
                cout << b->get_name() << " cannot be prepared because " << ingredient_ptr->get_name() << " is not sufficient" << "\n";
                return false;
            }
        }
        return true;
    }

    // consume the required ingredients quantity from the store of machine
    void consume_ingredients(Beverage* b) {
        map <Ingredient*, int> ingredients = b->ingredients();
        for (auto i: ingredients) {
            Ingredient* ingredient_ptr = i.first;
            int required_quantity = i.second;
            this->store->consume_ingredient_quantity(ingredient_ptr->get_name(), required_quantity);
        }
    }

    // Make all the outlets available for use
    void init_outlets(int num_of_outlets) {
        this->num_of_outlets = num_of_outlets;

        // first emptying any already available outlet
        while (!this->available_outlets.empty()) {
            this->available_outlets.pop();
        }

        // sets all outlets avaiable for use
        for (int i = 1; i <= this->num_of_outlets; i++) {
            this->available_outlets.push(i);
        }
    }


    public:
    CoffeeMachine(int num_of_outlets, map<string, int> store_ingredients_quantity) {
        init_outlets(num_of_outlets);
        this->store = new Store(store_ingredients_quantity);
    }

    void process_beverage(Beverage *b) {
        if (available_outlets.empty()) {
            cout << "All outlets are under use" << "\n";
            return;
        }

        if (ingredients_present(b)) {
            consume_ingredients(b);
            assign_beverage_to_outlet(b);
        }
    }

    void free_all_outlets() {
        init_outlets(this->num_of_outlets);
        detach_beverages_from_outlets();
    }

    // To increase the quantity of ingredient in the store
    void restock(Ingredient* i, int quantity) {
        this->store->add_ingredient_quantity(i->get_name(), quantity);
    }

};
