#include "Game.h"
#include "Room.h"
#include "Player.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){
    Room Lounge = Room();

    Game(5, "Knife", "Mr Green", "Lounge");

    Game(5);
}