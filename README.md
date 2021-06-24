# coffee-machine
For the given assignment of coffee machine with N outlets, we have identified 5 classes.

1. CoffeeMachine (has one Store)
2. Beverage (has one Recipe)
3. Store (Belongs to a CoffeeMachine)
4. Recipe (Belongs to a Beverage, has many ingredients)
5. Ingredient (Belongs to many Recipes)


Each class is written in a separate file having separate functionalities related to them.

Main.cpp is responsilbe to read input from user.

Main.cpp uses following functional interfaces to interact with the coffee machine:-
1. bool prepare_beverage (string ); 
    Used to process commands for preparing a beverage from the coffee machine.


2. bool restock (string, int );
    Used to process commands for restocking a ingredient qunatity in the store.

3. void free_outlets ();
    Used to process commands for freeing up all the outlets so that it can by used to further prepare commands.




# INPUT FORMAT:
    First line contains a single integer 'N' denoting the number of outlets of the machine.

    Next line contains an integer 'M' denoting the number of ingredients in the store.
    Each of the next 'M' lines contains a string and an integer denoting the name of ingredient and its quantity in the store respectively.

    Next line contains an integere 'B' denoting the number of beverages the coffee machine can prepare

    For each Beverage out of 'B':
        The input file contains a string 'B_name' and an integer 'K' denoting the beverage name and number of different ingredients required by the beverage respectively.

            Each of the next 'K' lines contains a string 'I_name' and an integer 'I_qty' denoting the ingredient name and its quantity required for the Beverage 'B_name' respectively

    Next lines contains an integer 'T' denoting the number of tasks
    Each of the next 'T' lines contains of task of any one of the following type
    prepare {{beverage_name}}
    restock {{ingredient_name}} {{ingredient_quantity}}
    free_outlets


# How to Test with Inputs:
    The input can be written in the file input.txt in the above format. 
    On running the main.cpp, the output will be generated and written to the file output.txt


# SAMPLE INPUT:
    10
    5
    milk 20
    water 300
    ginger_syrup 50
    sugar_syrup 60
    tea_leaves_syrup 30
    2
    tea 2
    milk 10
    water 30
    black_tea 4
    water 300
    ginger_syrup 30
    sugar_syrup 50
    tea_leaves_syrup 30
    4
    prepare black_tea
    prepare tea
    restock water 300
    prepare tea


# SAMPLE OUTPUT:
    black_tea is being prepared at outlet number 1
    tea cannot be prepared because water is not sufficient
    tea is being prepared at outlet number 2



# EXPLANATION:
Store contains following ingredients:-<br>
Milk 20 ml<br>
Water 300 ml<br>
Ginger Syrup 50 ml<br>
Sugar Syrup 60 ml<br>
Tea leaves syrup 30 ml<br>
<br>
Available Outlets: 1 2 3 4 5 6 7 8 9 10<br>

## Task 1: 
    Prepare Black tea
        Black tea requires
            water 300 ml
            ginger_syrup 30
            sugar_syrup 50
            tea_leaves_syrup 30
        These are present in the store is the black tea consumes the required ingredients.
        => black_tea is being prepared at outlet number 1

Now, the store contains:-<br>
Milk 20 ml<br>
Water 300 - 300 = 0 ml<br>
Ginger Syrup 50 - 30 = 20 ml<br>
Sugar Syrup 60 - 50 = 10 ml<br>
Tea leaves syrup 30 - 30 = 0 ml<br>
<br>
Available Outlets: 2 3 4 5 6 7 8 9 10<br>



## Task 2:
    Prepare Tea:
    Remaining quantity of water in store is less than 300 ml (required for tea).
    => tea cannot be prepared because water is not sufficient

## Task 3:
    restock water 300:

Now, the store contains:<br>
Milk 20 ml<br>
Water 0 + 300 = 300 ml<br>
Ginger Syrup 20 ml<br>
Sugar Syrup 10 ml<br>
Tea leaves syrup 0 ml<br>


## Task 4: 
    Prepare Tea
    now the store contains sufficient quantity of required ingredients and first outlet is in use already.
    => tea is being prepared at outlet number 2

