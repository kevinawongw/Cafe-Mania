// CSCI1300 Fall 2018
// Author: <Kevina Wong>
// Recitation: <123> – <Richard Tillquist>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/kevinawongw/csci1300>
// hmwk 9 - Text-based game project

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player{
    public:
    Player ();
    Player (string myUsername, vector<int> myScores);
    
    string getUsername ();
    void setUsername (string myUsername);
    vector<int> getAllScores();
    void addScore(int value);
    int getScore();
    void setScore(int myScore);

    private:
    int score;
    string username;
    std::vector<int> allScores;
};
#endif