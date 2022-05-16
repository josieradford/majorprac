#include <iostream>
#include <string>
#include <cmath>
#include "Person.h"

using namespace std;

Person:: Person(){
    finalAccusation = false;
    guessCount = 0;
    maxGuesses = 4;
    this-> Location = "emptyL";
    Accusation = new string[4];

    //empty accusation array
    for (int i = 0; i < 4; i++){
        Accusation[i] = "emptyA";
    }

}

Person:: Person(int _maxGuesses){
    maxGuesses = _maxGuesses;
    finalAccusation = false;
    guessCount = 0;

    this-> Location = "emptyL";
    Accusation = new string[4];

    //empty accusation array
    for (int i = 0; i < 4; i++){
        Accusation[i] = "emptyA";
    }
}

//  make accusation function
void Person::makeAccusation(){
    finalAccusation = false; //create this boolean as part of Person.h for access outside of thise scope
    bool validResponse = false;
    string response;
    int max = maxGuesses;

    //to be filled by user input
    string currentGuessLocation = " ";
    string currentGuessMurderer = " ";
    string currentGuessWeapon = " ";

    //determine whether making final accusation or not
    while (validResponse == false && guessCount < max) {
        char response = ' ';

        cout << "Do you want to make your final accusation? Y/N" << endl;
        cin >> response;

        switch (response){
            case 'Y':
            case 'y':
                finalAccusation = true;
                validResponse = true;
                break;

            case 'N':
            case 'n':
                finalAccusation = false;
                validResponse = true;
                break;

            default: //if no valid input is given
                cout << "invalid response" << endl;
                break;
        }
    }

    //checks if player is on final turn
    if (guessCount == max){
        finalAccusation = true;
        cout << "You must make your final accusation this turn." << endl;
    }

    //making accusation
    cout << "Enter your guess for the muderer: " << endl;
    // enter in both parts of murderer name
    for (int i = 1; i < 3; i++){
        cin >> Accusation[i];
    }
    /*cin >> Accusation[1];
    getline(cin, Accusation[1]);
    cout << "2 " << Accusation[1] << endl;*/

    cout << "Enter your guess for the murder weapon: " << endl;
    cin >> currentGuessWeapon ;
    Accusation[0] = currentGuessWeapon;

    cout << "Enter your guess for the room: " << endl;
    cin >> currentGuessLocation;
    Accusation[3] = currentGuessLocation;

        //need to add some kind of check for vaild input against weapon, murderer and room names

    cout << "Your accusation is:" << endl;
    //making final accusation
    if (finalAccusation == true){
        cout << endl << "It was " << Accusation[1] << " " << Accusation[2] << ", with the " << currentGuessWeapon << " in the "
        << currentGuessLocation << "." << endl; 

    } else{ // making a guess
        cout << "Was it " << Accusation[1] << " " << Accusation[2] << ", with the " << currentGuessWeapon << " in the "
        << currentGuessLocation << "?" << endl << endl; 
    }

    //increase counter of how many turns the user has had
    guessCount ++;

    int correctCounter = checkAccusation();

    //output how many were correct
    //make this depend on a difficulty setting?
    cout << correctCounter << " out of 3 guesses were correct" << endl << endl;
}

string Person :: getAccusation(){
    return Accusation[4];
}

// virtual change location function
void Person::changeLocation(){
    cout << "Allow for location change" << endl;

}

//Person:: ~Person(){
//}