/**
 * focaccia.cpp
  * Project UID: d435ced1b1ee1e06372665b53322301c67d2d4a0
 *
 * Joel Iacoban
 * joeliaco
 *
 * EECS 183: Project 1
 * Fall 2024
 * 
 * This program generates a shopping list given a number of people to make foccacia
 *
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string pluralize(string singular, string plural, int number);


// Based off Project Specification saying a single loaf serves four people
const int PEOPLE_SUPPLIED_PER_LOAF = 4;

double amountFlour(int amtPpl);
double amountYeast(int amtPpl);
double amountSalt(int amtPpl);
double amountOliveOil(int amtPpl);

int main() {
    int people;
    
    double numLoaves;
    
    double bagsFlour;
    double costFlour;
    
    double packsYeast;
    double costYeast;
    
    double cansSalt;
    double costSalt;
    
    double bottlesOliveOil;
    double costOliveOil;
    
    double totalCost;

    cout << "How many people do you need to serve? ";
    cin >> people;
    cout << endl << endl;
    
    // People divided by 4 gives loaves because 1 loaf serves 4 people
    numLoaves = ((float (people)) / PEOPLE_SUPPLIED_PER_LOAF);
    
 
    bagsFlour = amountFlour(people);
    packsYeast = amountYeast(people);
    cansSalt = amountSalt(people);
    bottlesOliveOil = amountOliveOil(people);
    
    cout << "You need to make: ";
    cout << ceil(numLoaves) << " " << pluralize("loaf", "loaves", ceil(numLoaves));
    cout << " of focaccia" << endl << endl;
    
    cout << "Shopping List for Focaccia Bread" << endl;
    cout << "--------------------------------" << endl;
    
    cout << bagsFlour << " " << pluralize("bag", "bags", bagsFlour);
    cout << " of flour" << endl;
    
    cout << packsYeast << " " << pluralize("package", "packages", packsYeast);
    cout << " of yeast" << endl;
    
    cout << cansSalt << " " << pluralize("canister", "canisters", cansSalt);
    cout << " of salt" << endl;
    
    cout << bottlesOliveOil << " ";
    cout << pluralize("bottle", "bottles", bottlesOliveOil);
    cout << " of olive oil" << endl << endl;
    
    // Calculates total cost of ingredients using given costs from Specification
    costFlour = bagsFlour * 2.69;
    costYeast = packsYeast * 0.40;
    costSalt = cansSalt * 0.49;
    costOliveOil = bottlesOliveOil * 6.39;
    
    totalCost = costFlour + costYeast + costSalt + costOliveOil;
    
    cout << "Total expected cost of ingredients: $" << totalCost << endl << endl;
    cout << "Have a great party!";
    
    return 0;
}

double amountFlour(int amtPpl) {
    
   // Found by dividing total flour cups in a 5 lb. bag by recipe's call for cups
    const double LOAVES_POSSIBLE_PER_BAG = 4.0;
   
    double neededFlourBags;
    double amtLoavesNeeded = (float (amtPpl) / PEOPLE_SUPPLIED_PER_LOAF);
    
    // Finds how many flour bags based on 4 loaves per bag
    neededFlourBags = (amtLoavesNeeded / LOAVES_POSSIBLE_PER_BAG);
   
    return ceil(neededFlourBags);
}

double amountYeast(int amtPpl) {
   
    // Found by dividing total yeast teaspoons in a pack by recipe's call for them
    const double LOAVES_POSSIBLE_PER_PACKAGE = 1.28751;
    
    double neededPacksYeast;
    double amtLoavesNeeded = (float (amtPpl) / PEOPLE_SUPPLIED_PER_LOAF);
   
    // Finds how many packs of yeast based on the number loaves possible per package
    neededPacksYeast = (ceil(amtLoavesNeeded) / LOAVES_POSSIBLE_PER_PACKAGE);
    
    return ceil(neededPacksYeast);
}

double amountSalt(int amtPpl) {
   
    /* Found by converting total grams in a canister to teaspoons, 
     and dividing that by the recipe's call for teaspoons (6 / 1.875) */
    const double LOAVES_POSSIBLE_PER_CANISTER = 3.2;
    
    double neededCanSalt;
    double amtLoavesNeeded = (float (amtPpl) / PEOPLE_SUPPLIED_PER_LOAF);
    
    neededCanSalt = (ceil(amtLoavesNeeded) / LOAVES_POSSIBLE_PER_CANISTER);
    
    return ceil(neededCanSalt);
}

double amountOliveOil(int amtPpl) {
    
    /* Found by dividing total milliliters of bottle by recipe call for tablespoons, 
     which were converted into millileters (1 tbsp = 14.8ml) */
    const double LOAVES_POSSIBLE_PER_BOTTLE = 16.8918;
    
    double neededBottlesOil;
    double amtLoavesNeeded = (float (amtPpl) / PEOPLE_SUPPLIED_PER_LOAF);
    
    // Finds how many bottles based on number of loaves possible per bottle
    neededBottlesOil = (ceil(amtLoavesNeeded) / LOAVES_POSSIBLE_PER_BOTTLE);
    
    return ceil(neededBottlesOil);
}

string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}
