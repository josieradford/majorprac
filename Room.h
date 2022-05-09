#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
#include <cmath>
#include "Player.h"

using namespace std;

class Room {
    protected:
        string RoomName;
        string Weapon;
        string Character;
        bool Passage;
    public:
        // defult Room constructor
        Room();

        // constructs Room with weapon, characters 
        Room(string Weapon, string Character, bool Passage, string RoomName);

        //set get room name
        void setRoomName(string _RoomName);
        string getRoomName();

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