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
    Accusation = new string[4];
    compLastGuess = new string[3];

    //empty accusation array
    for (int i = 0; i < 4; i++){
        Accusation[i] = "emptyA";
    }

}

Computer:: Computer(int _maxGuesses){
    maxGuesses = _maxGuesses;
    finalAccusation = false;
    guessCount = 0;
    difficulty = 0;

    this-> Location = "emptyL";
    Accusation = new string[4];
    compLastGuess = new string[3];

    //empty accusation array
    for (int i = 0; i < 4; i++){
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

    // to change difficulty levels
    if (difficulty == 1 || guessCount == 0){
        //to be filled by random input
        compLastGuess[2] = possibleRoom[rand() % 5];
        compLastGuess[0] = possibleCharacters[rand() % 5];
        compLastGuess[1] = possibleWeapons[rand() % 5];
    }
    else if ((difficulty == 2 && guessCount != 0) || (difficulty == 3 && guessCount != 0)){
        string possibleRoom2[4];
        string possibleWeapons2[4];
        string possibleCharacters2[4];

        // removes options for accusation to 'remember' last guess
        for (int i = 0; i < 5; i++){
            if (compLastGuess[2] != possibleRoom[i]){
                for (int j = 0; j < 4; j++){
                    possibleRoom2[j] = possibleRoom[i];
                    //cout << possibleRoom2[j] << endl;
                }
            }
			if (compLastGuess[0] != possibleCharacters[i]){
                for (int j = 0; j < 4; j++){
                    possibleCharacters2[j] = possibleCharacters[i];
                    //cout << possibleCharacters2[j] << endl;
                }
            }
			if (compLastGuess[1] != possibleWeapons[i]){
                for (int j = 0; j < 4; j++){
                    possibleWeapons2[j] = possibleWeapons[i];
                    //cout << possibleWeapons2[j] << endl;
                }
            }
        }
        //to be filled by random input
        compLastGuess[2] = possibleRoom2[rand() % 4];
        compLastGuess[0] = possibleCharacters2[rand() % 4];
        compLastGuess[1] = possibleWeapons2[rand() % 4];
    }

    /*//to be filled by random input NOt RANDOMISING RN
    string currentGuessLocation = possibleRoom[(rand() % 5)];
    string currentGuessMurderer = possibleCharacters[rand() % 5];
    string currentGuessWeapon = possibleWeapons[rand() % 5];*/

    //checks if player is on final turn
    if (guessCount == maxGuesses){
        finalAccusation = true;
        cout << "Computer is making its final accusation this turn." << endl;
    }

    //making final accusation
    if (finalAccusation == true){
        cout << "Computer believes it was: ";
        cout << compLastGuess[0] << " with the " << compLastGuess[1] << " in the "  << compLastGuess[2] << endl;
    } else{ // making a guess
        cout << "Computer thinks it may have been: ";
        cout << compLastGuess[0] << " with the " << compLastGuess[1] << " in the "  << compLastGuess[2] << endl;
    }

    //increase counter of how many turns the user has had
    guessCount ++;

    //int correctCounter = checkAccusation();
}

string * Computer :: getAccusation(){
    return compLastGuess;
}

/*void Computer :: DifficultyLevel(int difficulty){
    // to set level of memory according to difficulty
    string possibleRoom[5] = {"Garden", "Ballroom", "Library", "Conservatory", "Kitchen"};
    string possibleWeapons[5] = {"Knife", "Revolver", "Candlestick", "Rope", "Pipe"};
    string possibleCharacters[5] = {"Mr Green", "Ms Scarlet", "Professor Plum", "Coronel Mustard", "Ms Peacock"};

    if (difficulty == 1){
        //to be filled by random input
        string currentGuessLocation = possibleRoom[rand() % 5];
        string currentGuessMurderer = possibleCharacters[rand() % 5];
        string currentGuessWeapon = possibleWeapons[rand() % 5];
    }
    else if (difficulty == 2){
        string possibleRoom2[4];
        string possibleWeapons2[4];
        string possibleCharacters2[4];

        // options for accusation
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 4; j++){
                if (currentGuessLocation != possibleRoom[i]){
                    possibleRoom2[j] = possibleRoom[i];
                }
                //to be filled by random input
                string currentGuessLocation = possibleRoom2[rand() % 4];
                string currentGuessMurderer = possibleCharacters2[rand() % 4];
                string currentGuessWeapon = possibleWeapons2[rand() % 4];
            }
        }
    }
}*/

// virtual change location function
void Computer::changeLocation(){
    cout << "Allow for location change" << endl;
}

// determine level of difficulty
void Computer :: setDifficulty(){
    // prompt
	cout << "\nWhat level of difficulty would you like?" << endl;
    cout << "1. Easy" << endl << "2. Medium" << endl << "3. Hard" << endl;

    int loop = 0;
    
	// to set valid and invalid responses
    while (loop == 0){
		// prompt and get player response
        cout << "Difficulty: ";
        cin >> difficulty;

        // switch to test input
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
                cout << "Invalid response, please try again " << endl;
                break;
        }
    }
}

int Computer :: getDifficulty(){
    return difficulty;
}

//Computer:: ~Computer(){
//}