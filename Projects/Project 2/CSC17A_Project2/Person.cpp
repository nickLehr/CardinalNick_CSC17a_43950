/* 
 * File:   Person.cpp
 * Author: Owner
 *
 * Created on June 3, 2015, 11:31 AM
 */

#include <cstdlib>
#include <iostream>
#include "Person.h"
using namespace std;

char* Person::getName(){
    return name;
}

void Person::setName(char* n){
    name = n;
}

char* Person::getAlias(){
    return alias;
}

void Person::setAlias(char* a){
    alias = a;
}