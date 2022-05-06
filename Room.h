#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
#include <cmath>
#include "Player.h"
#include "Game.h"

using namespace std;

class Room {
    protected:
        string Weapon;
        string Character;
        bool Passage;
    public:
        // defult Room constructor
        Room();

        // constructs Room with weapon, characters 
        Room(string Weapon, string Character, bool Passage);

        // setter and getter Murder Weapon
        void setWeapon(string _Weapon);
        string getWeapon();
        
        // setter and getter Murderer
        void setCharacter(string _Character);
        string getCharacter();
        
        // setter and getter Secret Passage
        void setPassage(bool _Passage);
        bool getPassage();

        // destructor
        ~Room();
};
#endif