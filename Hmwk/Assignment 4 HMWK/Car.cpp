/* 
 * File:   Car.cpp
 * Author: Nicholas Cardinal
 *
 * Created on May 6, 2015, 8:21 PM
 */

#include <cstdlib>
#include "Car.h"
using namespace std;

Car::Car(int yM, string m){
    yearModel = yM;
    make = m;
    speed = 0;
}

void Car::setYM(int yM){
    yearModel = yM;
}

void Car::setMake(string m){
    make = m;
}

void Car::setSpeed(int s){
    speed = s;
}

void Car::accelerate(){
    speed += 5;
}

void Car::brake(){
    speed -= 5;
}
