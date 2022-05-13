#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <cmath>
#include "Room.h"

using namespace std;

class Game {
    protected:
        string Weapons[5];
        string Characters[5] ;
        string Rooms[5];
        int NumRooms; //must be 5 or less
        Room *ptrR;
        Player *ptrP;
        string MurWeapon;
        string Murderer;
        string MurLocation;
        int MaxNumGuesses;

    public:
        // creates a default Game
        Game();

        // creates a modifiable Game with interchangable characteristics
        Game(int NumRooms, string MurWeapon, string Murderer, string MurLocation, int maxNumGuesses);

        // creates a Game with randomised murder weapon, room and murderer
        Game(int NumRooms);

        //fills rooms array
        void fillRooms();
        Room* getRooms();

        // setter and getter Number of Rooms
        int getNumRooms();
        
        // setter and getter Murder Weapon
        string getMurWeapon();
        
        // setter and getter Murderer
        string getMurderer();
        
        // setter and getter Murder Location
        string getMurLocation();

        int getMaxNumGuesses();

        int checkAccusation(string weaponGuess, string charGuess, string locationGuess);
        
        // destructor
        //~Game();
};
#endif