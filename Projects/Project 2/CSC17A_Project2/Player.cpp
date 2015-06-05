/* 
 * File:   Player.cpp
 * Author: Owner
 *
 * Created on June 3, 2015, 11:40 AM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include "Player.h"
#include "GameState.h"
using namespace std;

int Player::getAge(){
    return age;
}

void Player::setAge(int a){
    GameState p;
    if(!(cin)){
       throw p;
    }
    else{
        age = a;
    }
}

char* Player::getName(){ 
    return AIname;
}
void Player::setName(char* n){
    for(int i = 0; i < sizeof(n);i++){
        AIname[i] = n[i];
    }
}
char* Player::getAlias(){
    return AIalias;
}
void Player::setAlias(char* a){
    for(int i=0;i<20;i++){
        swap(a[i],a[i+1]);
    }
    AIalias = a;
}