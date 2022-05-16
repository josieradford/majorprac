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
int Player::checkAccusation(string *Accusation){
    int correctCount = 0;
    
    cout << MurWeapon << " test" << endl;

    if (Accusation[0] == MurWeapon){
    correctCount++;
    }
    if (Accusation[1]+Accusation[2] == Murderer){
    correctCount++;
    }
    if (Accusation[3] == MurLocation){
    correctCount++;
    } 
    return correctCount;
}
    

void Player :: setDifficulty(){
    
}

// destructor

Player::~Player(){
    
}
