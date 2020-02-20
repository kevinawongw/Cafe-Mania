// CSCI1300 Fall 2018
// Author: <Kevina Wong>
// Recitation: <123> – <Richard Tillquist>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/kevinawongw/csci1300>
// hmwk 9 - Text-based game project

#include "Drinks.h"

Drinks :: Drinks (){
    string drinkType = "";
    sugarAmount = "";
    milkAmount = "";
    flavorType = "";
    flavorAmount = "";
}

Drinks :: Drinks (string myDrinkType, string mySugarAmount, string myMilkAmount, string myFlavorType, string myFlavorAmount){
    drinkType = myDrinkType;
    sugarAmount = mySugarAmount;
    milkAmount = myMilkAmount;
    flavorType = myFlavorType;
    flavorAmount = myFlavorAmount;
}

string Drinks :: getDrinkType(){
    return drinkType;
}

void Drinks :: setDrinkType (string myDrinkType){
    drinkType = myDrinkType;
}

string Drinks :: getSugarAmount(){
    return sugarAmount;
}

void Drinks :: setSugarAmount (string mySugarAmount){
    sugarAmount = mySugarAmount;
}

string Drinks :: getMilkAmount(){
    return milkAmount;
}

void Drinks :: setMilkAmount (string myMilkAmount){
    milkAmount = myMilkAmount;
}

string Drinks :: getFlavorType(){
    return flavorType;
}

void Drinks :: setFlavorType (string myFlavorType){
    flavorType = myFlavorType;
}

string Drinks :: getFlavorAmount (){
    return flavorAmount;
}

void Drinks :: setFlavorAmount (string myFlavorAmount){
    flavorAmount=myFlavorAmount;
}
