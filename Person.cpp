#include <iostream>
#include <string>
#include <cmath>
#include "Game.h"
#include "Player.h"
#include "Room.h"
#include "Person.h"

using namespace std;

//  make accusation function
// function shouldn't take in variables when declared as they are user input????
void Person::makeAccusation(){
    finalAccusation = false; //create this boolean as part of Person.h for access outside of thise scope
    bool validResponse = false;
    string response;
    int max = Game::getMaxNumGuesses();

    //determine whether making final accusation or not
    
    While(validResponse == false && numGuesses < max);{
        cout << "Do you want to make your final accusation?" << endl;
        cin >> response;

        switch (response){
            case "Y":
            case "y":
            case "yes":
            case "Yes":
                finalAccusation = true;
                validResponse = true;
                break;
            case "N":
            case "n":
            case "no":
            case "No":
                finalAccusation = false;
                validResponse = true;
                break;
            default: //if no valid input is given
                cout << "invalid response" << endl;
                break;
        }
    }

    //checks if player is on final turn
    if (numGuesses == max){
        finalAccusation = true;
        cout << "You must make your final accusation this turn." << endl;
    }


    //making accusation
    cout << "Enter your guess for the muderer: " << endl;
    cin >> Murderer ;

    cout << "Enter your guess for the murder weapon: " << endl;
        cin >> Weapon ;

        cout << "Enter your guess for the room: " << endl;
        cin >> Location ;

        //need to add some kind of check for vaild input against weapon, murderer and room names

        cout << "Your accusation is:" << endl;
    
        //making final accusation
        if (finalAccusation == true){
            cout << "It was" << murderer << ", with the " << weapon << " in the "
            << location << "." << endl; 

        } else{ // making a guess
            cout << "Was it " <<  murderer << ", with the " << weapon << " in the "
            << location << "?" << endl; 
        }
    
    //increase counter of how many turns the user has had
    numGuesses = numGuesses +1;
}

// virtual change location function
void Person::changeLocation(){

}