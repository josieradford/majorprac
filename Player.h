#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <cmath>
#include "Room.h"
#include "Game.h"

using namespace std;

class Player {
    protected:
        string Location;
        // this should be an array of some description ?
            //doesn't need to be an array bc we don't need to access previous locations?
        // could hold elements in a string (Area element isnt string)
        // could make accusation Player type ? (doesn't make sense but idk)
            // when makeAccusation is run create a formatted string Accusation that can be formatted differently based on..
            //if its made by computer or person?
        string Accusation;
    public:
        // defult constructor
        Player();

        // virtual make accusation function
        //function does not take any parameters  bc the person will have to input manually
        virtual void makeAccusation(int maxGuesses); 

        // virtual change location function
        //function does not take any parameters  bc the person will have to input manually
        virtual void changeLocation();

        // getter function Location
        string getLocation();
        
        // getter function Current Accusation
        string getAccusation();

        // destructor
        ~Player();
};
#endif