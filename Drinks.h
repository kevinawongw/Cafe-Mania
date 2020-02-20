// CSCI1300 Fall 2018
// Author: <Kevina Wong>
// Recitation: <123> – <Richard Tillquist>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/kevinawongw/csci1300>
// hmwk 9 - Text-based game project

#include <iostream>
#include <string>
using namespace std;

#ifndef DRINKS_H
#define DRINKS_H

class Drinks{
    public:
    Drinks ();
    Drinks (string myDrinkType, string mySugarAmount, string myMilkAmount, string myFlavorType, string myFlavorAmount);
    
    string getDrinkType ();
    void setDrinkType (string myDrinkType);
    string getSugarAmount ();
    void setSugarAmount (string mySugarAmount);
    string getMilkAmount ();
    void setMilkAmount (string myMilkAmount);
    string getFlavorType ();
    void setFlavorType (string myFlavorType);
    string getFlavorAmount ();
    void setFlavorAmount (string myFlavorAmount);
    
    private:
    string drinkType;
    string sugarAmount;
    string milkAmount;
    string flavorType;
    string flavorAmount;
};

#endif 