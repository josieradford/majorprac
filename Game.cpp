#include <iostream>
#include <string>
#include <cmath>
#include "Game.h"
#include "Player.h"
#include "Room.h"

using namespace std;

// creates a defult Game
Game :: Game(){
    this->NumRooms = 5;
    this->MurWeapon = Weapons[1];
    this->Murderer = Characters[1];
    this->MurLocation = Rooms[1];
    maxNumGuesses = NumRooms;

    
}

// creates a modifiable Game with interchangable characteristics
Game :: Game(int NumRooms, string MurWeapon, string Murderer, string MurLocation, int maxNumGuesses){
    getNumRooms();
    getMurWeapon();
    getMurderer();
    getMurLocation();
    /* shouldn't it look like this??
    this->NumRooms = NumRooms;
    this->MurWeapon = MurWeapon;
    this->Murderer = Murderer;
    this->MurLocation = MurLocation;
    */
    this->maxNumGuesses = NumRooms;
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
void Game :: setNumRooms(){
    // randomise this in future
    NumRooms = 5;
    //when randomising need to make sure that the murLocation is in the set of rooms taht the player can eneter
    //might need a get available rooms function
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

//used to pass the maximum guesses to the player class
int Game::getMaxNumGuesses(){
    return maxNumGuesses;
}

// destructor
Game :: ~Game(){
    
}