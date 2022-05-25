#include <iostream>
#include <string>
#include <cmath>
#include "Person.h"

using namespace std;

Person:: Person(){
    finalAccusation = false;
    guessCount = 0;
    maxGuesses = 4;
    this-> Location = "Conservatory";
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

    while (validResponse == false){
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
    }

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
        cout << "You must make your final accusation this turn." << endl;
    }

    bool valid0 = false;

    // to set valid and invalid responses
    while (valid0 == false){
        //making accusation
        cout << "Enter your guess for the murderer: " << endl;
        cout << "The options are: Mr Green, Ms Scarlet, Professor Plum, Colonel Mustard or Ms Peacock" << endl;
        // enter in both parts of murderer name
        cin >> Accusation[0] >> Accusation[1];

        string name = Accusation[0]+" "+Accusation[1];

        // switch to test input
        if (name == "Mr Green"){
            valid0 = true;
            break;
        }
        else if (name == "Ms Scarlet"){
            valid0 = true;
            break;
        }
        else if (name == "Professor Plum"){
            valid0 = true;
            break;
        }
        else if (name == "Colonel Mustard"){
            valid0 = true;
            break;
        }
        else if (name == "Ms Peacock"){
            valid0 = true;
            break;
        }
        else{
            cout << "Invalid entry please try again." << endl;
            cout << "Please make sure you are using capitals and your input looks the same as the above options." << endl << endl;
        } 
    }


    bool valid1 = false;

    // to set valid and invalid responses
    while (valid1 == false){
        //making accusation
        cout << "Enter your guess for the murder weapon: " << endl;
        cout << "The options are: Knife, Revolver, Candlestick, Rope or Pipe" << endl;
        // get murder weapon accusation
        cin >>  Accusation[2];

        string weapon = Accusation[2];

        // switch to test input for weapon
        if (weapon == "Knife"){
            valid1 = true;
            break;
        }
        else if (weapon == "Revolver"){
            valid1 = true;
            break;
        }
        else if (weapon == "Candlestick"){
            valid1 = true;
            break;
        }
        else if (weapon == "Rope"){
            valid1 = true;
            break;
        }
        else if (weapon == "Pipe"){
            valid1 = true;
            break;
        }
        else{
            cout << "Invalid entry please try again." << endl;
            cout << "Please make sure you are using capitals and your input looks the same as above the options." << endl << endl;
        } 
    }

    bool valid2 = false;

    // to set valid and invalid responses
    while (valid2 == false){
        //making accusation
        cout << "Enter your guess for the room: " << endl;
        cout << "The options are: Garden, Ballroom, Library, Conservatory or Kitchen" << endl;
        // get murder room accusation
        cin >> Accusation[3];

        string room = Accusation[3];

        // switch to test input
        if (room == "Garden"){
            valid2 = true;
            break;
        }
        else if (room == "Ballroom"){
            valid2 = true;
            break;
        }
        else if (room == "Library"){
            valid2 = true;
            break;
        }
        else if (room == "Conservatory"){
            valid2 = true;
            break;
        }
        else if (room == "Kitchen"){
            valid2 = true;
            break;
        }
        else{
            cout << "Invalid entry please try again." << endl;
            cout << "Please make sure you are using capitals and your input looks the same as the above options." << endl << endl;
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

string Person::getLocation(){
    return Location;
}

// virtual change location function
void Person::changeLocation(){
    string newLocation = " ";

    cout << "You are currently in the " << Location << "." << endl;

    //get new location
    bool validInput = false;
    while(validInput == false){
        cout << "From the " <<  Location << " you can move to:" << endl;
        if(Location == "Kitchen"){
            //options
            cout << "Library, Garden or Ballroom" << endl;
            cout << "Which room would you like to move to?" << endl;
            cin >> newLocation; //need input validation
            if (newLocation == "Library" ||newLocation == "Garden"|| newLocation == "Ballroom"){
                validInput = true;
                break;
            }else{
                cout << "You cannot move to " << newLocation << "." << endl;
            }
        }else if (Location == "Library"){
            //options
            cout << "Kitchen, Garden or Conservatory" << endl;
            cout << "Which room would you like to move to?" << endl;
            cin >> newLocation; //need input validation
            if (newLocation == "Conservatory" ||newLocation == "Garden"|| newLocation == "Kitchen"){
                validInput = true;
                break;
            }else{
                cout << "You cannot move to " << newLocation << "." << endl;
            }
        }else if (Location == "Garden"){
            //options
            cout << "Conservatory, Ballroom, Library or Kitchen" << endl;
            cout << "Which room would you like to move to?" << endl;
            cin >> newLocation; //need input validation
            if (newLocation == "Conservatory" || newLocation == "Ballroom"|| newLocation == "Library"|| newLocation == "Kitchen"){
                validInput = true;
                break;
            }else{
                cout << "You cannot move to " << newLocation << "." << endl;
            }
        }else if (Location == "Ballroom"){
            //options
            cout << "Conservatory, Garden or Kitchen" << endl;
            cout << "Which room would you like to move to?" << endl;
            cin >> newLocation; //need input validation
            if (newLocation == "Conservatory" || newLocation == "Garden"|| newLocation == "Kitchen"){
                validInput = true;
                break;
            }else{
                cout << "You cannot move to " << newLocation << "." << endl;
            }
        }else if (Location == "Conservatory"){
            //options
            cout << "Library, Ballroom or Garden" << endl;
            cout << "Which room would you like to move to?" << endl;
            cin >> newLocation; //need input validation
            if (newLocation == "Library" || newLocation == "Ballroom"|| newLocation == "Garden"){
                validInput = true;
                break;
            }else{
                cout << "You cannot move to " << newLocation << "." << endl;
            }
            
        }

    }
    
    //change location
    Location = newLocation;

    cout << "You have entered the " << Location << "." << endl;
    

}

void Person :: setDifficulty(){

}
int Person :: getDifficulty(){
    return 0;
}

//Person:: ~Person(){
//}