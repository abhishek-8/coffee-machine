class Store {
    map <string, int> remaining_quantity;
    public:
    Store(map<string, int> store_ingredients_quantity) {
        this->remaining_quantity = store_ingredients_quantity;
    }

    void add_ingredient_quantity(string ingredient_name, int quantity) {
        this->remaining_quantity[ingredient_name] += quantity;
    }

    void consume_ingredient_quantity(string ingredient_name, int quantity) {
        this->remaining_quantity[ingredient_name] -= quantity;    
    }

    bool available(string ingredient_name, int quantity) {
        return this->remaining_quantity[ingredient_name] >= quantity;
    }
};
