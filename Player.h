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
        string Accusation;
    public:
        // defult constructor
        Player();

        // virtual make accusation function
        virtual void makeAccusation(string Weapon, string Murderer, string Location); 

        // virtual change location function
        virtual void changeLocation(string Location);

        // getter function Location
        string getLocation();
        
        // getter function Current Accusation
        string getAccusation();

        // destructor
        ~Player();
};
#endif