// CSCI1300 Fall 2018
// Author: <Kevina Wong>
// Recitation: <123> – <Richard Tillquist>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/kevinawongw/csci1300>
// hmwk 9 - Text-based game project

#include <iostream>
#include <string>
using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer{
    public:
    Customer ();
    Customer (string myUsername, string myFavoriteDrink, string mySugarPreference, string myMilkPreference, string myFlavorType, string myFlavorAmount);
    
    string getUsername();
    void setUsername(string myUsername);
    string getFavoriteDrink();
    void setFavoriteDrink(int myFavoriteDrink);
    string getSugarPrefernce();
    void setSugarPreferece(int mySugarPreference);
    string getMilkPrefernce();
    void setMilkPreferece(int myMilkPreference);
    string getFlavorAmount();
    void setFlavorAmount(int myFlavorAmount);
    string getFlavorType();
    void setFlavorType (string myFlavorType);
    
    private:
    string username;
    string favoriteDrink;
    string sugarPreference;
    string milkPreference;
    string flavorAmount;
    string flavorType;
};
#endif