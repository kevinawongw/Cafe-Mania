// CSCI1300 Fall 2018
// Author: <Kevina Wong>
// Recitation: <123> – <Richard Tillquist>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/kevinawongw/csci1300>
// hmwk 9 - Text-based game project

#ifndef GAME_H
#define GAME_H

#include "Drinks.h"
#include "Customer.h"
#include "Player.h"

class Game{
    public:
    Game ();
    int playerTurn();
    void meetCustomers();
    void viewCafeMenu();
    void viewLeaderboard(string fileName);
    int practiceMode(string username);
    void viewPlayerStats (string username);
    void readDrinks (string drinkFile);
    void readCustomers (string customerFile);
    int computerTurn ();
    void readRules ();
    bool checkDrinkType (int customerIndex, string DrinkType);
    int checkSugar(int customerIndex, string sugarAmt);
    int checkMilk(int customerIndex, string milkAmt);
    bool checkFlavorType (int customerIndex, string flavorType);
    int checkFlavorAmt (int customerIndex, string flavorAmount);
    int playGame(Player p);
    
    string toUpperCase(string str);

    private:
    Drinks drinks [200];
    Customer customer [35];
    int numScores;
    int numPlayers;
};
#endif