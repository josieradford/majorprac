#include "Game.h"
#include "Player.h"
#include "Person.h"
#include "Computer.h"
#include <string>
#include <array>

using namespace std;

//default with no input
/*
Game::Game(){ //has two players default
    
    //fill arrrays
    setOptions();
    
    MaxNumGuesses = 4;

    //setup rooms
    this->NumRooms = 4;
    
    fillRooms();

    //create players
    numPeople = 1;
    numComputers = 1;
    numPlayers = numPeople + numComputers;
    setPlayers();

    //set up murder so that each player holds info
    setMurder();

    //copy murder details to each player
    for (int i = 0; i < numPlayers; i++){
        ptrP[i].murderDetails = murderDetails;
    }

    startGame();
}

//creates a modifiable Game with interchangable characteristics
Game::Game(int NumRooms, string MurWeapon, string Murderer, string MurLocation, int MaxNumGuesses){
    //setup rooms
    this->NumRooms = NumRooms;
    ptrR = new Room[NumRooms];
    this->MaxNumGuesses = MaxNumGuesses;

    fillRooms();

    //create players
    int numPlayers = 2;
    ptrP = new Player[numPlayers];
    ptrP[0] = Person();
    //ptrP[1] = Computer();

    //set up murder
    murderDetails = new string[3];
    murderDetails[0] = Murderer;
    murderDetails[1] = MurLocation;
    murderDetails[2] = MurWeapon;
}
Game :: Game(int numRooms, int numPlayers){
    
    //fill arrrays
    setOptions();

    MaxNumGuesses = 4;

    //setup rooms
    this->NumRooms = numRooms;
    ptrR = new Room[NumRooms];
    fillRooms();

    // sets pointer array to create players
    Player * players[numPlayers];
    for(int k = 0; k < numPlayers; k++){
        players[0] = new Person;
        if (players[k] != players[0]){
            players[k] = new Computer;
        }
    }

    // set difficulty level for computer players
    cout << "The difficulty level selected will be applied to all players." << endl;
    players[1]->setDifficulty();
    // uncomment if we want to make specific to each computer player
    cout << "You've selected to have " << (numPlayers - 1) << " computer players" << endl;
    cout << "Each difficulty level selected will be applied to the corresponding players." << endl;
    for(int m = 0; m < numPlayers; m++){
        if (players[m] != players[0]){
            cout << "For player " << m << " " ;
            players[m]->setDifficulty();
        }
    }

    //create players
    ptrP = new Player[numPlayers];
    ptrP[0] = Person();
    //ptrP[1] = Computer();

    //set up murder so that pointer holds info
    setMurder();


    //pass murder details to each player
    for (int i = 0; i < numPlayers; i++){
        ptrP[i].murderDetails = this->murderDetails;
    }

    //begin make accusation loop
    for (int j = 0; j < MaxNumGuesses; j++){
        players[0]->makeAccusation(); //player 1 (person) make accusation
        for(int l = 1; l < numPlayers; l++){
            players[l]->makeAccusation(); //players 2+ (computer) make accusation
        }
    }    
}
*/

// creates a Game with randomised murder weapon, room and murderer
Game::Game(int NumRooms){
    //fill arrrays
    setOptions();

    //setup rooms
    this->NumRooms = NumRooms;
    this->MaxNumGuesses = NumRooms;
    
    /*
    array<Player *, 2> players;
    players[0] = new Person;
    players[1] = new Computer;
    */

    //set up players
    numPeople = 1;
    numComputers = 1;
    setPlayers();

    //set computer difficulty
    ptrP[1].setDifficulty();

    fillRooms();


    //set up murder so that each player holds info
    setMurder();
    
    //cout << "Murder info track: " << Murderer  << " " << MurLocation << " " << MurWeapon << endl << endl;
    
    //pass murder details to players
    for (int i = 0; i < numPlayers; i++){
        ptrP[i].murderDetails = this->murderDetails;
    }

    //cout << NumRooms << endl;

    //startGame();

}

//adds a room to array

