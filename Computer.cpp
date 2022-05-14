#include <iostream>
#include <string>
#include <cmath>
#include "Computer.h"

using namespace std;

Computer:: Computer(){
    finalAccusation = false;
    guessCount = 0;
    maxGuesses = 4;
    difficulty = 0;
    this-> Location = "emptyL";
    Accusation = new string[3];

    //empty accusation array
    for (int i = 0; i < 3; i++){
        Accusation[i] = "emptyA";
    }

}

Computer:: Computer(int _maxGuesses){
    maxGuesses = _maxGuesses;
    finalAccusation = false;
    guessCount = 0;
    difficulty = 0;

    this-> Location = "emptyL";
    Accusation = new string[3];

    //empty accusation array
    for (int i = 0; i < 3; i++){
        Accusation[i] = "emptyA";
    }
}

//  make accusation function
void Computer::makeAccusation(){
    finalAccusation = false; //create this boolean as part of Computer.h for access outside of thise scope

    // options for accusation
    string possibleRoom[5] = {"Garden", "Ballroom", "Library", "Conservatory", "Kitchen"};
    string possibleWeapons[5] = {"Knife", "Revolver", "Candlestick", "Rope", "Pipe"};
    string possibleCharacters[5] = {"Mr Green", "Ms Scarlet", "Professor Plum", "Coronel Mustard", "Ms Peacock"};

    if (maxGuesses == guessCount){
        finalAccusation = true;
    }

    //to be filled by random input
    string currentGuessLocation = possibleRoom[rand() % 5];
    string currentGuessMurderer = possibleCharacters[rand() % 5];
    string currentGuessWeapon = possibleWeapons[rand() % 5];

    //checks if player is on final turn
    if (guessCount == maxGuesses){
        finalAccusation = true;
        cout << "Computer is making its final accusation this turn." << endl;
    }

    //making final accusation
    if (finalAccusation == true){
        cout << "Computer believes it was: ";
        cout << currentGuessMurderer << " with the " << currentGuessWeapon << " in the "  << currentGuessLocation << endl;
    } else{ // making a guess
        cout << "Computer thinks it may have been: ";
        cout << currentGuessMurderer << " with the " << currentGuessWeapon << " in the "  << currentGuessLocation << endl;
    }

    //increase counter of how many turns the user has had
    guessCount ++;

    int correctCounter = checkAccusation();
}

// virtual change location function
void Computer::changeLocation(){
    cout << "Allow for location change" << endl;
}

// determine level of difficulty
void Computer :: setDifficulty(){
    cout << "What level of difficulty would you like?" << endl;
    cout << "1. Easy" << endl << "2. Medium" << endl << "3. Hard" << endl;

    int loop = 0;
    
    while (loop == 0){
        cout << "Difficulty: ";
        cin >> difficulty;

        switch (difficulty){
            case 1:
                loop = 1;
                break;
            case 2:
                loop = 2;
                break;
            case 3:
                loop = 3;
                break;
            default: //if no valid input is given
                cout << "Invalid response, please try again" << endl;
                break;
        }
    }
}

int Computer :: getDifficulty(){
    return difficulty;
}

//Computer:: ~Computer(){
//}