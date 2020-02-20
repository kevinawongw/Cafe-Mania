// CSCI1300 Fall 2018
// Author: <Kevina Wong>
// Recitation: <123> – <Richard Tillquist>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/kevinawongw/csci1300>
// hmwk9 / Project3

#include <iostream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include "Computer.h"
#include "Customer.h"
#include "Drinks.h"
#include "Game.h"
#include "Player.h"
using namespace std;

/*
1.) http://www.cplusplus.com/reference/vector/vector/
#Refreshed how to use vectors

2.)https://www.tutorialspoint.com/cplusplus/cpp_goto_statement.htm
#Showed me how to go to a label

3.)http://www.cplusplus.com/reference/sstream/stringstream/
#Refreshed how to use stringstreams

4.)http://www.cplusplus.com/reference/algorithm/sort/
#Showed me how to sort a vector in ascending/descending order

5.)Worked with Kyle Zhou to help fix an error in my viewPlayerStats method.

*/

void displayMenu(){
     cout << "Select a numerical option:" << endl;
     cout << "======Main Menu=====" << endl;
     cout << "1. Play Game!" << endl;
     cout << "2. Meet Customers" << endl;
     cout << "3. View Cafe Menu" << endl;
     cout << "4. Practice Mode - Learn your customers!" << endl;
     cout << "5. View Scores" << endl;
     cout << "6. View Player Stats" << endl;
     cout << "7. Read Rules" << endl;
     cout << "8. Feeling Lucky? Select Me ! (͡° ͜ʖ ͡°)" << endl;
     cout << "9. Quit" << endl;
}

Player makePlayer (string username){
     
     //Reads a file
     string leaderboard; //defines a new string called recipe
     ifstream file; //makes file in an ifstream 
     file.open ("Records.txt");
     string name;
     vector<int> v;
     bool found = false;
     if (file.is_open()){ //if file is open
          while(getline(file, leaderboard)){ //use getline function
               stringstream s;
               s << leaderboard;
               string scores;
               int i = 0;
               s>>name;
               
               //Finds if the player already exists
               if(name == username){
                    cout << "Welcome back, Barista "<< username << "!" << endl;
                    s>>scores;
                    stringstream sscores;
                    string score;
                    sscores << scores;
                    
                    
                    //Puts the player's scores into a vector
                    while(getline(sscores, score, ',')){
                         v.push_back(stoi(score));
                    }
                    found = true;
                    break;
               }
               s.clear();
          }
     }    
     
     //If the player is found, it creates a player object with the username and the score
     if(found){
          Player p(username, v);
          return p;
     }
     
     //If the player is not found, it creates a player object with just the usernames
     else{
          Player p;
          p.setUsername(username);
          return p;
     }
}


int main(int argc, char const *argv[])
{
     string choice;
     Game game;
     srand(time(NULL));
     while (choice != "9") {
          int count, newRating;
          string username, customer,name;
          displayMenu();
          cin >> choice;
          cin.ignore();
          int choiceNum = stoi(choice);
          Player p;
          stringstream g;
          
          START:switch (choiceNum) {
          case 1:
               cout << "Enter your name: " << endl;
               cin >> username;
               cin.ignore();

               game.playGame(makePlayer(username));
               break;
          case 2:
               // cout << "Enter a Customer:" << endl;
               // cin >> username;
               // cin.ignore();
               game.meetCustomers ();
               cout << endl;
               break;
          case 3:
               game.readDrinks("Drinks.txt");
               game.viewCafeMenu();
               break;
          case 4:
               cout << "Enter your name:" << endl;
               cin >> username;
               cin.ignore();
               game.practiceMode (username);
               cout << endl;
               break;
          case 5:
               game.viewLeaderboard("Records.txt");
               cout << endl;
               break;
          case 6:
               cout <<"Enter a player's name: "<< endl;
               cin >> name;
               game.viewPlayerStats(name);
               break;
          case 7:
               game.readRules();
               break;
          case 8:
               choiceNum = (rand() %7) + 1;
               goto START;
               break;
          case 9:
               cout << "Thanks for Playing!" << endl;
               break;
          default:
               break;
        }
   } 
    return 0;
}
