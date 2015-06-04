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
using namespace std;

int Player::getAge(){
    return age;
}

void Player::setAge(int a){
    while(!(cin >> a)){
        throw "Please enter a valid age.";
    }
    a = age;
}

char* Player::getName(){
    return AIname;
}
void Player::setName(char* n){
//    for(int i=0;i<20;i++){
//        swap(n[i],n[i+1]);
//    }
    name = n;
}
char* Player::getAlias(){
    return AIalias;
}
void Player::setAlias(char* a){
    for(int i=0;i<20;i++){
        swap(a[i],a[i+1]);
    }
    alias = a;
}