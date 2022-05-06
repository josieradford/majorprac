#ifndef "GAME_H"
#define "GAME_H"
#include <iostream>
#include <string>
#include <cmath>
#include "Player.h"
#include "Room.h"

using namespace std;

class Game {
    protected:
        int NumRooms;
        string MurWeapon;
        string Murderer;
        string MurLocation;
    public:
        // creates a defult Game
        Game();

        // creates a modifiable Game with interchangable characteristics
        Game(NumRooms, MurWeapon, Murderer, MurLocation);

        // setter and getter Number of Rooms
        setNumRooms();
        getNumRooms();
        
        // setter and getter Murder Weapon
        setMurWeapon();
        getMurWeapon();
        
        // setter and getter Murderer
        setMurderer();
        getMurderer();
        
        // setter and getter Murder Location
        setMurLocation();
        getMurLocation();
        
        // destructor
        ~Game();
}
#endif