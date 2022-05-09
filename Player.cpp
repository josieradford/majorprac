#include <iostream>
#include <string>
#include <cmath>
#include "Player.h"

using namespace std;

// defult constructor
Player :: Player(){

}

// virtual make accusation function
void Player :: makeAccusation(string Weapon, string Character, string Location){
    cout << "You believe that the murder weapon was " << Weapon;
    cout << ", the murderer was " << Character;
    cout << " and the murder location was " << Location << endl;
    // compare to Packet in game
    // give feedback as if same or not
    if (Weapon != MurWeapon){ //how to carry over variable from Game.h?
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
void Player :: changeLocation(Room _Location){
    Location = _Location;
}

// getter function Location
string Player :: getLocation(){
    return Location;
}


// getter function Current Accusation
string Player :: getAccusation(){
    return Accusation;
}

// destructor
Player :: ~Player(){

}