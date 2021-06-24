#include <bits/stdc++.h>
using namespace std;

class Ingredient {
    string name, measuring_unit;

    public:
    Ingredient(string name, string measuring_unit = "ml") {
        set_name(name);
        set_measuring_unit(measuring_unit);
    }

    string get_measuring_unit() {
        return this->measuring_unit;
    }

    string get_name() {
        return this->name;
    }

    void set_name(string name) {
        this->name = name;
    }

    void set_measuring_unit(string unit) {
        this->measuring_unit = unit;
    }
};