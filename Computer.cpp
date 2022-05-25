#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
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
    string possibleCharacters[5] = {"Mr Green", "Ms Scarlet", "Professor Plum", "Colonel Mustard", "Ms Peacock"};

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
    else if (difficulty == 2 && guessCount != 0){
        string possibleRoom2[4];
        string possibleWeapons2[4];
        string possibleCharacters2[4];

        // removes options for accusation to 'remember' last guess
        for (int i = 0; i < 5; i++){
            if (compLastGuess[2] != possibleRoom[i]){
                for (int j = 0; j < 4; j++){
                    possibleRoom2[j] = possibleRoom[i];
                }
            }
			if (compLastGuess[0] != possibleCharacters[i]){
                for (int j = 0; j < 4; j++){
                    possibleCharacters2[j] = possibleCharacters[i];
                }
            }
			if (compLastGuess[1] != possibleWeapons[i]){
                for (int j = 0; j < 4; j++){
                    possibleWeapons2[j] = possibleWeapons[i];
                }
            }
        }
        //to be filled by random input
        compLastGuess[2] = possibleRoom2[rand() % 4];
        compLastGuess[0] = possibleCharacters2[rand() % 4];
        compLastGuess[1] = possibleWeapons2[rand() % 4];
    }
    else if (difficulty == 3 && guessCount != 0){
		// run test to check file1 contents against arrays
        // sets counter to set size of possibleWeapons3
        int trackerwrong0 = 5;
		bool cbool0 = false, cbool1 = false, cbool2 = false, cbool3 = false, cbool4 = false;
        // opens file1
        file0.open("ComputerMemoryPerson.txt", ios :: in);
        // checks if file1 is open
        if (file0.is_open()){
            string line;
            // while loop to sort through each line in file2
            while (getline(file0, line)){
                // get how many guess options have been used
                for (int i = 0; i < 5; i++){
                    if (line == possibleCharacters[i]){
                        trackerwrong0--;
                        break;
                    }
                }
            }
            // close file1
            file0.close();
        }
        // set string array for possible weapons
		string possibleCharacters3[trackerwrong0];
		string incorrectGuesses0[5 - trackerwrong0];
		// opens file0
		file0.open("ComputerMemoryPerson.txt", ios :: in);
        // checks if file0 is open
        if (file0.is_open()){
            string line;
            // while loop to sort through each line in file
			for (int p = 0; p < (5 - trackerwrong0); p++){
				getline(file0, line);
				if (line != ""){
					incorrectGuesses0[p] = line;
				}
			}
            // close file0
            file0.close();
        }

		if (trackerwrong0 != 5){
			for (int i = 0; i < (5 - trackerwrong0); i++){
			int j = 0;

			if (possibleCharacters[0] != incorrectGuesses0[i] && cbool0 == false){
				possibleCharacters3[j] = possibleCharacters[0];
				j++;
			} else {cbool0 = true;}
			if (possibleCharacters[1] != incorrectGuesses0[i] && cbool1 == false){
				possibleCharacters3[j] = possibleCharacters[1];
				j++;
			} else {cbool1 = true;}
			if (possibleCharacters[2] != incorrectGuesses0[i] && cbool2 == false){
				possibleCharacters3[j] = possibleCharacters[2];
				j++;
			} else {cbool2 = true;}
			if (possibleCharacters[3] != incorrectGuesses0[i] && cbool3 == false){
				possibleCharacters3[j] = possibleCharacters[3];
				j++;
			} else {cbool3 = true;}
			if (possibleCharacters[4] != incorrectGuesses0[i] && cbool4 == false){
				possibleCharacters3[j] = possibleCharacters[4];
				j++;
			} else {cbool4 = true;}
			}

		} else if (trackerwrong0 == 5){
			for (int k = 0; k < 5; k++){
				possibleCharacters3[k] = possibleCharacters[k];
			}
		}

		// run test to check file1 contents against arrays
        // sets counter to set size of possibleWeapons3
        int trackerwrong1 = 5;
		bool wbool0 = false, wbool1 = false, wbool2 = false, wbool3 = false, wbool4 = false;
        // opens file1
        file1.open("ComputerMemoryWeapon.txt", ios :: in);
        // checks if file1 is open
        if (file1.is_open()){
            string line;
            // while loop to sort through each line in file1
            while (getline(file1, line)){
                // get how many guess options have been used
                for (int i = 0; i < 5; i++){
                    if (line == possibleWeapons[i]){
                        trackerwrong1--;
                        break;
                    }
                }
            }
            // close file1
            file1.close();
        }
        // set string array for possible weapons
		string possibleWeapons3[trackerwrong1];
		string incorrectGuesses1[5 - trackerwrong1];
		// opens file1
		file1.open("ComputerMemoryWeapon.txt", ios :: in);
        // checks if file1 is open
        if (file1.is_open()){
			string line;
            // while loop to sort through each line in file
			for (int p = 0; p < (5 - trackerwrong1); p++){
				getline(file1, line);
				if (line != ""){
					incorrectGuesses1[p] = line;
				}
			}
            // close file1
            file1.close();
        }

		if (trackerwrong1 != 5){
			for (int i = 0; i < (5 - trackerwrong1); i++){
			int j = 0;

			if (possibleWeapons[0] != incorrectGuesses1[i] && wbool0 == false){
				possibleWeapons3[j] = possibleWeapons[0];
				j++;
			} else {wbool0 = true;}
			if (possibleWeapons[1] != incorrectGuesses1[i] && wbool1 == false){
				possibleWeapons3[j] = possibleWeapons[1];
				j++;
			} else {wbool1 = true;}
			if (possibleWeapons[2] != incorrectGuesses1[i] && wbool2 == false){
				possibleWeapons3[j] = possibleWeapons[2];
				j++;
			} else {wbool2 = true;}
			if (possibleWeapons[3] != incorrectGuesses1[i] && wbool3 == false){
				possibleWeapons3[j] = possibleWeapons[3];
				j++;
			} else {wbool3 = true;}
			if (possibleWeapons[4] != incorrectGuesses1[i] && wbool4 == false){
				possibleWeapons3[j] = possibleWeapons[4];
				j++;
			} else {wbool4 = true;}
			}
		} else if (trackerwrong1 == 5){
			for (int k = 0; k < 5; k++){
				possibleWeapons3[k] = possibleWeapons[k];
			}
		}

		// run test to check file1 contents against arrays
        // sets counter to set size of possibleRoom3
        int trackerwrong2 = 5;
		bool rbool0 = false, rbool1 = false, rbool2 = false, rbool3 = false, rbool4 = false;
        // opens file2
        file2.open("ComputerMemoryRoom.txt", ios :: in);
        // checks if file2 is open
        if (file2.is_open()){
            string line;
            // while loop to sort through each line in file2
            while (getline(file2, line)){
                // get how many guess options have been used
                for (int i = 0; i < 5; i++){
                    if (line == possibleRoom[i]){
                        trackerwrong2--;
                        break;
                    }
                }
            }
            // close file2
            file2.close();
        }
        // set string array for possible weapons
		string possibleRoom3[trackerwrong2];
		string incorrectGuesses2[5 - trackerwrong2];
		// opens file2
		file2.open("ComputerMemoryRoom.txt", ios :: in);
        // checks if file2 is open
        if (file2.is_open()){
            string line;
            // while loop to sort through each line in file
			for (int p = 0; p < (5 - trackerwrong2); p++){
				getline(file2, line);
				if (line != ""){
					incorrectGuesses2[p] = line;
				}
			}
            // close file2
            file2.close();
        }

		if (trackerwrong2 != 5){
			for (int i = 0; i < (5 - trackerwrong2); i++){
			int j = 0;

			if (possibleRoom[0] != incorrectGuesses2[i] && rbool0 == false){
				possibleRoom3[j] = possibleRoom[0];
				j++;
			} else {rbool0 = true;}
			if (possibleRoom[1] != incorrectGuesses2[i] && rbool1 == false){
				possibleRoom3[j] = possibleRoom[1];
				j++;
			} else {rbool1 = true;}
			if (possibleRoom[2] != incorrectGuesses2[i] && rbool2 == false){
				possibleRoom3[j] = possibleRoom[2];
				j++;
			} else {rbool2 = true;}
			if (possibleRoom[3] != incorrectGuesses2[i] && rbool3 == false){
				possibleRoom3[j] = possibleRoom[3];
				j++;
			} else {rbool3 = true;}
			if (possibleRoom[4] != incorrectGuesses2[i] && rbool4 == false){
				possibleRoom3[j] = possibleRoom[4];
				j++;
			} else {rbool4 = true;}
			}

		} else if (trackerwrong2 == 5){
			for (int k = 0; k < 5; k++){
				possibleRoom3[k] = possibleRoom[k];
			}
		}

        // fill with randomised input
        compLastGuess[0] = possibleCharacters3[rand() % trackerwrong0];
        compLastGuess[1] = possibleWeapons3[rand() % trackerwrong1];
        compLastGuess[2] = possibleRoom3[rand() % trackerwrong2];
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
}

string * Computer :: getAccusation(){
    return compLastGuess;
}

/*void Computer :: DifficultyLevel(int difficulty){
    // to set level of memory according to difficulty
    string possibleRoom[5] = {"Garden", "Ballroom", "Library", "Conservatory", "Kitchen"};
    string possibleWeapons[5] = {"Knife", "Revolver", "Candlestick", "Rope", "Pipe"};
    string possibleCharacters[5] = {"Mr Green", "Ms Scarlet", "Professor Plum", "Colonel Mustard", "Ms Peacock"};

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
	

    bool validResponse = false;
    
	while (validResponse == false){
        cout << "\nWhat level of difficulty would you like?" << endl;
        cout << "1. Easy" << endl << "2. Medium" << endl << "3. Hard" << endl;
        // prompt and get player response

        cout << "Difficulty: ";
        cin >> difficulty;

		if (difficulty == 1 || difficulty == 2 || difficulty == 3){
			validResponse = true; //accept input
		}
		else {
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