void Game::fillRooms(){
    //simplified version
    /*
    string possibleRoomNames[5] = {"Garden", "Ballroom", "Library", "Conservatory", "Kitchen"};
    
    string possibleRoomWeapons[5] = {"Knife", "Revolver", "Candlestick", "Rope", "Pipe"};
    
    string possibleRoomCharacters[5] = {"Mr Green", "Ms Scarlet", "Professor Plum", "Coronel Mustard", "Ms Peacock"};
    
    for (int i = 0; i < NumRooms; i++){
        ptr[i].setRoomName(possibleRoomNames[rand() % 5]);
        ptr[i].setCharacter(possibleRoomCharacters[rand() %5]);
        ptr[i].setWeapon(possibleRoomWeapons[rand() %5]);
    }
    */



     //LOGIC 
    ptrR = new Room[NumRooms];

    string possibleRoomNames[5] = {"Garden", "Ballroom", "Library", "Conservatory", "Kitchen"};
    string* usedRoomNames = new string[5];
    //string usedRoomNames[] = {};
    string possibleRoomWeapons[5] = {"Knife", "Revolver", "Candlestick", "Rope", "Pipe"};
    string* usedRoomWeapons = new string[5];
    //string usedRoomWeapons[] = {};
    string possibleRoomCharacters[5] = {"Mr Green", "Ms Scarlet", "Professor Plum", "Coronel Mustard", "Ms Peacock"};
    string* usedRoomCharacters = new string[5];
    //string usedRoomCharacters[] = {};

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
            ptrR[i].setRoomName(newRoomName);
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
            ptrR[i].setCharacter(newRoomCharacter);
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
            ptrR[i].setWeapon(newRoomWeapon);
            usedRoomWeapons[i] = newRoomWeapon;
        }
        
    }

    delete[] (usedRoomCharacters);
    delete[] (usedRoomNames);
    delete[] (usedRoomWeapons);

    
}



//fill arrays
void Game::setOptions(){
    string RoomSet[5] = {"Garden", "Ballroom", "Library", "Conservatory", "Kitchen"};
    Rooms = RoomSet;

    string WeaponSet[5] = {"Knife", "Revolver", "Candlestick", "Rope", "Pipe"};
    Weapons = WeaponSet;

    string CharacterSet[5] = {"Mr Green", "Ms Scarlet", "Professor Plum", "Coronel Mustard", "Ms Peacock"};
    Characters = CharacterSet;
}

// getter function Current Accusation
int Game::checkAccusation(string *Accusation, string *murdererDetails){
    int correctCount = 0;

    cout << murdererDetails[0] << " test" << endl;

    if (Accusation[0] == murdererDetails[0]){
    correctCount++;
    }
    if (Accusation[1]+Accusation[2] == murdererDetails[1]){
    correctCount++;
    }
    if (Accusation[3] == murdererDetails[2]){
    correctCount++;
    } 

    cout << correctCount << " out of 3 guesses were correct" << endl << endl;
    return correctCount;
}

Room* Game::getRooms(){
    return ptrR;

}



//getter Number of Rooms

int Game::getNumRooms(){
    return NumRooms;
}

//setter of murder details
void Game::setMurder(){ //uses randomiser

    murderDetails = new string[3];
    murderDetails[0] = Characters[rand() % NumRooms];
    murderDetails[1] = Rooms[rand() % NumRooms];
    murderDetails[2] = Weapons[rand() % NumRooms];
    
}

string * Game::getMurder(){
    return murderDetails;
}
       
//getter Murder Weapon
string Game::getMurWeapon(){
    return murderDetails[2];
}

//getter Murderer
string Game::getMurderer(){
    return murderDetails[0];
}
        
//getter Murder Location
string Game::getMurLocation(){
    return murderDetails[1]; 
}


int Game::getMaxNumGuesses(){
    return MaxNumGuesses;
}


void Game::setPlayers(){
    //create player array
    ptrP = new Player[numPeople + numComputers];

    //fill array with people
    for (int i = 0; i < numPeople; i++){
        ptrP[i] = Person();
    }

    //fill array with computers
    for (int i = numPeople; i < numComputers+numPeople; i++){
        ptrP[i] = Computer();
    }
    
}

//CAUSES SEGMENTATION FAULT
void Game::startGame(){ //accusations loop
    for (int i = 0; i < numPlayers; i++){
        ptrP[i].makeAccusation();
    }
}
        
// destructor
/*
Game:: ~Game(){
    delete ptrR;

}
*/