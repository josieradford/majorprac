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
    
    for (int j = 0; j < NumRooms; j++){
		if (gameEND == false){
            // person player
            printMap();
            players[0]->changeLocation(); //change person's location

            for (int i = 0; i < 5; i++){ //print room description
                if((players[0]->getLocation()) == (ptrR[i].getRoomName())){
                    ptrR[i].printRoomDescription();
                }
            }
            
			players[0]->makeAccusation();
        	checkAccusation(players[0]->getAccusation(), getMurder());

			// computer player
        	players[1]->makeAccusation();
        	checkAccusationComputer(players[1]->getAccusation(), getMurder(), gameDifficulty);

            
		}
		else {
			gameENDMessage();
			break;
		}
    }

	cout << "\nThanks for playing ! \nThats the end." << endl;

	if (gameDifficulty == 3){
		remove("ComputerMemoryPerson.txt");
		remove("ComputerMemoryWeapon.txt");
		remove("ComputerMemoryRoom.txt");
	}
}

void Game :: gameIntro(){
	cout << endl << "Welcome, this is a simulation of the game Cluedo." << endl;
	cout << "The game is played by a player (you) and a Computer," << endl;
	cout << "You will take it in turns to make accusations and try to guess" << endl;
	cout << "the murderer, murder weapon and room in which the murder took place." << endl;
	cout << "The rules are as follows:" << endl;
    cout << "1. Each turn, you must move between rooms adjacent to your current location." << endl;
    cout << "2. You will then accuse a character of having commited the murder in that room." << endl;
	cout << "3. Each guess you will be told the number of correct guesses in your accusation." << endl;
	cout << "4. Depending on the selected difficulty, the computer may or may not tell you if its" << endl;
	cout << "   guess was correct, but it will always tell you its guess." << endl;
	cout << "5. When the correct guess is made the game will end." << endl << endl;
	cout << "Please enjoy the game!" << endl << endl;
}

//adds a room to array

void Game::fillRooms(){
    srand ( time(NULL) );

    ptrR = new Room[NumRooms];

    //create blank arrays for items that have already been assigned
    int availIndexWeapons[5] = {0, 1, 2, 3 ,4}; //set to -1 when used
    int availIndexChars[5] = {0, 1, 2, 3 ,4}; //set to -1 when used

    //for each room, fill with unused items, and assign name from Rooms array
    for (int i = 0; i < NumRooms; i++){
        bool weaponSet = false;
        bool charSet = false;
        string newRoomCharacter = " ";
        string newRoomWeapon = " ";
        
        ptrR[i].setRoomName(Rooms[i]); //fills room names directly from array

        while (weaponSet == false){
             int newRoomWeapIndex = (rand() % 5);
            for (int k = 0; k < NumRooms; k++){
                if (availIndexWeapons[k] == newRoomWeapIndex){
                    ptrR[i].setWeapon(Weapons[newRoomWeapIndex]);
                    availIndexWeapons[k] = -1;
                    weaponSet = true;
                }
            }
        }
       

        while (charSet == false){
             int newRoomCharIndex = (rand() % 5);
            for (int k = 0; k < NumRooms; k++){
                if (availIndexChars[k] == newRoomCharIndex){
                    ptrR[i].setCharacter(Characters[newRoomCharIndex]);
                    availIndexChars[k] = -1;
                    charSet = true;
                }
            }
        }
        
    }
    
}



//fill arrays
void Game::fillArrays(){
    
    Rooms = new string[5];
    string RoomSet[5] = {"Conservatory", "Ballroom", "Garden", "Library", "Kitchen"};
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
/*
Game:: ~Game(){
    delete ptrR;

}
*/