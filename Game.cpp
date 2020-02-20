// CSCI1300 Fall 2018
// Author: <Kevina Wong>
// Recitation: <123> – <Richard Tillquist>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/kevinawongw/csci1300>
// hmwk 9 - Text-based game project

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include "Computer.h"
#include "Customer.h"
#include "Drinks.h"
#include "Game.h"
#include "Player.h"

using namespace std;

//Global Variables
int computerTurn();
int playerTurn();
int totalScore=0;
int robotTotal=0;
int totalScoreArr[200];



/* split function
 * the function to split the given string into array of string with respect to a delimiter
 *
 * @param : string , the string we are going to split
 * @param : char, the delimiter
 * @param : string array, the array of string we save after spliting
 * @param : int, size of the  indicates the maximum number of split-apart string pieces
*/
 
int split (string str, char c, string array[], int size)
 {
    if (str.length() == 0) {
         return 0;
     }
    string word = "";
    int count = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return count ;
 }

//Default Constructor::
Game :: Game (){
    numScores = 0; 
    numPlayers=0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
//Member Function #1: playerTurn
/** Function: 
 * Call member functions readDrinks and readCustomers.
 * Prompt the player to enter a username.
 * Randomly generate a number 
 * Find the customer at that randomly generated inndex (this customer will enter the cafe).
 * Promt the user to enter a drink name
 * If the drink name matches, the customer's drink preference, continue.
 * If it doesn't match, the customer leaves and the player gets +0 for that round. 
 * If it does, it will keep asking until the user imputs the correct drink.
 * Promt the user to enter a flavor type,
 * If Flavor matches, +1
 * If it does not, +0
 * Promt user to enter amount of sugar, milk, and flavor amount:
 * If the number is correct, +2 points 
 * If the number is off by one, +1 point
 * If the number is off by two or more, +0 points.
 * Print satisfaction statements 
 * End the Player's turn.
 **/
 
int Game :: playerTurn (){

srand ( time(NULL) ); 
//read files for drinks and customers
readCustomers("Customers.txt");
readDrinks("Drinks.txt");

// initializes score equal to zero
int score = 0;

//Makes random customer enter by genrating a random customer index
int customerIndex = (rand() %35);
cout << customer[customerIndex].getUsername() << " has entered Happy Cafe!" << endl;
cout << customer[customerIndex].getUsername () << ": Hello! I'd like to order a " << customer[customerIndex].getFavoriteDrink() << " please!" << endl << endl;

//Promp user to enter drink name and calls the checkDrink method
cout << "What drink will you be making for " << customer[customerIndex].getUsername() << "?" << endl;
string drinkName;
getline(cin,drinkName);

//If the user types in the correct drink:
    if (checkDrinkType(customerIndex, drinkName) == true){
        //+1 Point for typing in the right drink
        score=1;
        
        //Promt the user to enter an amount of sugar packets and calls the checkSugar method to check if the amount of sugar is correct for that customer
        cout << "How many sugar packets does " << customer[customerIndex].getUsername() << " want? (Select 1-5 Packets)" << endl;
        string sugar;
        getline (cin, sugar);
        
        //If it's exactly correct, +2 points
        if (checkSugar(customerIndex, sugar) == 1){
            score=score+2;
        }
        
        //If it's off my 1, +1 point
        else if (checkSugar(customerIndex, sugar) == 2 || checkSugar(customerIndex, sugar) == 3){
            score++;
        }
        
        //If it's off by 2 or more, +0 points
        else if (checkSugar(customerIndex, sugar) == 4) {
            score =score;
        }
        
        //Prompt the user to enter an amount of milk and calls the checkMilk method to check if the amount of milk is correct.
        cout << "How many oz of milk does " << customer[customerIndex].getUsername() << " want? (Select 1-5 oz)" << endl;
        string milk;
        getline (cin, milk);
        
        //If the milk amount is exactly correct +2 points
        if (checkMilk(customerIndex, milk) == 1){
            score = score+2;
        }
        
        //If the milk amount is off by one, +1 point.
        else if (checkMilk(customerIndex, milk) == 2 || checkMilk(customerIndex, milk) == 3){
            score ++;
        }
        
        //If the milk amount is off by 2 or more, +0 points
        else if (checkMilk(customerIndex, milk) == 4){
            score=score;
        } 
        
        //Promt the user to enter a flavor name and call checkFlavorType to see if it's correct
        cout << "What flavoring does " << customer[customerIndex].getUsername() << " want? (Refer to the Cafe Menu to see Happy Cafe's flavors!)" << endl;
        string flavoring;
        getline (cin, flavoring);
        
        //If its correct, + 1 Point
        if (checkFlavorType(customerIndex, flavoring) == true){
            score++;
        }
        
        // If it's incorrect, +0 Points
        else {
            score=score;
        }    
        
        //Promt the user to enter an amonunt of flavoring. Call the checkFlavorAmount method to check if that amount is correct.
        cout << "How many pumps of flavoring does " << customer[customerIndex].getUsername() << " want? (Select 1-5 pumps)" << endl;
        string flavor;
        getline (cin, flavor);
        
        //If it's exactly correct, +2 points
        if (checkFlavorAmt(customerIndex, flavor) == 1){
            score = score+2;
        }
        
        //If it's off by one, +1 Point
        else if (checkFlavorAmt(customerIndex, flavor) == 2 || checkFlavorAmt(customerIndex, flavor) == 3){
            score++;
        }
        
        // If it's off by 2 or more, +0 points.
        else if (checkFlavorAmt(customerIndex, flavor) == 4){
            score=score;
        }    
        
        //Prints out satisfaction statements depending on score earned from each ingredient : 
        cout << "How was your Drink, " << customer[customerIndex].getUsername() << "? :)" << endl << endl;
        cout << customer[customerIndex].getUsername() <<": "<< endl;
        if (checkSugar(customerIndex, sugar) == 1){
            cout << "The level of sugar in my drink was perfect! +2 Points "  << endl;
        }
        else if (checkSugar(customerIndex, sugar) == 2){
            cout << "My drink was a little too sweet. Maybe a little less sugar next time? +1 Point" << endl;
        }
        else if (checkSugar(customerIndex, sugar) == 3){
            cout << "I'd like a little more sugar next time. +1 Point" << endl;
        }
        else if (checkSugar(customerIndex, sugar) == 4){
            cout << "The sugar level was totally off!  :( +0 Points" << endl;
        }
        
        if (checkMilk(customerIndex, milk) == 1){
            cout << "The amount of milk in here is great! It couldn't be better! +2 Points" << endl;
        }
        else if (checkMilk(customerIndex, milk) == 2){
            cout << "Theres a little too much milk in my drink +1 Point" << endl;
        }
        else if (checkMilk(customerIndex, milk) == 3){
            cout << "This would be better with a little more milk +1 Point" << endl;    
        }    
        else if (checkMilk(customerIndex, milk) == 4){
            cout << "There's totally the wrong amount of milk in my drink! :( +0 Point" << endl;
        }    
        if (checkFlavorType(customerIndex, flavoring) == true){
            cout << "The flavor in this drink is great! +1 Point" << endl;
        }
        else {
            cout << "The flavor in my drink is a litte weird ಠ.ಠ +0 Points" << endl;
        }    
        
        if (checkFlavorAmt(customerIndex, flavor) == 1){
            cout << "There was a good amount of flavoring +2 Points" << endl;
        }
        else if (checkFlavorAmt(customerIndex, flavor) == 2){
            cout << "The flavoring was a bit too strong +1 Point" << endl;
        }
        else if (checkFlavorAmt(customerIndex, flavor) == 3){
            cout << "I wish there was a little more flavoring +1 Point" << endl;
        }    
        else if (checkFlavorAmt(customerIndex, flavor) == 4){
            cout << "The amount of flavoring was way off :/ +0 Points" << endl;
        }    
        
        //Prints out the satisfaction statement based on the overall total:
        cout << "Overall Satisfaction: " << endl;
        if (score == 1){
            cout << "My drink was so bad (ಥ﹏ಥ)"  <<endl;
        }
        else if (score > 1 && score <= 4 ){
            cout << "My drink was okay ʘ‿ʘ" << endl;
        }
        else if (score > 4 && score < 8){
            cout << "My drink was pretty good ಠ‿↼" << endl;
        }
        if (score == 8 ){
            score = 10;
            cout << "My drink was perfect!! (☞ﾟ∀ﾟ)☞" << endl;
        }
        cout << endl << "Customer Score: " << endl << score << endl << endl;
    }
    
    //If you made the wrong drink in the beginning
    else {
        cout << "The angry customer has left... ಠ╭╮ಠ" << endl << endl;
        score = 0;
    }
//TotalScore is eaqual to the sum of scores
totalScore += score;

//return score
return score;    
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//Member Function #2: meetCustomers
/** Function: meetCustomers 
 * @param: string username
 * call read customerFile
 * Promt the user to enter a username (in hmwk9.cpp)
 * Loop through every customer index to find the name that matches the parameter name.
 * Print the following:
 * Name:
 * Sugar Preference:
 * Milk: Preference:
 * Flavor Type Preference:
 * Flavor Amount Preference:
 * If the Username cannot be found, print:
 * "[name] has never visited the Cafe."
 **/
 
void Game :: meetCustomers (){
    //call the readCustomers method
    readCustomers("Customers.txt");
    
    cout << "What would you like to do? " << endl << "1.) Enter a customer " << endl << "2.) Meet a random customer" << endl << endl;
    string answer;
    cin >> answer;
    if (answer == "1"){
        cout << "Enter a customer name: " << endl;
        string username;
        cin >> username;
        
        //initialized customerIndex equal to -1
        int customerIndex = -1; 
        
        //Loops through every customer and finds the customer username that matches the parameter username. Sets that index equal to the customer index
        for (int i = 0; i < 35; i++){
            string usernameAt = customer[i].getUsername(); //usernameAt is equal to the username at the index
            if (toUpperCase (usernameAt) == toUpperCase (username)){ //if the username at the index is equal to the username 
                customerIndex = i; //customerIndex is the index where the user is found
            }
        
        //If it customer is not found in the array of customers:    
        }    
        if (customerIndex == -1){ //if the customerIndex =-1
            cout << username << " has never visted the cafe! " << endl; //output statement
            return;
        }
        
        // Print preferences for that customer 
        cout << "Meet " << username << "!" << endl << endl;
        cout << "Favorite Drink : " << customer[customerIndex].getFavoriteDrink() << endl; //output statement
        cout << "Sugar Preference : " << customer[customerIndex].getSugarPrefernce() << endl; //output statement
        cout << "Milk Preference : " << customer[customerIndex].getMilkPrefernce() << endl;
        cout << "Flavor Preference : " << customer[customerIndex].getFlavorType() << endl;
        cout << "Flavor Amount : " << customer[customerIndex].getFlavorAmount() << endl;
        cout << "-----" << endl; //outtput statement
    }  
    else {
        int customerIndex = (rand() %35);
        cout << "Meet " << customer[customerIndex].getUsername() << "!" << endl << endl;
        cout << "Favorite Drink : " << customer[customerIndex].getFavoriteDrink() << endl; //output statement
        cout << "Sugar Preference : " << customer[customerIndex].getSugarPrefernce() << endl; //output statement
        cout << "Milk Preference : " << customer[customerIndex].getMilkPrefernce() << endl;
        cout << "Flavor Preference : " << customer[customerIndex].getFlavorType() << endl;
        cout << "Flavor Amount : " << customer[customerIndex].getFlavorAmount() << endl;
        cout << "-----" << endl; //outtput statement
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//Member Function #3: viewCafeMenu
/** Function: viewCafeMenu
 * Call readDrinks function
 * Loop through each drink and print out:
 * Drink Name
 * Sugar Amount
 * Milk Amount
 * Flavor Type
 * Flavor Amount
 **/
 
void Game :: viewCafeMenu (){
    //Call readDrinks method
    Game :: readDrinks("Drinks.txt");
    
    //Print out cafe menu and how much of each ingredient it uses (even numbers)
    cout << "Happy Cafe Menu: " << endl << endl;
    for (int i = 0; i < 30; i++){
        if (drinks[i].getDrinkType().length() != 0){
            cout << drinks[i].getDrinkType() << endl;
            cout << "Sugar Packets: " << drinks[i].getSugarAmount() << endl;
            cout << "Milk Amount: " << drinks[i].getMilkAmount() << endl;
            cout << "Flavoring: " << drinks[i].getFlavorType() << endl;
            cout << "Flavor Amount: " << drinks[i].getFlavorAmount() << endl << endl;
            i++;
        }    
    } 
    //Print out cafe menu and how much of each ingredient it uses (odd numbers) -- fixes bug
    for (int i = 1; i < 30; i++){
        if (drinks[i].getDrinkType().length() != 0){
            cout << drinks[i].getDrinkType() << endl;
            cout << "Sugar Packets: " << drinks[i].getSugarAmount() << endl;
            cout << "Milk Amount: " << drinks[i].getMilkAmount() << endl;
            cout << "Flavoring: " << drinks[i].getFlavorType() << endl;
            cout << "Flavor Amount: " << drinks[i].getFlavorAmount() << endl << endl;
            i++;
        }
    } 

    //Print out flavor options
    cout << endl << "Flavor Shot Options: " << endl;
    cout << "None" << endl;
    cout << "Chocolate" << endl;
    cout << "Chai" << endl;
    cout << "Vanilla" << endl;
    cout << "Carmel" << endl;
    cout << "Pumpkin Spice" << endl;
    cout << "Matcha" << endl;
    cout << "Black Tea" << endl;
    cout << "Grean Tea" << endl;
    cout << "Jasmine Tea" << endl;
    cout << "Thai Tea" << endl;
    cout << "Strawberry" << endl;
    cout << "Mango" << endl;
    cout << "Sea Salt" << endl;
    cout << "Remember that these are just the standard cafe recipes! Each customer may have their own personal preference. " << endl;
}
 
 
///////////////////////////////////////////////////////////////////////////////////////////////////
//Member Function #4: viewLeaderboard
/** Function: viewLeaderboard
 * @param: string fileName
 * Parse the information from the file which should be filled with scores 
 * Print out Leaderboard
 **/
 
 void Game :: viewLeaderboard (string fileName){
    //Print opening statement
    cout << "Here are the player scores: " << endl;
    
    //Reads the file and parses information
    string leaderboard; //defines a new string called leaderboard
    ifstream file (fileName.c_str()); //makes file in an ifstream 
    if (file.is_open()){ //if file is open
        //print out all players and their scores  
        while(getline(file, leaderboard)){ //use getline function
            string info [2];
            split(leaderboard, ' ',info,2);
            string Rusername = info[0];
            string scores = info[1];
            cout << Rusername << "'s Score(s):" << endl << scores << endl;
        }    
    }
    //close file
    file.close();
 }
 
///////////////////////////////////////////////////////////////////////////////////////////////////
//Member Function #5: practiceMode
/** Function: practiceMode
 * @param: string Username
 * Asks the user if they would help a customer
 * call PlayerTurn function
 * Allows pllayer to keep helping customer until they select 2.) No in the menu of whether they would like to continue
 **/
 
int Game :: practiceMode (string username){
    srand ( time(NULL) );
    int customersHelped = 0;
    
    //Promts the player to select a menu option of whether they would like to help a customer.
    cout << "Do you want to help a customer?" << endl << "Select: " << endl << "1.) Yes! ☜(˚▽˚)☞ " << endl << "2.) No ರ.ರ" << endl << endl;
    string answer; 
    cin >> answer;
    cin.ignore();
    
    //If yes, call playeTurn to play the game until the player selects no. 
    if (answer== "1"){
        playerTurn();
    cout << "Do you want to help another customer?" << endl << "Select: " << endl << "1.) Yes! ☜(˚▽˚)☞ " << endl << "2.) No ರ.ರ" << endl << endl;
    cin >> answer;
    cin.ignore();
    
    //For everytime the player selects yes, add one to customersHelped
    customersHelped++;
    }
    
    //If the player selects no and would not like to continue
    else{
        return 0;
    }
    
    //Print closing statement
    cout << "You helped " << customersHelped << " customer(s)! " << endl << "Great Job!" << endl << endl;
} 
///////////////////////////////////////////////////////////////////////////////////////////////////

//Member Function #6: viewPlayerStats
/** Function: viewPlayerStats
 * @param: string username
 * Prompt the user to enter the username
 * If the player can be found in the player file/ leaderboard file,
 * print the player name, the player's max score, and how many times the player has played.
 **/
 
 void Game :: viewPlayerStats(string username){
    //Reads the file that holds the records of players 
    string leaderboard; //defines a new string called recipe
    ifstream file ("Records.txt"); //makes file in an ifstream 
    string name;
    vector<int> v;
    bool found = false;
    
    //Parse information to vector
    if (file.is_open()){ //if file is open
        while(getline(file, leaderboard)){ //use getline function
            stringstream s;
            s << leaderboard;
            string scores;
            int i = 0;
            s>>name;
            
            //If the name is found
            if(name == username){
                // Puts the user's score into vector v
                s>>scores;
                stringstream sscores;
                string score;
                sscores << scores;
                while(getline(sscores, score, ',')){
                     v.push_back(stoi(score));
                }
                
                found = true;
                break;
            }
            s.clear();
        }
    } 
    
    if(found){
        //Prints players's stats
        cout << "Here are " << username <<"'s stats: " << endl << endl;
        cout << "Times Played: " << v.size() << " Time(s)" << endl;
        sort(v.begin(), v.end());
        cout << "Max Score: " <<  v.back() << " Point(s) " << endl;
    }else{
         cout << username << " has never played before ( •̀ᄇ• ́)ﻭ✧"<<endl;
    }
}
 ///////////////////////////////////////////////////////////////////////////////////////////////////
//Member Function #7: readDrinks
/** Function: readDrinks
 * @param: string drinkFile
 * Open the file
 * Parse the information and put the different information sets into arrays
 * Create a temporary drink in a loop to keep adding drinks into the drinks array
 * return the number of drinks in the file
 **/
 
void Game :: readDrinks(string drinkFile){
    int i;
    const int sizeDrinks = 200; //defines and declares numberBooks as a const int and set to 30. 
    
    //Read file
    string recipe; //defines a new string called recipe
    ifstream file (drinkFile.c_str()); //makes file in an ifstream 
    if (file.is_open()){ //if file is open
    
        //Parse information into strings
        while(getline(file, recipe)){ //use getline function
            string recipeSplit[5]; //creates a new array with the size of 5
            split(recipe, ',', recipeSplit,5); //splits the file 
            string drinkName = recipeSplit[0]; 
            string sugarAmt = recipeSplit[1]; 
            string milkAmt = recipeSplit[2];
            string flavorName = recipeSplit [3];
            string flavorAmt = recipeSplit[4];
            
            //Creates drinks objects and adds them into the drinks array
            Drinks tempDrink(drinkName,sugarAmt,milkAmt,flavorName,flavorAmt); //creates a book called tempbook 
            if ( i < 200 ){ //if i is less than capacity
                drinks[i] = tempDrink;
            }
            
            //otherwise:
            else {
                break; //break
            }
            i++; //i+1
        }
    }
}

 ///////////////////////////////////////////////////////////////////////////////////////////////////
//Member Function #8: readCustomers
/** Function: readCustomers
 * @param:  string customerFile
 * Open the file
 * Parse the information and put the different information sets into arrays
 * Create a temporary customer in a loop to keep adding customers into the customer array
 * return the number of customer in the file
 **/
  
void Game :: readCustomers(string customerFile){
    int i=0;
    const int sizeCustomers = 35; //defines and declares numberBooks as a const int and set to 30. 
    
    //Read file
    string order; //defines a new string called recipe
    ifstream file (customerFile.c_str()); //makes file in an ifstream 
    if (file.is_open()){ //if file is open
        
        //Parse information and puts them into strings
        while(getline(file, order)){ //use getline function
            string orderSplit[6]; //creates a new array with the size of 5
            split(order, ',', orderSplit,6); //splits the file 
            string customerName = orderSplit[0];
            string drinkName = orderSplit[1]; 
            string sugarAmt = orderSplit[2]; 
            string milkAmt = orderSplit[3];
            string flavorName = orderSplit [4];
            string flavorAmt = orderSplit[5];
            //Creates customer objects and adds customers into the array
            Customer tempCustomer(customerName,drinkName,sugarAmt,milkAmt,flavorName,flavorAmt); 
            if (i < 35 ){ 
                customer[i] = tempCustomer;
                i++; //i+1
            }
            
            //otherwise:
            else {
                break; //break
            }
        }
    }
}    

///////////////////////////////////////////////////////////////////////////////////////////////////
//Member Function #9: computerTurn
/** Function: computerTurn
 * same Pseudocode as Member Function #1
 * Differences:
 * Computer will always select the correct drink type.
 * The computer will randomly generate a number (up to five) for the sugar, milk and flavor amount.
 * The computer will always select the correct flavor type.
 * The computer cannot be in the leaderboard. 
 * *Leaderboard consists of real players only. 
 **/
 
int Game :: computerTurn (){
    srand ( time(NULL) ); 
    //Call readDrinks and readCustomers methods
    readCustomers("Customers.txt");
    readDrinks("Drinks.txt");
    int Rscore=0;
    
    //Generates a random number for customerIndex (0-34) and generates random number for ingredient amount (0-5)
    int customerIndex = (rand() %35);
    string ingredientAmt[6] = {"0", "1", "2", "3","4","5"};
    int ingredientIndex =(rand() %5) + 1;
    
    //Prints customer actions
    cout << customer[customerIndex].getUsername() << " has entered Happy Cafe!" << endl;
    cout << customer[customerIndex].getUsername () << ": Hello! I'd like to order a " << customer[customerIndex].getFavoriteDrink() << " please!" << endl << endl;
    cout << "What drink will you be making for " << customer[customerIndex].getUsername() << "?" << endl;
    
    //Robot will always make the right drink
    cout << "The robot barista will be making " << customer[customerIndex].getFavoriteDrink() << endl << endl;
    Rscore=1;
    
    //Randomly generate a number for amount of sugar and calls checkSugar function to check if its correct
    cout << "How many sugar packets does " << customer[customerIndex].getUsername() << " want? (Select 1-5 Packets)" << endl;
    string sugar = ingredientAmt[ingredientIndex];
    
    //If it's exactly correct, +2 Points
    if (checkSugar(customerIndex, sugar) == 1){
        Rscore=Rscore+2;
        cout << sugar << " packets" << endl;
    }
    
    //If it's off by one, +1 points
    else if (checkSugar(customerIndex, sugar) == 2 || checkSugar(customerIndex, sugar) == 3){
        Rscore++;
        cout << sugar << " packets" << endl;
    }
    
    //If it's off by two or more, +0 Points
    else if (checkSugar(customerIndex, sugar) == 4){
        Rscore =Rscore;
         cout << sugar << " packets" << endl;
    }
    
    //Generates a random number for how much milk to add. Call the checkmilk method to see if it's correct
    cout << "How many oz of milk does " << customer[customerIndex].getUsername() << " want? (Select 1-5 oz)" << endl;
    string milk = ingredientAmt[ingredientIndex];
    
    //If it's exactly correct, +2 Points
    if (checkMilk(customerIndex, milk) == 1){
        Rscore = Rscore+2;
        cout << milk << " oz" << endl;
    }
    
    //If it's off by 1, +1 point
    else if (checkMilk(customerIndex, milk) == 2 || checkMilk(customerIndex, milk) == 3){
        Rscore ++;
         cout << milk << " oz" << endl;
    }
    
    //If it's off by two or more, +0 Points
    else if (checkMilk(customerIndex, milk) == 4){
        Rscore=Rscore;
        cout << milk << " oz" << endl;
    }    
    
    //Prints out what flavor the robot added (will always be correct)
    cout << "What flavoring does " << customer[customerIndex].getUsername() << " want? (Refer to the Cafe Menu to see Happy Cafe's flavors!)" << endl;
    cout << "The robot added " << customer[customerIndex].getFlavorType() << " into the drink" << endl;
    Rscore++;
    
    //Generates a random number for how much flavoring will be added and calls the checkFlavorAmt method to see if it's correct
    cout << "How many pumps of flavoring does " << customer[customerIndex].getUsername() << " want? (Select 1-5 pumps)" << endl;
    string flavor = ingredientAmt[ingredientIndex];
    
    //If it's exactly correct, +2 Points
    if (checkFlavorAmt(customerIndex, flavor) == 1){
        Rscore = Rscore+2;
         cout << flavor << " pumps" << endl;
    }
    
    //If its off by one, +1 Point
    else if (checkFlavorAmt(customerIndex, flavor) == 2 || checkFlavorAmt(customerIndex, flavor) == 3){
        Rscore++;
         cout << flavor << " pumps" << endl;
    }
    
    //If its off by 2 or more, +0 Points
    else if (checkFlavorAmt(customerIndex, flavor) == 4){
        Rscore=Rscore;
         cout << flavor << " pumps" << endl;
    }    
    
    
    //Prints out satisfaction statements based on scores earned from each ingredient
    cout << "Robot Barista: How was your Drink, " << customer[customerIndex].getUsername() << "? :)" << endl << endl;
    cout << customer[customerIndex].getUsername() <<": "<< endl;
    
    //Sugar
    if (checkSugar(customerIndex, sugar) == 1){
        cout << "The level of sugar in my drink was perfect! +2 Points "  << endl;
    }
    else if (checkSugar(customerIndex, sugar) == 2){
        cout << "My drink was a little too sweet. Maybe a little less sugar next time? +1 Point" << endl;
    }
    else if (checkSugar(customerIndex, sugar) == 3){
        cout << "I'd like a little more sugar next time. +1 Point" << endl;
    }
    else if (checkSugar(customerIndex, sugar) == 4){
        cout << "The sugar level was totally off!  :( +0 Points" << endl;
    }
    
    //Milk
    if (checkMilk(customerIndex, milk) == 1){
        cout << "The amount of milk in here is great! It couldn't be better! +2 Points" << endl;
    }
    else if (checkMilk(customerIndex, milk) == 2){
        cout << "Theres a little too much milk in my drink +1 Point" << endl;
    }
    else if (checkMilk(customerIndex, milk) == 3){
        cout << "This would be better with a little more milk +1 Point" << endl;    
    }    
    else if (checkMilk(customerIndex, milk) == 4){
        cout << "There's totally the wrong amount of milk in my drink! :( +0 Point" << endl;
    }    
    cout << "The flavor in this drink is great! +1 Point" << endl;
    
    //Flavor Amount
    if (checkFlavorAmt(customerIndex, flavor) == 1){
        cout << "There was a good amount of flavoring +2 Points" << endl;
    }
    else if (checkFlavorAmt(customerIndex, flavor) == 2){
        cout << "The flavoring was a bit too strong +1 Point" << endl;
    }
    else if (checkFlavorAmt(customerIndex, flavor) == 3){
        cout << "I wish there was a little more flavoring +1 Point" << endl;
    }    
    else if (checkFlavorAmt(customerIndex, flavor) == 4){
        cout << "The amount of flavoring was way off :/ +0 Points" << endl;
    }    
    
    //Prints overall Satisfaction based on total score.
    cout << "Overall Satisfaction: " << endl;
    if (Rscore == 1){
        cout << "My drink was so bad (ಥ﹏ಥ)"  <<endl;
    }
    else if (Rscore > 1 && Rscore <= 4 ){
        cout << "My drink was okay ʘ‿ʘ" << endl;
    }
    else if (Rscore > 4 && Rscore < 8){
        cout << "My drink was pretty good ಠ‿↼" << endl;
    }
    if (Rscore == 8 ){
        Rscore = 10;
        cout << "My drink was perfect!! (☞ﾟ∀ﾟ)☞" << endl;
    }
    cout << endl << "Robot's Customer Score: " << endl << Rscore << endl << endl;
    
    //Total score equals the sum of scores
    robotTotal+=Rscore;
    return Rscore;
}

 
///////////////////////////////////////////////////////////////////////////////////////////////////
//Member Function #10: readRules:
/** Function: readRules
 * Prints the rules of the game
 **/
void Game :: readRules (){
    
    cout << "What rules would you like to see?" << endl << "1.) General Rules " << endl << "2.) Competitive Mode" << endl << "3.) Practice Mode" << endl << endl;
    string answer; 
    cin >> answer;
    cin.ignore();
    
    if (answer == "1"){
        //Prints out rules for the game
        cout << "Welcome to Happy Cafe Barista Game!" << endl << endl;
        cout << "Here is how the point system works: " << endl;
        cout << "   Correct Drink: +1 Point" << endl;
        cout << "   Correct Amount of Sugar: +2 Points" << endl;
        cout << "   Correct Amomunt of Milk: +2 Points" << endl;
        cout << "   Correct Amount of Flavor: +2 Points" << endl;
        cout << "   Correct Flavor Type: +1 Point" << endl << endl;
        cout << "   If you make a perfect drink, you will get +2 bonus points! " << endl;
        cout << "   **If the number of sugar, milk, or flavor is off by 1: +1 Point**" << endl;
        cout << "   **If the number of sugar, milk, or flavor is off by 2 or more: +0 Points**" << endl << endl;
        cout << "4.) You can view the Happy Cafe menu to look at the standard recipes. " << endl;
        cout << "5.) Be Careful and Observant! Some customers have specific prefences which you will learn as you play the game more!" << endl;
        cout << "6.) There are two modes: " << endl << "Classic Mode (Play Game): Compete against a CPU and see who can get the highest score!" <<endl << "Practice Mode: Play by yourself to get to know customers and gain practice! " << endl << endl;
    }
    else if (answer == "2"){
        cout << "Competitive Mode: " << endl << endl;
        cout << "In this mode you'll be playing against Robot Barista" << endl;
        cout << "1.) Your goal is to get the highest score after serving 3 customers (3 rounds)." << endl;
        cout << "2.) You can get a maximum of 10 points per customer, and 30 points per game." << endl;
        cout << "Comptete against Robot Barista to beat it's score." << endl;
        cout << "See General Rules to learn about the scoring system" << endl <<endl;
    }
    else {
        cout << "Practice Mode: " << endl << endl;
        cout << "In this mode, you'll be playing by yourself and helping customers!" << endl;
        cout << "1.) Your points do not matter in this mode." << endl;
        cout << "2.) Keep helping more customers to gain practice and learn customer's orders!" << endl << endl;
    }
}    
///////////////////////////////////////////////////////////////////////////////////////////////////
//Member Function #11: checkDrinkType:
/** Function: checkDrinkType
 * @param: string drinkName
 * @Param: int customerIndex
 * Check to see if the drink name matches the customer's favorite drink
 * If the name mathches, +1 point.
 * If the name does not match, the customer leaves
 **/
 
 bool Game :: checkDrinkType (int customerIndex, string drinkType){
     
    //If the drink type matches (not caps sensitive):
    if (toUpperCase(drinkType) ==  toUpperCase(customer[customerIndex].getFavoriteDrink())){
        cout << "Correct! You gained +1 point for making the right drink for " << customer[customerIndex].getUsername() << endl << endl;     
        return true;
    }
    
    //If it doesn't:
    else{
        cout << customer[customerIndex].getUsername () << ": Thats not what I ordered >:( " << endl << "You gained +0 points for this customer." << endl;
        return false;
    }   
 }
 ///////////////////////////////////////////////////////////////////////////////////////////////////
//Member Function #12: checkSugar:
/** Function: checkDrinkType
 * @param: int customer index
 * @param: string sugarAmt
 * Check to see if the sugar amount matches the customer's preference
 * If it's a number thats not between 1 and 5, return 0
 * If it's correct, return 1,
 * If the sugar amount is over by one, return 2
 * If the sugar amount is under by one, return 3
 * If the sugar amount is off by two or more, return 4
 **/
 
 
int Game :: checkSugar (int customerIndex, string sugarAmt){
    
    //Edge Case: If the sugar amount is invalid
    if (stoi(sugarAmt) < 0 || stoi(sugarAmt) > 5){
        cout << "Not a valid sugar amount! +0 Points... " << endl;
        return 0;
    }
    
    //If the sugar amount is exactly correct
     if (sugarAmt == customer[customerIndex].getSugarPrefernce()){
        return 1;
    }
    
    //If the sugar amount is too much by 1
    else if (stoi(sugarAmt) ==  stoi(customer[customerIndex].getSugarPrefernce())+1){
        return 2;
    }
    
    //If the sugar amount is too little by 1
    else if (stoi(sugarAmt) ==  stoi(customer[customerIndex].getSugarPrefernce())-1){
        return 3;
    }
    
    //If the sugar amount is off by more than one
    else {
        return 4;
    }
 }
 
 ///////////////////////////////////////////////////////////////////////////////////////////////////
//Member Function #13: checkMilkAmt:
/** Function: checMilkamt
 * @param: int customer index
 * @param: string milkAmt
 * Check to see if the milk amount matches the customer's preference
 * If it's a number thats not between 1 and 5, return 0
 * If it's correct, return 1,
 * If the milk amount is over by one, return 2
 * If the milk amount is under by one, return 3
 * If the milk amount is off by two or more, return 4
 **/
 
  
int Game :: checkMilk (int customerIndex, string milkAmt){
   
    //If the milk amt is not valid
    if (stoi(milkAmt) < 0 || stoi(milkAmt) > 5){
        cout << "Not a valid sugar amount! +0 Points... " << endl;
        return 0;
    }
    
    //If the milk amount is exactly right
    if (milkAmt == customer[customerIndex].getMilkPrefernce()){
        return 1;
    }
    
    //If the milk amount is too much by one
    else if (stoi(milkAmt) ==  stoi(customer[customerIndex].getMilkPrefernce())+1){
        return 2;
    }
    
    //If the milk amount is too little by one
    else if (stoi(milkAmt) ==  stoi(customer[customerIndex].getMilkPrefernce())-1){
        return 3;
    }
    
    //If the milk amount if off by more than one
    else {
        return 4;
    }
 }
 
 ///////////////////////////////////////////////////////////////////////////////////////////////////
//Member Function #14: checkFlavorType:
/** Function: checkFlavorType
 * @param: string drinkName
 * @param: int customerIndex
 * Check to see if the flavor type matches the customer's flavor preference
 * If the flavor mathches, +1 point.
 * If the flavor does not match, the customer leaves
 **/
bool Game :: checkFlavorType (int customerIndex, string flavorName){
    
    //If flavor matches
    if (toUpperCase(flavorName) ==  toUpperCase(customer[customerIndex].getFlavorType())){
        return true;
    }
    
    //If it doesn't
    else{
        return false;
    }   
}
///////////////////////////////////////////////////////////////////////////////////////////////////
//Member Function #15: checkFlavorAmt:
/** Function: checkFlavorAmt
 * @param: int customer index
 * @param: string FlavorAmt
 * Check to see if the flavor amount matches the customer's preference
 * If it's a number thats not between 1 and 5, return 0
 * If it's correct, return 1,
 * If the flavor amount is over by one, return 2
 * If the flavor amount is under by one, return 3
 * If the flavor amount is off by two or more, return 4
 **/
 
 
int Game :: checkFlavorAmt (int customerIndex, string flavorAmt){
    
    //If the flavor amount is not valid
    if (stoi(flavorAmt) < 0 || stoi(flavorAmt) > 5){
        cout << "Not a valid sugar amount! +0 Points... " << endl;
        return 0;
    }
    
    //If the flavor amount is exactly right
     if (flavorAmt == customer[customerIndex].getFlavorAmount()){
        return 1;
    }
    
    //If the flavor amount is too much by 1
    else if (stoi(flavorAmt) ==  stoi(customer[customerIndex].getFlavorAmount())+1){
        return 2;
    }
    
    //If the flavor is too little by 1
    else if (stoi(flavorAmt) ==  stoi(customer[customerIndex].getFlavorAmount())-1){
        return 3;
    }
    
    //If the flavor amount is off by more than 1
    else {
        return 4;
    }
 }
///////////////////////////////////////////////////////////////////////////////////////////////////
//Member Function #16: toUpperCase:
/** Function: toUpperCase
 * Changes string into all uppercase
 **/
 
//Loops through every letter in a string and makes it an uppercase letter to make input statements not case sensitive
string Game :: toUpperCase(string str){
    string ans = "";
    for(int i = 0; i < str.length(); i++){
        ans += toupper(str[i]);
    }
    return ans;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
//Member Function #16: playGame:
/**Function: PlayGame
 * @param: PLayer p
 * Runs playerTurn and commputerTurn three times and sums up the score from those three rounds
 * Prints out total score after three rounds
 * Saves username and score into a file
 **/
int Game :: playGame (Player p){
    int robotScore=0;
    int score=0;
    int Rscore=0;
    
    //Loops playerTurn and computerTurn 3 times and gets the sum of the scores from the three rounds.
    for (int i =0; i < 3; i++){
        p.setScore(p.getScore()+playerTurn());
        robotScore += computerTurn();
    }
    
    
    //Prints scores
    cout << "Total Score: " <<  p.getScore() << endl;
    cout << "Robot Score: " << robotScore << endl << endl;
    
    
    //prints statements depending on if you beat the robot and if you got a perfect score.
    if (p.getScore() == 30){
        cout << "Congratulations! You got a perfect score! The customers were very happy! (ღ˘⌣˘ღ)"  << endl;
    }
    
    //If you beat Robot
    if (p.getScore() > robotScore) {
        cout << "You beat the robot barista! Great Job! Play again to keep testing your skills!" << endl;
    }
    
    //If robot beat you
    else if (p.getScore() < robotScore ){
        cout << "Better luck next time. The customers preferred the robot barista's drinks...(¬_¬)" << endl;
    }
    
    //if you tied
    if (p.getScore() == robotScore){
        cout << "You tied with the robot barista. The customers were equally satisfied with your drinks. Play again to rematch the robot barista! " << endl;
    }
    numScores++;
    
    
    //Reads the records file
    ifstream inFile("Records.txt");
    string records = "";
    string temp = "";
    
    //If the username isn't found, adds information to the records string 
    while(getline(inFile, temp)){
        if(temp.find(p.getUsername()) == string::npos)
            records += temp + "\n";
    }
    inFile.close();
    
    //Opens a file too write into
    ofstream outFile("Records.txt");
    
    string allScore = "";
    
    //Adds scores into allScore
    for(int i:p.getAllScores()){
        allScore += to_string(i) + ",";
    }
    allScore += to_string(p.getScore());
    
    //Adds information (name and score) into records string
    records += p.getUsername() + " " + allScore + "\n";
    
    //Writes records into Records.txt
    outFile << records;
    numPlayers++;
    
    //close file
    outFile.close();
    return p.getScore(); 
}
