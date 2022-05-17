#include "Player.h"
#include <iostream>
#include <string>
#include <cmath>

 using namespace std;
 
 // default constructor
Player::Player(){
    this-> Location = "emptyLocation";
    Accusation = new string[3];

    //empty accusation array
    for (int i = 0; i < 3; i++){
        Accusation[i] = "emptyAccusation";
    }

}

//virtuals
void Player::makeAccusation(){
    //test
    cout << "Player::makeAccusation was run" << endl;
}

void Player::changeLocation(){
    
}

// getter function Location
string Player::getLocation(){
    return Location;
}
        
// getter function Current Accusation
int Player::checkAccusation(string *Accusation){

    cout << "checkAccusation was run" << endl;
    int correctCount = 0;
    
    //combine accusation elements to produce full name of character
    Accusation[0]  = Accusation[0] + " " + Accusation[3];

    if (Accusation[0] == murderDetails[0]){
        cout << Accusation[0] << endl;
    correctCount++;
    }
    if (Accusation[1] == murderDetails[1]){
    correctCount++;
    }
    if (Accusation[2] == murderDetails[2]){
    correctCount++;
    } 
    return correctCount;
}
    

void Player :: setDifficulty(){
    
}

// destructor

Player::~Player(){
    
}
