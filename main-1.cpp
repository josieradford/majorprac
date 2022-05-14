#include "Game.h"
#include "Room.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    Game game1;
    Player player1;

    Room *rooms = game1.getRooms();
    
    int numRooms = game1.getNumRooms();

    for(int i = 0; i < numRooms; i++){
        cout << rooms[i].getRoomName() << endl;
    }

    //cout << *(player1.getAccusation()) << " "<< player1.getLocation() << endl;
   

   
    Room room1 = Room("Knife", "Purple", false, "Garden");

    cout << room1.getCharacter() << endl;
    cout << room1.getWeapon() << endl;
    cout << room1.getPassage() << endl;
    cout << room1.getRoomName() << endl;
    

    return 0;
}