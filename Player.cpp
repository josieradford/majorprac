#include <iostream>
#include <string>
#include <cmath>
#include "Game.h"
#include "Player.h"
#include "Room.h"

using namespace std;

// defult constructor
Player(){

}

// virtual make accusation function
virtual makeAccusation(string Weapon, string Character, Room Area){
    cout << "You believe that the murder weapon was " << Weapon;
    cout << ", the murderer was " << Character;
    cout << " and the murder location was " << Area << endl;
    // compare to Packet in game
    // give feedback as if same or not
    if (Weapon != MurWeapon){
        cout << Weapon << "was not the murder weapon !" << endl;
    }
    if (Character != Murderer){
        cout << Character << "was not the murderer !" << endl;
    }
    if (Area != MurLocation){
        cout << Area << "was not the location of the murder !" << endl;
    }

    // add a graphic of the potential and crossed off murder weapons, suspects and locations.
}

// virtual change location function
virtual changeLocation(Room _Location){
    Location = _Location;
}

// getter function Location
getLocation(){
    return Location;
}

// getter function Current Accusation
getAccusation(){
    return Accusation;
}

// destructor
~Player(){

}