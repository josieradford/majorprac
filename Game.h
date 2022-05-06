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
        const string Weapons[5] = {"Knife", "Revolver", "Candlestick", "Rope", "Pipe"};
        const string Characters[5] = {"Mr Green", "Ms Scarlet", "Professor Plum", "Coronel Mustard", "Ms Peacock"};
        const string Rooms[5] = {"Garden", "Ballroom", "Library", "Conservatory", "Kitchen"};
        int NumRooms = 5;
        string MurWeapon;
        string Murderer;
        string MurLocation;
    public:
        // creates a defult Game
        Game();

        // creates a modifiable Game with interchangable characteristics
        Game(NumRooms, MurWeapon, Murderer, MurLocation);

        // creates a Game with randomised murder weapon, room and murderer
        Game(NumRooms);

        // setter and getter Number of Rooms
        void setNumRooms();
        int getNumRooms();
        
        // setter and getter Murder Weapon
        void setMurWeapon();
        string getMurWeapon();
        
        // setter and getter Murderer
        void setMurderer();
        string getMurderer();
        
        // setter and getter Murder Location
        void setMurLocation();
        string getMurLocation();
        
        // destructor
        ~Game();
}
#endif