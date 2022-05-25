#include <iostream>
#include <string>
#include <cmath>
#include "Room.h"

using namespace std;


// defult Room constructor
Room::Room(){
    this->Weapon = "";
    this->Character = "";
    this->RoomName = "";
    this->Passage = false;
}

// constructs Room with weapon, characters 
Room:: Room(string Weapon, string Character, bool Passage, string RoomName){
    this->Weapon = Weapon;
    this->Character = Character;
    this->Passage = Passage;
    this->RoomName = RoomName;

}

void Room::setRoomName(string _RoomName){
    this->RoomName = _RoomName;
}

string Room::getRoomName(){
    return RoomName;
}

// setter and getter Murder Weapon
void Room::setWeapon(string _Weapon){
    this->Weapon = _Weapon;
}
string Room::getWeapon(){
    return Weapon;
}
        
// setter and getter Murderer
void Room::setCharacter(string _Character){
    this->Character = _Character;
}
string Room::getCharacter(){
    return Character;
}
        

void Room::printRoomDescription(){
    srand ( time(NULL) );
    string descriptions[4] = {"suspicious", "relaxed", "nervous", "worried"};
    string charDescription = descriptions[rand() % 3];

    string weaponLocation = " ";
    string room = getRoomName();

    if (room == "Kitchen"){
        weaponLocation = "counter";
    } else if (room == "Garden"){
        weaponLocation = "ground";
    }else if (room == "Conservatory" || room == "Ballroom"){
        weaponLocation = "floor";
    } else if (room == "Library"){
        weaponLocation = "desk";
    } else{
        cout << "invalid room name : returned from printRoomDescription";
    }

    cout << "In the " << getRoomName() << " there is a " << getWeapon()
    << " laying on the " << weaponLocation << " and " << getCharacter()
    << " is standing there looking " << charDescription << "." << endl;
}
// destructor
Room::~Room(){

}