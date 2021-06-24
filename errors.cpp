#include <bits/stdc++.h>
using namespace std;

const string INVALID_TASK_INPUT_ERROR = "Invalid task input error";
const string BEVERAGE_NOT_FOUND_ERROR = "Beverage not available";
const string DUPLICATE_BEVERAGE_ERROR = "Duplicate Beverage name found";
const string DUPLICATE_INGREDIENT_ERROR = "Duplicate Ingredient name found";
const string INGREDIENT_NOT_FOUND_ERROR = "Ingredient not available";
const string PROCESS_HAULTED = "Process haulted due to some error";

void invalid_task_error() {
    cout << INVALID_TASK_INPUT_ERROR << "\n";
}

void beverage_not_found_error() {
    cout << BEVERAGE_NOT_FOUND_ERROR << "\n";
}

void ingredient_not_found_error() {
    cout << INGREDIENT_NOT_FOUND_ERROR << "\n";
}

void duplicate_beverage_error() {
    cout << DUPLICATE_BEVERAGE_ERROR << "\n";
}

void duplicate_ingredient_error() {
    cout << DUPLICATE_INGREDIENT_ERROR << "\n";
}

void haulted_error() {
    cout << PROCESS_HAULTED << "\n";
}
