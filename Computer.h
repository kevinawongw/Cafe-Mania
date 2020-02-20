// CSCI1300 Fall 2018
// Author: <Kevina Wong>
// Recitation: <123> – <Richard Tillquist>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/kevinawongw/csci1300>
// hmwk 9 - Text-based game project

#include <iostream>
#include <string>
using namespace std;

#ifndef COMPUTER_H
#define COMPUTER_H

class Computer{
    public:
    Computer ();
    Computer (string myusername, int myScores[], int myNumScores);
    
    string getUsername();
    void setUsername(string myUsername);
    int getScoreAt(int index);
    bool setScoreAt(int index, int value);
    int getNumScores();
    void setNumScores (int myNumScores);
    
    private:
    string username;
    int scores [200];
    int numScores;
};
#endif