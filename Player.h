#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Player {
    public:
        string Location;

        //accusation array using: 1Character, 2Weapon, 3Room
        string* Accusation;

        //currentGuess
        string currentGuessMurderer;
        string currentGuessWeapon;
        string currentGuessLocation;

        //murderer info
        string *murderDetails;

    //public:
        // default constructor
        Player();

        // virtual make accusation function
        //function does not take any parameters  bc the person will have to input manually
        virtual void makeAccusation();

        // virtual change location function
        //function does not take any parameters  bc the person will have to input manually
        virtual void changeLocation();

        // getter function Location
        string getLocation();
        
        // checker function Current Accusation
        int checkAccusation(string *Accusation);

        // set difficulty levels
        virtual void setDifficulty();

        // destructor
        ~Player();
};
#endif