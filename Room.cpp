#include "Room.h"


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
        
// setter and getter Secret Passage
void  Room::setPassage(bool _Passage){
    this->Passage = _Passage;
}

bool Room::getPassage(){
    return Passage;
}
// destructor
Room::~Room(){

}