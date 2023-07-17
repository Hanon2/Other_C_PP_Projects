#include <iostream>
#include <cmath>
#include <vector>
#include "fooditem.h"
using namespace std;
int input1; // an integer to take the input of the user
int counter = 0; // a counter to count through the while loop, if the input
int i;
int main() {
    // declared vectors that has the details for the prepopulated items
    vector<string> foodVec = {"Apple","Orange","Ramen","Nuggets","Spaghetti","Grapes","Water melon","Meat","Chicken breast","Snickers"};
    vector<double> caloriesVec = {20,30,40,50,60,70,80,90,100,10};
    vector<double> fatsVec = {10,15,20,25,30,35,40,45,50,55};
    vector<double> sugarVec = {1,2,3,4,5,6,7,8,9,10};
    vector<double> protienVec = {30,60,70,20,40,20,50,10,90,5};
    vector<double> sodiumVec = {3,1,5,6,7,9,10,11,12,13};
    vector<double> energyvec = {200,300,400,600,700,100,500,1000,1100,1200};
    // declared variables for the user if he/she will input a custom item
    string name_input;
    double calories_input;
    double fat_input;
    double sugar_input;
    double protien_input;
    double sodium_input;
    double energy_input;

    vector<fooditem> store_choices; // a vector that stores the choices of the user
    vector<fooditem> item_storage; // a vector that stores the 10 prepopulated items
    // declare 10 differnet objects using the prepopulated values in the vectors 
    fooditem appleObj(energyvec[0],fatsVec[0],sugarVec[0],protienVec[0],sodiumVec[0],foodVec[0]);
    fooditem orangOobj(energyvec[1],fatsVec[1],sugarVec[1],protienVec[1],sodiumVec[1],foodVec[1]);
    fooditem ramenObj(energyvec[2],fatsVec[2],sugarVec[2],protienVec[2],sodiumVec[2], foodVec[2]);
    fooditem nuggetsObj( energyvec[3],fatsVec[3],sugarVec[3],protienVec[3],sodiumVec[3],foodVec[3]);
    fooditem spaghettiObj(energyvec[4],fatsVec[4],sugarVec[4],protienVec[4],sodiumVec[4],foodVec[4]);
    fooditem grapesObj( energyvec[5],fatsVec[5],sugarVec[5],protienVec[5],sodiumVec[5],foodVec[5]);
    fooditem watermelonObj(energyvec[6],fatsVec[6],sugarVec[6],protienVec[6],sodiumVec[6],foodVec[6]);
    fooditem meatObj(energyvec[7],fatsVec[7],sugarVec[7],protienVec[7],sodiumVec[7],foodVec[7]);
    fooditem chickenObj(energyvec[8],fatsVec[8],sugarVec[8],protienVec[8],sodiumVec[8],foodVec[8]);
    fooditem snickersObj(energyvec[9],fatsVec[9],sugarVec[9],protienVec[9],sodiumVec[9],foodVec[9]);
    fooditem total(0, 0, 0, 0, 0, "total");
    // store the items in the vector
    item_storage.push_back(appleObj);
    item_storage.push_back(orangOobj);
    item_storage.push_back(ramenObj);
    item_storage.push_back(nuggetsObj);
    item_storage.push_back(spaghettiObj);
    item_storage.push_back(grapesObj);
    item_storage.push_back(watermelonObj);
    item_storage.push_back(meatObj);
    item_storage.push_back(chickenObj);
    item_storage.push_back(snickersObj);

    cout << "Welcome to nutrition calculator\n" << "please select one of the following options" << endl;

    while (counter == 0) {
        for (i = 0; i <= item_storage.size() - 1; ++i) {
            // a for loop to print out the items
            cout << i << "- " << item_storage.at(i).getFood() << endl;
            if (i == item_storage.size() - 1) {
                cout << i + 1 << "- Enter a new food item" << endl;
                cout << i + 2 << "- Finish adding items" << endl;
            }
        }

        cin >> input1; // take the input of the user

        if (input1 == 0) {
            store_choices.push_back(appleObj);
        } else if (input1 == 1) {
            store_choices.push_back(orangOobj);
        } else if (input1 == 2) {
            store_choices.push_back(ramenObj);
        } else if (input1 == 3) {
            store_choices.push_back(nuggetsObj);
        } else if (input1 == 4) {
            store_choices.push_back(spaghettiObj);
        } else if (input1 == 5) {
            store_choices.push_back(grapesObj);
        } else if (input1 == 6) {
            store_choices.push_back(watermelonObj);
        } else if (input1 == 7) {
            store_choices.push_back(meatObj);
        } else if (input1 == 8) {
            store_choices.push_back(chickenObj);
        } else if (input1 == 9) {
            store_choices.push_back(snickersObj);
        } else if (input1 == i) { // take input from user if he/she wants to add an item
            cout << "Enter item name" << endl;
            cin >> name_input;
            cout << "Enter calories" << endl;
            cin >> calories_input;
            cout << "Enter fats (g)" << endl;
            cin >> fat_input;
            cout << "Enter sugar (g)" << endl;
            cin >> sugar_input;
            cout << "Enter protien (g)" << endl;
            cin >> protien_input;
            cout << "Enter sodium (mg)" << endl;
            cin >> sodium_input;
            cout << "Enter energy" << endl;
            cin >> energy_input;
            fooditem new_Obj(energy_input,fat_input,sugar_input,protien_input,sodium_input,name_input);
            item_storage.push_back(new_Obj);
            store_choices.push_back(new_Obj);
        } else if (input1 == i + 1) { // finish adding items and calculate
            for (int count = 0; count <= store_choices.size() - 1; ++count) {
                if (count == 0) {
                    total = store_choices.at(count);
                } else {
                    total += store_choices.at(count);
                }
            }
            total.print();

            ++counter;
        }

    }
}
