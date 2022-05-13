#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
//#include "Person.h"
//#include "Room.h"
//#include "Game.h"

using namespace std;

class Player {
    public:
        string Location;

        //accusation array using: 1Character, 2Weapon, 3Room
        string* Accusation;
        

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
        
        // getter function Current Accusation
        string* getAccusation();

        // destructor
        ~Player();
};
#endif