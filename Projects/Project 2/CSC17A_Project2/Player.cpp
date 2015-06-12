/* 
 * File:   Player.cpp
 * Author: Owner
 *
 * Created on June 3, 2015, 11:40 AM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <stdexcept>
#include "Player.h"
using namespace std;

void Player::exception(int ex){
    if(ex == 3){
        cout << "Invalid age, ERROR MESSAGE: " << ex << endl;
    }
    cout << "Enter an age";
    cin.clear();
    cin.ignore();
    setAge();
}

Player::Player(string n, int a){
    name = n;
    age = a;
}

string Player::getName(){
    return name;
}

void Player::setName(){
    string n;
    cout << "Enter your name: ";
    cin >> n;
    name = n;
    cout << "\nWelcome " << name << "!" << endl;
}
        
void Player::setAge(){
    int a;
    cout << "Enter your age: ";
    cin >> a;
    try{
    if(!cin){
        throw 3;
    }
    else{
        age = a;
    }
    }catch(int ex){
        exception(ex);
        cin.clear();
    }
}

int Player::getAge(){
    return age;
}

ostream &operator<<(ostream &out, Player &p){
    out << p.name << " is younger and will go first!" << endl<<endl<<endl;
    return out;
}

istream &operator>>(istream &in, Player &p){
    in >> p.name >> p.age;
    return in;
}