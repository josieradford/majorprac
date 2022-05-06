#include <iostream>
#include <string>
#include <cmath>
#include "Game.h"
#include "Player.h"
#include "Room.h"

using namespace std;

// defult Room constructor
Room(){

}

// constructs Room with weapon, characters 
Room(Weapon, Character, Passage){
    getWeapon();
    getCharacter();
    getPassage();
}

// setter and getter Murder Weapon
setWeapon(string _Weapon){
    // randomise this in future
    Weapon = _Weapon;
}
getWeapon(){
    return Weapon;
}

// setter and getter Murderer
setCharacter(string _Character){
    // randomise this in future
    Character = _Character;
}
getCharacter(){
    return Character;
}

// setter and getter Secret Passage
setPassage(bool _Passage){
    // set this as constant for if one of four rooms
    // eg if Ballroom/Conservatory OR if Library/Garden
    // that way there is always a link
    Passage = Passage;
}
getPassage(){
    return Passage;
}

// destructor
~Room(){
    
}
