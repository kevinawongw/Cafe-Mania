// CSCI1300 Fall 2018
// Author: <Kevina Wong>
// Recitation: <123> – <Richard Tillquist>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/kevinawongw/csci1300>
// hmwk 9 - Text-based game project

#include "Player.h"

Player :: Player (){
    string username = "";
    score =0;
}

Player :: Player (string myUsername, vector<int> myScores){
    username = myUsername;
    score=0;
    allScores = myScores;
}

string Player :: getUsername (){
    return username;
}

void Player :: setUsername(string myUsername){
    username = myUsername;
}

vector<int> Player :: getAllScores(){
    return allScores;
}

void Player :: addScore( int value){
    allScores.push_back(value);
}

int Player::getScore(){
    return score;
}

void Player::setScore(int myScore){
    score = myScore;
}