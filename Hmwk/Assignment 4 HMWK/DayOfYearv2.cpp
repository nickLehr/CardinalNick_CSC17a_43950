/* 
 * File:   DayOfYearv2.cpp
 * Author: Owner
 *
 * Created on May 11, 2015, 12:13 PM
 */

#include <cstdlib>
#include <iostream>
#include "DayOfYearv2.h"
using namespace std;

string DayOfYearv2::month[12] = {"January", "February", "March", "April", "May",
                                "June", "July", "August", "September", "October",
                                 "November","December"};

DayOfYearv2::DayOfYearv2(int d){
    dayOfYear = d;
}

DayOfYearv2::DayOfYearv2(string m,int d){
    monthy = m;
    if(d > 31 || d < 1){
        cout << "Invalid day. Goodbye.";
    }
    else{
        dayOfYear = d; 
    }
}

void DayOfYearv2::print(){
    for(int i=0;i<12;i++){
        if(dayOfYear == 31 && monthy == "December"){
            dayOfYear = 1;
            monthy = "January"; 
        }
        else if(dayOfYear == 31 && monthy == month[i]){
            dayOfYear = 1;
            monthy = month[i+1];
        }
    }
    cout << monthy << " " << dayOfYear;
}

DayOfYearv2 DayOfYearv2::operator++(){
    if(dayOfYear == 365){
        dayOfYear = 1;
    }
    else{
        ++dayOfYear;
    }
    return *this;
}

DayOfYearv2 DayOfYearv2::operator++(int){
    DayOfYearv2 temp(dayOfYear);
    if(dayOfYear == 365){
        dayOfYear = 1;
    }
    else{
        dayOfYear++;
    }
    return temp;
}

DayOfYearv2 DayOfYearv2::operator--(){
    if(dayOfYear == 1){
        dayOfYear = 365;
    }
    else{
        --dayOfYear;
    }
    return *this;
}

DayOfYearv2 DayOfYearv2::operator--(int){
    DayOfYearv2 temp(dayOfYear);
    if(dayOfYear == 1){
        dayOfYear = 365;
    }
    else{
        dayOfYear--;
    }
    return temp;
}

void DayOfYearv2::printv2(){
    cout << monthy << " " << dayOfYear;
}