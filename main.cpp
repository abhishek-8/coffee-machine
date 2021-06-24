#include <bits/stdc++.h>
#include "models/coffee_machine.cpp"
#include "errors.cpp"
using namespace std;

/*
=======================================================================================
Declaring variables to only read and store user input and its mapping with class object
=======================================================================================
*/

int num_of_outlets; // Stores the total number of outlet for the coffe machine
map < string, vector < pair < string, int > > > beverage_ingredients; // Stores the ingredients and its quantities for each beverage name
map < string, int > store_ingredients; // Stores the ingredients and its quantities initially present for the machine
map < string, Ingredient* > ingredient_pointer_map; // Maps ingredient name with a pointer that points to its class object
map < string, Beverage* > beverage_pointer_map; // Maps breverage name with a pointer that points to its class object

/* ******************************* Variable declaration ends ********************************** */



CoffeeMachine* g_machine_ptr; // Global pointer to the object of CoffeeMachine object




/* 
===============================================================================
Functional interface that is being called directly from the input command
===============================================================================
*/

bool prepare_beverage(string beverage_name) {
    if (beverage_pointer_map.find(beverage_name) == beverage_pointer_map.end()) {
        beverage_not_found_error();
        return false;
    }
    g_machine_ptr->process_beverage(beverage_pointer_map[beverage_name]);
    return true;
}

bool restock(string ingredient_name, int quantity) {
    if (ingredient_pointer_map.find(ingredient_name) == ingredient_pointer_map.end()) {
        ingredient_not_found_error();
        return false;
    }
    g_machine_ptr->restock(ingredient_pointer_map[ingredient_name], quantity);
    return true;
}

void free_outlets() {
    g_machine_ptr->free_all_outlets();
}

/* ************************** Function interface ends ***************************** */






/*
=============================================================================
Reads input 
=============================================================================
*/

void read_num_of_outlets() {
    cin >> num_of_outlets;
}

void read_store_ingredients() {
    int num_of_store_items;
    cin >> num_of_store_items;

    while(num_of_store_items--) {
        string ingredient_name;
        int quantity;
        cin >> ingredient_name >> quantity;
        store_ingredients[ingredient_name] = quantity;
    }
}

void read_beverage_ingredients() {
    int num_of_beverages, ingredient_count, ingredient_quantity;
    string beverage_name, ingredient_name;

    cin >> num_of_beverages;

    while (num_of_beverages--) {
        cin >> beverage_name >> ingredient_count;

        vector < pair <string, int> > ingredients_list;

        while (ingredient_count--) {
            cin >> ingredient_name >> ingredient_quantity;
            ingredients_list.push_back(make_pair(ingredient_name, ingredient_quantity));
        }

        beverage_ingredients[beverage_name] = ingredients_list;
    }
}

void user_input() {
    read_num_of_outlets();
    read_store_ingredients();
    read_beverage_ingredients();
}


void user_task_input() {
    int tasks, quantity;
    string name, task_type;

    cin >> tasks;

    while (tasks--) {
        cin >> task_type;

        if (task_type == "prepare") {

            cin >> name;
            if(!prepare_beverage(name)) {
                haulted_error();
                return;
            }

        } else if (task_type == "restock") {

            cin >> name >> quantity;
            if (!restock(name, quantity)) {
                haulted_error();
                return;
            }

        } else if (task_type == "free_outlets") {

            free_outlets();

        } else {

            invalid_task_error();

        }
    }
}

/* ********************************* Ends reading input *************************************** */





/* 
=============================================================================
Maps input with models
=============================================================================
*/
void map_store_input_to_object_pointers() {
    for (auto i: store_ingredients) {
        string ingredient_name = i.first;

        if (ingredient_pointer_map.find(ingredient_name) == ingredient_pointer_map.end()) {

            ingredient_pointer_map[ingredient_name] = new Ingredient(ingredient_name);

        } else {

            duplicate_ingredient_error();

        }
    }
}

void map_beverage_input_to_object_pointers() {
    for (auto i: beverage_ingredients) {
        string beverage_name = i.first;

        if (beverage_pointer_map.find(beverage_name) == beverage_pointer_map.end()) {

            beverage_pointer_map[beverage_name] = new Beverage(beverage_name);

            vector < pair <string, int> > ingredients = i.second;

            for (auto j: ingredients) {
                string ingredient_name = j.first;
                int ingredient_quantity = j.second;

                if (ingredient_pointer_map.find(ingredient_name) != ingredient_pointer_map.end()) {
                    beverage_pointer_map[beverage_name]->add_recipe_ingredient(
                        ingredient_pointer_map[ingredient_name], 
                        ingredient_quantity
                    );

                } else {
                    ingredient_not_found_error();
                }
            }

        } else {
            duplicate_beverage_error();
        }
    }
}

void map_user_input_with_models() {
    map_store_input_to_object_pointers();
    map_beverage_input_to_object_pointers();
}

/* ****************************** Ends mapping input ********************************** */



int main() {

    #ifndef ONLINE_JUDGE
    freopen( "input.txt", "r", stdin);
    freopen( "output.txt", "w", stdout);
    #endif

    // Initial Seeding
    user_input();
    map_user_input_with_models();

    // Defining global pointer to the machine class object
    g_machine_ptr = new CoffeeMachine(num_of_outlets, store_ingredients);

    // Input of tasks
    user_task_input();

    return 0;
}

