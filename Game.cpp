#include "Game.h"
#include <string>

using namespace std;

//default with no input
Game::Game(){
    //setup rooms
    this->NumRooms = 4;
    ptr = new Room[NumRooms];

    MaxNumGuesses = 4;

    fillRooms();
    //set up murder
    this->Murderer = Characters[rand() % NumRooms];
    this->MurLocation = Rooms[rand() % NumRooms];
    this->MurWeapon = Weapons[rand() % NumRooms];

}

//creates a modifiable Game with interchangable characteristics
Game::Game(int NumRooms, string MurWeapon, string Murderer, string MurLocation, int MaxNumGuesses){
        //setup rooms
    this->NumRooms = NumRooms;
    ptr = new Room[NumRooms];
    this->MaxNumGuesses = MaxNumGuesses;

    fillRooms();

    //set up murder
    this->Murderer = Murderer;
    this->MurLocation = MurLocation;
    this->MurWeapon = MurWeapon;

}


// creates a Game with randomised murder weapon, room and murderer
Game::Game(int NumRooms){
    //setup rooms
    this->NumRooms = NumRooms;
    this->MaxNumGuesses = NumRooms;
    ptr = new Room[NumRooms];

    fillRooms();
    //set up murder
    this->Murderer = Characters[rand() % NumRooms];
    this->MurLocation = Rooms[rand() % NumRooms];
    this->MurWeapon = Weapons[rand() % NumRooms];
}

//adds a room to array

void Game::fillRooms(){
    //simplified version
    string possibleRoomNames[5] = {"Garden", "Ballroom", "Library", "Conservatory", "Kitchen"};
    
    string possibleRoomWeapons[5] = {"Knife", "Revolver", "Candlestick", "Rope", "Pipe"};
    
    string possibleRoomCharacters[5] = {"Mr Green", "Ms Scarlet", "Professor Plum", "Coronel Mustard", "Ms Peacock"};
    
    for (int i = 0; i < NumRooms; i++){
        ptr[i].setRoomName(possibleRoomNames[rand() % 5]);
        ptr[i].setCharacter(possibleRoomCharacters[rand() %5]);
        ptr[i].setWeapon(possibleRoomWeapons[rand() %5]);
    }
    



    /* LOGIC (BROKEN)
    string possibleRoomNames[5] = {"Garden", "Ballroom", "Library", "Conservatory", "Kitchen"};
    string usedRoomNames[] = {};
    string possibleRoomWeapons[5] = {"Knife", "Revolver", "Candlestick", "Rope", "Pipe"};
    string usedRoomWeapons[] = {};
    string possibleRoomCharacters[5] = {"Mr Green", "Ms Scarlet", "Professor Plum", "Coronel Mustard", "Ms Peacock"};
    string usedRoomCharacters[] = {};

    for (int i = 0; i < NumRooms; i++){
        bool nameUsed = false;
        bool weaponUsed = false;
        bool characterUsed = false;

        string newRoomName = possibleRoomNames[rand() % 5];

        //iterates over number of rooms already setup
        //checks if room name has already been used
        for (int k = 0; k <= i; k++){
            if (usedRoomNames[k] == newRoomName){
                nameUsed = true;
                break;
            }
        }
        
        //sets room name
        if (nameUsed == false){
            ptr[i].setRoomName(newRoomName);
            usedRoomNames[i] = newRoomName;
        }
        
        string newRoomCharacter = possibleRoomCharacters[rand() % 5];

        //iterates over number of rooms already setup
        //checks if character has already been allocated 
        for (int k = 0; k <= i; k++){
            if (usedRoomCharacters[k] == newRoomCharacter){
                characterUsed = true;
                break;
            }
        }
        
        //sets character to room
        if (characterUsed == false){
            ptr[i].setCharacter(newRoomCharacter);
            usedRoomCharacters[i] = newRoomCharacter;
        }
        
        string newRoomWeapon = possibleRoomWeapons[rand() % 5];

        //iterates over number of rooms already setup
        //checks if weapon has already been allocated 
        for (int k = 0; k <= i; k++){
            if (usedRoomWeapons[k] == newRoomWeapon){
                weaponUsed = true;
                break;
            }
        }
        
        //sets weapon to room
        if (weaponUsed == false){
            ptr[i].setWeapon(newRoomWeapon);
            usedRoomWeapons[i] = newRoomWeapon;
        }
        
    }
    */
}


Room* Game::getRooms(){
    return ptr;

}



//getter Number of Rooms

int Game::getNumRooms(){
    return NumRooms;
}
        
//getter Murder Weapon
string Game::getMurWeapon(){
    return MurWeapon;
}

//getter Murderer
string Game::getMurderer(){
    return Murderer;
}
        
//getter Murder Location
string Game::getMurLocation(){
    return MurLocation;
}

int Game::getMaxNumGuesses(){
    return MaxNumGuesses;
}
        
// destructor
/*
Game:: ~Game(){
    delete ptr;

}
*/