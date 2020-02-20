// CSCI1300 Fall 2018
// Author: <Kevina Wong>
// Recitation: <123> – <Richard Tillquist>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/kevinawongw/csci1300>
// hmwk 9 - Text-based game project

#include "Computer.h"

Computer :: Computer (){
    string username = "";
    numScores = 0;
    for (int i = 0; i < 200; i++){
        scores [i] = -1;
    }
}

Computer :: Computer (string myUsername, int myScores [200], int myNumScores){
    username = myUsername;
    for (int i = 0; i < 200; i++){
        scores [i] = myScores[i];
    }
    numScores = myNumScores;
}

string Computer :: getUsername (){
    return username;
}

void Computer :: setUsername(string myUsername){
    username = myUsername;
}

int Computer :: getScoreAt(int index){
    int scoreAt;
    if (index >= 200){
        return -1;
    }
    else{
        return scores[index];
    }
}

bool Computer :: setScoreAt (int index, int value){
    if (index < 200){ // if the index is less than 200 and the vakue is between zero and five
        scores [index] = value; // the ratings at the index is equal to the value
        return true; //bool: return true
    }
    else{
        return false; //bool: return false
    }
}

int Computer :: getNumScores (){
    return numScores;
}

void Computer :: setNumScores (int myNumScores){
    numScores = myNumScores;
}