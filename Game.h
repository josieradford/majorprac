#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <cmath>
#include "Player.h"
#include "Room.h"

using namespace std;

class Game {
    protected:
        string Weapons[5] = {"Knife", "Revolver", "Candlestick", "Rope", "Pipe"};
        string Characters[5] = {"Mr Green", "Ms Scarlet", "Professor Plum", "Coronel Mustard", "Ms Peacock"};
        string Rooms[5] = {"Garden", "Ballroom", "Library", "Conservatory", "Kitchen"};
        int NumRooms;
        string MurWeapon;
        string Murderer;
        string MurLocation;
        int maxNumGuesses;
    public:
        // creates a default Game
        Game();

        // creates a modifiable Game with interchangable characteristics
        Game(int NumRooms, string MurWeapon, string Murderer, string MurLocation, int maxNumGuesses);

        // creates a Game with randomised murder weapon, room and murderer
        Game(int NumRooms);

        // setter and getter Number of Rooms
        void setNumRooms();
        int getNumRooms();
        
        // setter and getter Murder Weapon
        void setMurWeapon(string _Weapon);
        string getMurWeapon();
        
        // setter and getter Murderer
        void setMurderer(string _Murderer);
        string getMurderer();
        
        // setter and getter Murder Location
        void setMurLocation(string _MurLocation);
        string getMurLocation();

        int getMaxNumGuesses();
        
        // destructor
        ~Game();
};
#endif