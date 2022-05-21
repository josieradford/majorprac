#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Person.h"
#include "Computer.h"
#include "Room.h"
#include <array>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

class Game {
    protected:
        string *Weapons;
        string *Characters;
        string *Rooms;
        int NumRooms; //must be 5 or less
        Room *ptrR;
        Player *ptrP;
        char (*ptrM)[33]; //pointer to map array
        string * murderDetails; //pointer to correct accusation
        int numPeople;
        int numComputers;
        int numPlayers;
        int MaxNumGuesses;
        int gameDifficulty;
        fstream file0;
        fstream file1;
        fstream file2;
        //array<Player *, 2> players;

    public:
        // creates a default Game
        Game();
    /*
        // creates a modifiable Game with interchangable characteristics
        Game(int NumRooms, string MurWeapon, string Murderer, string MurLocation, int maxNumGuesses);

        // creates a Game with randomised murder weapon, room and murderer
        Game(int NumRooms, int numPlayers);
    */
        // creates a Game with randomised murder weapon, room and murderer
        Game(int NumRooms);



        //set up arrays for characters, weapons and rooms
        void fillArrays();

        //fills rooms array
        void fillRooms();
        Room * getRooms();

        // setter and getter Number of Rooms
        int getNumRooms();

        //set and get player array
        void setPlayers();

        //getter murder info
        void setMurder();
        string * getMurder();

        // setter and getter Murder Weapon
        string getMurWeapon();
        
        // setter and getter Murderer
        string getMurderer();
        
        // setter and getter Murder Location
        string getMurLocation();
        
        void setMap();
        void printMap();

        void startGame(); //loops accusation

        int getMaxNumGuesses();

        int checkAccusation(string * Accusation, string * murdererDetails);
        int checkAccusationComputer(string * compLastGuess, string * murdererDetails, int difficulty);
        
        // destructor
        //~Game();
};
#endif