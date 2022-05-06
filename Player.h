#ifndef "PLAYER_H"
#define "PLAYER_H"
#include <iostream>
#include <string>
#include <cmath>
#include "Room.h"
#include "Game.h"

using namespace std;

class Player {
    protected:
        Room Location;
        // this should be an array of some description ?
        // could hold elements in a string (Area element isnt string)
        // could make accusation Player type ? (doesn't make sense but idk)
        string Accusation;
    public:
        // defult constructor
        Player();

        // virtual make accusation function
        virtual makeAccusation(Weapon, Murderer, Area); 

        // virtual change location function
        virtual changeLocation(Location);

        // getter function Location
        getLocation();
        
        // getter function Current Accusation
        getAccusation();

        // destructor
        ~Player();
}