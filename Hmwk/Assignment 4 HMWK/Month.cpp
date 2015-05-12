/* 
 * File:   Month.cpp
 * Author: Owner
 *
 * Created on May 11, 2015, 7:36 PM
 */

#include <cstdlib>
#include <iostream>
#include "Month.h"
using namespace std;

string Month::monthy[13] = {"","January", "February", "March", "April", "May",
                                "June", "July", "August", "September", "October",
                                 "November","December"};

Month::Month(){
    name = "January";
    monthNumber = 1;
}

Month::Month(string n){
    name = n;
    for(int i=0;i<13;i++){
    if(n == monthy[i])
        monthNumber = i;
    }
}

Month::Month(int mN){
    monthNumber = mN;
    name = monthy[mN];
}

string Month::setName(string n){
    name = n;
}

int Month::setMonthNum(int mN){
    monthNumber = mN;
}

Month Month::operator++(){
    if(monthNumber == 12){
        monthNumber = 1;
        name = monthy[1];
    }
    else{
        name = monthy[monthNumber+1];
        ++monthNumber;
    }
    return *this;
}

Month Month::operator++(int){
    Month temp(monthNumber);
    if(monthNumber == 12){
        monthNumber = 1;
        name = monthy[1];
    }
    else{
        name = monthy[monthNumber+1];
        monthNumber++;
    }
    return temp;
}

Month Month::operator--(){
    if(monthNumber == 1){
        monthNumber = 12;
        name = monthy[13];
    }
    else{
        name = monthy[monthNumber-1];
        monthNumber--;
    }
    return *this;
}

Month Month::operator--(int){
    Month temp(monthNumber);
    if(monthNumber == 1){
        monthNumber = 12;
        name = monthy[13];
    }
    else{
        name = monthy[monthNumber-1];
        --monthNumber;
    }
    return temp;
}

void Month::print(){
    cout << monthNumber << " " << name;
}

