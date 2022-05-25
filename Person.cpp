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
    //bool validResponse = false;
    //string response;
    int max = maxGuesses;

    /*while (validResponse == false){
        if (guessCount < max){
            char response = ' ';

            cout << "\nDo you want to make your final accusation? Y/N" << endl;
            cin >> response;

            if (response == 'N' || response == 'n'){
                finalAccusation = false;
                validResponse = true;
            }
            else if (response == 'Y' || response == 'y'){
                finalAccusation = true;
                validResponse = true;
            }
            else {
                cout << "Invalid response please try again." << endl;
                break;
            }
        }
    }*/

    /*//determine whether making final accusation or not
    while (validResponse == false && guessCount < max) {
        char response = ' ';

        cout << "\nDo you want to make your final accusation? Y/N" << endl;
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
    }*/

    //checks if player is on final turn
    if (guessCount == max){
        finalAccusation = true;
        cout << "\nYou must make your final accusation this turn." << endl;
    }

    int loop0 = 0;

    // to set valid and invalid responses
    while (loop0 == 0){
        //making accusation
        cout << "\nEnter your guess for the murderer: " << endl;
        cout << "The options are: Mr Green, Ms Scarlet, Professor Plum, Colonel Mustard or Ms Peacock" << endl;
        // enter in both parts of murderer name
        cin >> Accusation[0] >> Accusation[1];

        string name = Accusation[0]+" "+Accusation[1];

        // switch to test input
        if (name == "Mr Green" || name == "Ms Scarlet" || name == "Professor Plum" || name == "Colonel Mustard" || name == "Ms Peacock"){
            loop0 = 1;
            break;
        }
        else{
            cout << "Invalid entry please try again." << endl;
            cout << "Please make sure you are using capitals and your input looks the same as the options" << endl << endl;
        } 
    }

    /*cin >> Accusation[1];
    getline(cin, Accusation[1]);
    cout << "2 " << Accusation[1] << endl;*/

    int loop1 = 0;

    // to set valid and invalid responses
    while (loop1 == 0){
        //making accusation
        cout << "Enter your guess for the murder weapon: " << endl;
        cout << "The options are: Knife, Revolver, Candlestick, Rope or Pipe" << endl;
        // get murder weapon accusation
        cin >>  Accusation[2];

        string weapon = Accusation[2];

        // switch to test input
        if (weapon == "Knife"){
            loop1 = 1;
            break;
        }
        else if (weapon == "Revolver"){
            loop1 = 1;
            break;
        }
        else if (weapon == "Candlestick"){
            loop1 = 1;
            break;
        }
        else if (weapon == "Rope"){
            loop1 = 1;
            break;
        }
        else if (weapon == "Pipe"){
            loop1 = 1;
            break;
        }
        //else if ()
        else{
            cout << "Invalid entry please try again." << endl;
            cout << "Please make sure you are using capitals and your input looks the same as the options" << endl << endl;
        } 
    }

    int loop2 = 0;

    // to set valid and invalid responses
    while (loop2 == 0){
        //making accusation
        cout << "Enter your guess for the room: " << endl;
        cout << "The options are: Garden, Ballroom, Library, Conservatory or Kitchen" << endl;
        // get murder room accusation
        cin >> Accusation[3];

        string room = Accusation[3];

        // switch to test input
        if (room == "Garden"){
            loop2 = 1;
            break;
        }
        else if (room == "Ballroom"){
            loop2 = 1;
            break;
        }
        else if (room == "Library"){
            loop2 = 1;
            break;
        }
        else if (room == "Conservatory"){
            loop2 = 1;
            break;
        }
        else if (room == "Kitchen"){
            loop2 = 1;
            break;
        }
        else{
            cout << "Invalid entry please try again." << endl;
            cout << "Please make sure you are using capitals and your input looks the same as the options" << endl << endl;
        } 
    }

    cout << "\nYour accusation is:" << endl;
    //making final accusation
    if (finalAccusation == true){
        cout << endl << "It was " << Accusation[0] << " " << Accusation[1] << ", with the " << Accusation[2] << " in the "
        << Accusation[3] << "." << endl; 

    } else{ // making a guess
        cout << "Was it " << Accusation[0] << " " << Accusation[1] << ", with the " << Accusation[2] << " in the "
        << Accusation[3] << "?" << endl; 
    }

    //increase counter of how many turns the user has had
    guessCount ++;
}

string * Person :: getAccusation(){
    return Accusation;
}

// virtual change location function
void Person::changeLocation(){
    cout << "Allow for location change" << endl;
    cout << "You are currently in " << Location << endl;

    //if Location 


}

void Person :: setDifficulty(){

}
int Person :: getDifficulty(){
    return 0;
}

Person:: ~Person(){
    delete[] Accusation;
}