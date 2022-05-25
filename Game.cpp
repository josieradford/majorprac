#include "Game.h"
#include "Player.h"
#include "Person.h"
#include "Computer.h"
#include <string>
#include <time.h>
#include <array>
#include <fstream>
#include <stdlib.h>

using namespace std;

//default with no input
/*
Game::Game(){ //has two players default
    
    //fill arrrays
    fillArrays();
    
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
    gameIntro();

	fillArrays();
    setMap();
    printMap();
	gameEND = false;

    //setup rooms
    this->NumRooms = NumRooms;
    this->MaxNumGuesses = NumRooms;

    //create players
    // sets pointer array to create players
    numPlayers = 2;
    array<Player *, 2> players;

    players[0] = new Person;
    players[1] = new Computer;


    //set computer difficulty
    players[1]->setDifficulty();
    gameDifficulty = players[1]->getDifficulty();

    fillRooms();

    //set up murder so that each player holds info
    setMurder();
    
	//cout << "Murder info track: " << Murderer  << " " << MurLocation << " " << MurWeapon << endl << endl;

    for (int j = 0; j < NumRooms; j++){
        if (gameEND == false){
			// person player
			players[0]->makeAccusation();

        	checkAccusation(players[0]->getAccusation(), getMurder());
		}
		if (gameEND == false){
			// computer player
        	players[1]->makeAccusation();
        	checkAccusationComputer(players[1]->getAccusation(), getMurder(), gameDifficulty);
		}
		else {
			gameENDMessage();
			break;
		}
    }

	cout << "\nThanks for playing ! \nThats the end.\n" << endl;

	if (gameDifficulty == 3){
		remove("ComputerMemoryPerson.txt");
		remove("ComputerMemoryWeapon.txt");
		remove("ComputerMemoryRoom.txt");
	}
}

void Game :: gameIntro(){
	cout << "Welcome, this is a simulation of the game Cluedo." << endl;
	cout << "The game is played by a player (you) and a Computer," << endl;
	cout << "You will take in turns to make accusations and try guess" << endl;
	cout << "the murderer, murder weapon and room in which the murder took place" << endl;
	cout << "The rules are as follows:" << endl;
	cout << "1. Each guess you will be told the number of correct guesses in your accusation." << endl;
	cout << "2. Depending on the difficulty you select the computer may or may not tell you if its" << endl;
	cout << "   guess was correct, but it will always tell you its guess." << endl;
	cout << "3. When the correct guess is made the game will end." << endl << endl;
	cout << "Please enjoy the game!" << endl << endl;
}

//adds a room to array

void Game::fillRooms(){
    ptrR = new Room[NumRooms];

    string* usedRoomNames = new string[5];
    string* usedRoomWeapons = new string[5];
    string* usedRoomCharacters = new string[5];


    for (int i = 0; i < NumRooms; i++){
        bool nameUsed = false;
        bool weaponUsed = false;
        bool characterUsed = false;

        string newRoomName = Rooms[rand() % 5];

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
        
        string newRoomCharacter = Characters[rand() % 5];

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
        
        string newRoomWeapon = Weapons[rand() % 5];

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
void Game::fillArrays(){
    
    Rooms = new string[5];
    string RoomSet[5] = {"Garden", "Ballroom", "Library", "Conservatory", "Kitchen"};
    Weapons = new string[5];
    string WeaponSet[5] = {"Knife", "Revolver", "Candlestick", "Rope", "Pipe"}; 
    Characters = new string[5];
    string CharacterSet[5] = {"Mr Green", "Ms Scarlet", "Professor Plum", "Colonel Mustard", "Ms Peacock"};   
    
    for (int i = 0; i < 5; i++){
        Rooms[i] = RoomSet[i];
        Weapons[i] = WeaponSet[i];
        Characters[i] = CharacterSet[i];
    }

}

// getter function Current Accusation for Person
int Game::checkAccusation(string *Accusation, string *murderDetails){
    int correctCount = 0;
    
    if (Accusation[2] == murderDetails[1]){
        correctCount++;
    }
    if (Accusation[0]+" "+Accusation[1] == murderDetails[0]){
        correctCount++;
    }
    if (Accusation[3] == murderDetails[2]){
        correctCount++;
    } 

    cout << "You made " << correctCount << " out of 3 correct guesses" << endl << endl;

	// trigger the end of game if the correct guess was made
	if (correctCount == 3){
		gameEND = true;
		personWin = true;
	}

    return correctCount;
}

// checker function Current Accusation for Computer
int Game::checkAccusationComputer(string * compLastGuess, string * murderDetails, int gameDifficulty){
    int correctCount = 0;

    if (gameDifficulty == 1){

        cout << "Computer got ";
        // if loop to test output
        if (compLastGuess[0] == murderDetails[0]){
            cout << murderDetails[0] << " ";
            correctCount++;
        }
        if (compLastGuess[1] == murderDetails[1]){
            cout << murderDetails[1] << " ";
            correctCount++;
        }
        if (compLastGuess[2] == murderDetails[2]){
            cout << murderDetails[2] << " ";
            correctCount++;
        }if (correctCount == 0){
            cout << "0 correct guesses" << endl;
        }
        else{
            cout << "correct" << endl;
        }
    } else if (gameDifficulty == 2){
        // if loop to test output
        if (compLastGuess[0] == murderDetails[0]){
            correctCount++;
        }
        if (compLastGuess[1] == murderDetails[1]){
            correctCount++;
        }
        if (compLastGuess[2] == murderDetails[2]){
            correctCount++;
        }
        cout << "Computer got " << correctCount << " out of 3 guesses correct" << endl;
    }
    else if (gameDifficulty == 3){
        // if loop to test output
        if (compLastGuess[0] == murderDetails[0]){
            correctCount++;
        }
		// enter the guess into text file if its incorrect
        else if (compLastGuess[0] != murderDetails[0]){
            file0.open("ComputerMemoryPerson.txt", ios :: app);
			file0 << compLastGuess[0] << endl;
			file0.close();
        }
		// if loop to test output
        if (compLastGuess[1] == murderDetails[1]){
            correctCount++;
        }
		// enter the guess into text file if its incorrect
		else if(compLastGuess[1] != murderDetails[1]){
			file1.open("ComputerMemoryWeapon.txt", ios :: app);
			file1 << compLastGuess[1] << endl;
			file1.close();
		}
		// if loop to test output
        if (compLastGuess[2] == murderDetails[2]){
            correctCount++;
        }
		// enter the guess into text file if its incorrect
		else if(compLastGuess[2] != murderDetails[2]){
			file2.open("ComputerMemoryRoom.txt", ios :: app);
			file2 << compLastGuess[2] << endl;
			file2.close();
		}
		// output to show computers reaction
        if (correctCount == 0){
            cout << "Computer was not happy with its guess." << endl;
        }
        else if (correctCount == 1){
            cout << "Computer thinks its guess was okay." << endl;
        }
        else if (correctCount == 2){
            cout << "Computer thinks its guess was pretty good." << endl;
        }
        else if (correctCount == 3){
            cout << "Computer thinks this was a great guess!" << endl;
        }
    }

	// trigger the end of game if the correct guess was made
	if (correctCount == 3){
		gameEND = true;
	}

    return correctCount;
}

// return rooms
Room* Game::getRooms(){
    return ptrR;

}

void Game::setMap(){
    int numRows = 16;
    int numCols = 34;
    ptrM = new char[15][33];

    for(int row = 0; row < numRows; row++){
        for(int col = 0; col < numCols; col++){
            //external frame
            if (row == 0 || col == 0 || col == numCols-1 || row == numRows-1 ){
                ptrM[row][col] = '*';
            //internal frame
            }  else if ((row == 5 || row == 10) && (col >= 11 && col <= 22)){
                ptrM[row][col] = '*';
            }else if ((col == 11 || col == 22) && (row >= 5 && row <= 10)){
                ptrM[row][col] = '*';
            }else if ((col == 17) && (row <= 5 || row >= 10)){
                ptrM[row][col] = '*';
            }else if ((row == 8) && (col <= 11 || col >= 22)){
                ptrM[row][col] = '*';
            //room numbering
            } else if (row == 2 && col == 3){
                ptrM[row][col] = '1';
            }else if (row == 2 && col == 30){
                ptrM[row][col] = '2';
            }else if (row == 7 && col == 16){
                ptrM[row][col] = '3';
            }else if (row == 13 && col == 3){
                ptrM[row][col] = '4';
            }else if (row == 13 && col == 30){
                ptrM[row][col] = '5';
            }
            else{
                ptrM[row][col] = ' ';
            }            
            //doors
            ptrM[3][17] = '|';
            ptrM[8][5] = '_';
            ptrM[8][27] = '_';
            ptrM[13][17] = '|';
            ptrM[5][13] = '_';
            ptrM[10][13] = '_';
            ptrM[5][20] = '_';
            ptrM[10][20] = '_';
            
        }
    }
    

}

void Game::printMap(){
    int numRows = 16;
    int numCols = 34;

    //print map
    cout << endl << "GAME MAP" << endl;
    for(int row = 0; row < numRows; row++){
        for(int col = 0; col < numCols; col++){
            cout << (ptrM[row][col]);
        }
        cout << endl;
    }

    //print map legend
    cout << "1: Conservatory" << endl
    << "2: Ballroom" << endl
    << "3: Garden" << endl
    << "4: Library" << endl
    << "5: Kitchen" << endl
    << "_ : doors" << endl
    << "* : walls" << endl;

}

//getter Number of Rooms
int Game::getNumRooms(){
    return NumRooms;
}

//setter of murder details
void Game::setMurder(){ //uses randomiser
    //fill arrrays
    fillArrays();
    srand ( time(NULL) );

    murderDetails = new string[3];

    
    murderDetails[2] = Rooms[rand() % NumRooms];
    murderDetails[1] = Weapons[rand() % NumRooms];
    murderDetails[0] = Characters[rand() % NumRooms];

    //cout << "Murder details from setMurder: " << murderDetails[0] << " " << murderDetails[1] << " " << murderDetails[2] << endl;
}

string * Game::getMurder(){
    return murderDetails;
}
       
//getter Murder Weapon
string Game::getMurWeapon(){
    return murderDetails[1];
}

//getter Murderer
string Game::getMurderer(){
    return murderDetails[0];
}
        
//getter Murder Location
string Game::getMurLocation(){
    return murderDetails[2]; 
}


int Game::getMaxNumGuesses(){
    return MaxNumGuesses;
}


void Game::setPlayers(){
    /*
    //VERSION 1 WORKS FOR PLAYER FUNCTION
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
    */

    array<Player *, 2> players;
    players[0] = new Person;
    players[1] = new Computer;
    
}

void Game::startGame(){ //accusations loop
    for (int i = 0; i < numPlayers; i++){
        ptrP[i].makeAccusation();
        cout << "startGame run for: " << i << endl;
    }
}

void Game :: gameENDMessage(){
	if (personWin == true){
		cout << "You have made the correct guess! \nThe murderer has now been found and you have won!" << endl;
	}
	else if (personWin == false){
		cout << "Computer has made the correct guess! \nThe murderer has now been found, however, you have lost" << endl;
	}
}
        
// destructor
Game:: ~Game(){
    delete[] ptrR;
	delete[] Rooms;
	delete[] Weapons;
	delete[] Characters;
	delete[] ptrM;
	delete[] murderDetails;
}