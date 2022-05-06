#include <iostream>
#include <string>
#include <cmath>
#include "Game.h"
#include "Player.h"
#include "Room.h"

using namespace std;

// defult Room constructor
Room :: Room(){

}

// constructs Room with weapon, characters 
Room :: Room(string Weapon, string Character, bool Passage){
    getWeapon();
    getCharacter();
    getPassage();
}

// setter and getter Murder Weapon
void Room :: setWeapon(string _Weapon){
    // randomise this in future
    Weapon = _Weapon;
}
string Room :: getWeapon(){
    return Weapon;
}

// setter and getter Murderer
void Room :: setCharacter(string _Character){
    // randomise this in future
    Character = _Character;
}
string Room :: getCharacter(){
    return Character;
}

// setter and getter Secret Passage
void Room :: setPassage(bool _Passage){
    // set this as constant for if one of four rooms
    // eg if Ballroom/Conservatory OR if Library/Garden
    // that way there is always a link
    Passage = Passage;
}
bool Room :: getPassage(){
    return Passage;
}

// destructor
Room :: ~Room(){

}
