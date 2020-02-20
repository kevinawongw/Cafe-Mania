// CSCI1300 Fall 2018
// Author: <Kevina Wong>
// Recitation: <123> – <Richard Tillquist>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/kevinawongw/csci1300>
// hmwk 9 - Text-based game project

#include "Customer.h"

Customer :: Customer(){
    string username = "";
    favoriteDrink = "";
    sugarPreference = "";
    milkPreference = "";
    flavorType = "";
    flavorAmount = "";
}

Customer :: Customer (string myUsername, string myFavoriteDrink, string mySugarPreference, string myMilkPreference, string myFlavorType, string myFlavorAmount){
    username = myUsername;
    favoriteDrink = myFavoriteDrink;
    sugarPreference = mySugarPreference;
    milkPreference = myMilkPreference;
    flavorAmount = myFlavorAmount;
    flavorType = myFlavorType;
}

string Customer :: getUsername (){
    return username;
}

void Customer :: setUsername (string myUsername){
    username = myUsername;
}

string Customer :: getFavoriteDrink (){
    return favoriteDrink;
}

void Customer :: setFavoriteDrink (int myFavoriteDrink){
    favoriteDrink = myFavoriteDrink;
}

string Customer :: getSugarPrefernce (){
    return sugarPreference;
}

void Customer :: setSugarPreferece (int mySugarPreference){
    sugarPreference = mySugarPreference;
}

string Customer :: getMilkPrefernce (){
    return milkPreference;
}

void Customer :: setMilkPreferece (int myMilkPreference){
    milkPreference = myMilkPreference;
}

string Customer :: getFlavorAmount (){
    return flavorAmount;
}

void Customer :: setFlavorAmount (int myFlavorAmount){
    flavorAmount = myFlavorAmount;
}

string Customer :: getFlavorType (){
    return flavorType;
}

void Customer :: setFlavorType (string myFlavorType){
    flavorType = myFlavorType;
}




