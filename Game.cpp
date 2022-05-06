#include <iostream>
#include <string>
#include <cmath>
#include "Game.h"
#include "Player.h"
#include "Room.h"

using namespace std;

// creates a defult Game
Game :: Game(){
    
}

// creates a modifiable Game with interchangable characteristics
Game :: Game(int NumRooms, string MurWeapon, string Murderer, string MurLocation){
    getNumRooms();
    getMurWeapon();
    getMurderer();
    getMurLocation();
}

// creates a Game with randomised murder weapon, room and murderer
Game :: Game(int NumRooms){
    getNumRooms();
    setMurWeapon(Weapons[rand() % 5]);
    getMurWeapon();
    setMurderer(Characters[rand() % 5]);
    getMurderer();
    setMurLocation(Rooms[rand() % 5]);
    getMurLocation();
}

// setter and getter Number of Rooms
void Game :: setNumRooms(int _NumRooms){
    // randomise this in future
    NumRooms = _NumRooms;
}
int Game :: getNumRooms(){
    return NumRooms;
}

// setter and getter Murder Weapon
void Game :: setMurWeapon(string _MurWeapon){
    MurWeapon = _MurWeapon;
}
string Game :: getMurWeapon(){
    return MurWeapon;
}

// setter and getter Murderer
void Game :: setMurderer(string _Murderer){
    // randomise this in future
    Murderer = _Murderer;
}
string Game :: getMurderer(){
    return Murderer;
}

// setter and getter Murder Location
void Game :: setMurLocation(string _MurLocation){
    // randomise this in future
    MurLocation = _MurLocation;
}
string Game :: getMurLocation(){
    return MurLocation;
}

// destructor
Game :: ~Game(){
    
}