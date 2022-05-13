#include <iostream>
#include <string>
//#include "Player.h" //is this line necessary
#include "Person.h"

using namespace std;

Person:: Person(){
    finalAccusation = false;
    guessCount = 0;
    maxGuesses = 4;
    this-> Location = "emptyL";
    Accusation = new string[3];

    //empty accusation array
    for (int i = 0; i < 3; i++){
        Accusation[i] = "emptyA";
    }


}

Person:: Person(int _maxGuesses){
    maxGuesses = _maxGuesses;
    finalAccusation = false;
    guessCount = 0;

    this-> Location = "emptyL";
    Accusation = new string[3];

    //empty accusation array
    for (int i = 0; i < 3; i++){
        Accusation[i] = "emptyA";
    }
}

//  make accusation function
void Person::makeAccusation(){
    finalAccusation = false; //create this boolean as part of Person.h for access outside of thise scope
    bool validResponse = false;
    string response;
    int max = maxGuesses;

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

    //to be filled by user input
    string Murderer = " ";
    string Weapon = " ";
    string Location = " ";


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
            cout << "It was" << Murderer << ", with the " << Weapon << " in the "
            << Location << "." << endl; 

        } else{ // making a guess
            cout << "Was it " <<  Murderer << ", with the " << Weapon << " in the "
            << Location << "?" << endl; 
        }
    
    //increase counter of how many turns the user has had
    guessCount ++;
}

// virtual change location function
void Person::changeLocation(){
    cout << "Allow for location change" << endl;

}

Person:: ~Person(){

    
}