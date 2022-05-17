#include "Game.h"
#include "Player.h"
#include "Person.h"
#include "Computer.h"
#include <string>
#include <array>

using namespace std;

//default with no input
Game::Game(){
    //fill arrrays
    string Rooms[5] = {"Garden", "Ballroom", "Library", "Conservatory", "Kitchen"};
    string Weapons[5] = {"Knife", "Revolver", "Candlestick", "Rope", "Pipe"};
    string Characters[5] = {"Mr Green", "Ms Scarlet", "Professor Plum", "Coronel Mustard", "Ms Peacock"};

    MaxNumGuesses = 4;

    //setup rooms
    this->NumRooms = 4;
    ptrR = new Room[NumRooms];
    fillRooms();

    // sets pointer array to create players
    array<Player *, 2> players;
    players[0] = new Person;
    players[1] = new Computer;

    //create players
    int numPlayers = 2;
    ptrP = new Player[numPlayers];
    ptrP[0] = Person();
    //ptrP[1] = Computer();

    //set up murder so that each player holds info
    murdererDetails = new string[3];
    murdererDetails[0] = Weapons[rand() % NumRooms];
    murdererDetails[1] = Characters[rand() % NumRooms];
    murdererDetails[2] = Rooms[rand() % NumRooms];
    murderInfo = " ";
    string Murderer = Characters[rand() % NumRooms];
    string MurLocation = Rooms[rand() % NumRooms];
    string MurWeapon = Weapons[rand() % NumRooms];

    murderInfo = Murderer + MurLocation + MurWeapon;

    for (int i = 0; i < numPlayers; i++){
        ptrP[i].Murderer = Murderer;
        ptrP[i].MurLocation = MurLocation;
        ptrP[i].MurWeapon = MurWeapon;
    }

    for (int j = 0; j < NumRooms; j++){
        players[0]->makeAccusation();
        players[1]->makeAccusation();
    }    
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
    for (int i = 0; i < numPlayers; i++){
        ptrP[i].Murderer = Murderer;
        ptrP[i].MurLocation = MurLocation;
        ptrP[i].MurWeapon = MurWeapon;
    }
}


// creates a Game with randomised murder weapon, room and murderer
Game::Game(int NumRooms){
    //fill arrrays
    string Rooms[5] = {"Garden", "Ballroom", "Library", "Conservatory", "Kitchen"};
    string Weapons[5] = {"Knife", "Revolver", "Candlestick", "Rope", "Pipe"};
    string Characters[5] = {"Mr Green", "Ms Scarlet", "Professor Plum", "Coronel Mustard", "Ms Peacock"};

    //setup rooms
    this->NumRooms = NumRooms;
    this->MaxNumGuesses = NumRooms;
    ptrR = new Room[NumRooms];
    
    array<Player *, 2> players;
    players[0] = new Person;
    players[1] = new Computer;

    players[1]->setDifficulty();

    fillRooms();

    //create players
    int numPlayers = 2;
    ptrP = new Player[numPlayers];
    ptrP[0] = Person();
    ptrP[1] = Computer();

    //set up murder so that each player holds info
    string Murderer = Characters[rand() % NumRooms + 1];
    string MurLocation = Rooms[rand() % NumRooms];
    string MurWeapon = Weapons[rand() % NumRooms];
    
    cout << "Murder info track: " << Murderer  << " " << MurLocation << " " << MurWeapon << endl << endl;
    
    for (int i = 0; i < numPlayers; i++){
        ptrP[i].Murderer = Murderer;
        ptrP[i].MurLocation = MurLocation;
        ptrP[i].MurWeapon = MurWeapon;
    }

    cout << NumRooms << endl;

    for (int j = 0; j < NumRooms; j++){
        players[0]->makeAccusation();
        players[1]->makeAccusation();
    }

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



     //LOGIC (BROKEN)
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

Game :: Game(int numRooms, int numPlayers){
     //fill arrrays
    string Rooms[5] = {"Garden", "Ballroom", "Library", "Conservatory", "Kitchen"};
    string Weapons[5] = {"Knife", "Revolver", "Candlestick", "Rope", "Pipe"};
    string Characters[5] = {"Mr Green", "Ms Scarlet", "Professor Plum", "Coronel Mustard", "Ms Peacock"};

    MaxNumGuesses = 4;

    //setup rooms
    this->NumRooms = 4;
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

    //set up murder so that each player holds info
    murderInfo = " ";
    string Murderer = Characters[rand() % NumRooms];
    string MurLocation = Rooms[rand() % NumRooms];
    string MurWeapon = Weapons[rand() % NumRooms];

    murderInfo = Murderer + MurLocation + MurWeapon;

    for (int i = 0; i < numPlayers; i++){
        ptrP[i].Murderer = Murderer;
        ptrP[i].MurLocation = MurLocation;
        ptrP[i].MurWeapon = MurWeapon;
    }

    for (int j = 0; j < MaxNumGuesses; j++){
        players[0]->makeAccusation();
        for(int l = 1; l < numPlayers; l++){
            players[l]->makeAccusation();
        }
    }    
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

string * Game::getMurder(){
    return murdererDetails;
}

/*        
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
*/

int Game::getMaxNumGuesses(){
    return MaxNumGuesses;
}


        
// destructor
/*
Game:: ~Game(){
    delete ptrR;

}
*/