#include <iostream>
#include <string>
#include <cmath>
#include "Game.h"
#include "Player.h"
#include "Room.h"

using namespace std;

// creates a defult Game
Game(){

}

// creates a modifiable Game with interchangable characteristics
Game(NumRooms, MurWeapon, Murderer, MurLocation){
    getNumRooms();
    getMurWeapon();
    getMurderer();
    getMurLocation();
}

// setter and getter Number of Rooms
setNumRooms(int _NumRooms){
    // randomise this in future
    NumRooms = _NumRooms;
}
getNumRooms(){
    return NumRooms;
}

// setter and getter Murder Weapon
setMurWeapon(string _MurWeapon){
    // randomise this in future
    MurWeapon = _MurWeapon;
}
getMurWeapon(){
    return MurWeapon;
}

// setter and getter Murderer
setMurderer(string _Murderer){
    // randomise this in future
    Murderer = _Murderer;
}
getMurderer(){
    return Murderer;
}

// setter and getter Murder Location
setMurLocation(string _MurLocation){
    // randomise this in future
    MurLocation = _MurLocation;
}
getMurLocation(){
    return MurLocation;
}

// destructor
~Game(){
    
}