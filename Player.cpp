#include "Player.h"
#include <iostream>
#include <string>
#include <cmath>

 using namespace std;
 
 // default constructor
Player::Player(){
    this-> Location = "emptyL";
    Accusation = new string[4];

    //empty accusation array
    for (int i = 0; i < 4; i++){
        Accusation[i] = "emptyA";
    }

}

//virtuals
void Player::makeAccusation(){

}

void Player::changeLocation(){
    
}

// getter function Location
string Player::getLocation(){
    return Location;
}
        
// getter function Current Accusation
int Player::checkAccusation(){
    int correctCount = 0;

    if (currentGuessWeapon == MurWeapon){
        correctCount++;
    }
    if (currentGuessMurderer == Murderer){
        correctCount++;
    }
    if (currentGuessLocation == MurLocation){
        correctCount++;
    } 
     return correctCount;
}

void Player :: setDifficulty(){
    
}

// destructor

Player::~Player(){
    
}
