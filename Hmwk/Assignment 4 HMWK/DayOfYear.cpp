/* 
 * File:   DayOfYear.cpp
 * Author: Owner
 *
 * Created on May 11, 2015, 11:22 AM
 */

#include <cstdlib>
#include <iostream>
#include "DayOfYear.h"
using namespace std;

string DayOfYear::month[12] = {"January ", "February ", "March ", "April ", "May ",
                                "June ", "July ", "August ", "September ", "October ",
                                 "November ","December "};

DayOfYear::DayOfYear(int d){
    dayOfYear = d;
}

void DayOfYear::print(){
    if(dayOfYear <= 31){
        cout << month[0] << dayOfYear;
    }
    else if(dayOfYear > 31 && dayOfYear <= 59){
        cout << month[1] << dayOfYear - 31;
    }
    else if(dayOfYear > 59 && dayOfYear <= 90){
        cout << month[2] << dayOfYear - 59;
    }
    else if(dayOfYear > 90 && dayOfYear <= 120){
        cout << month[3] << dayOfYear - 90;
    }
    else if(dayOfYear > 120 && dayOfYear <= 151){
        cout << month[4] << dayOfYear - 120;
    }
    else if(dayOfYear > 151 && dayOfYear <= 181){
        cout << month[5] << dayOfYear - 151;
    }
    else if(dayOfYear > 181 && dayOfYear <= 212){
        cout << month[6] << dayOfYear - 181;
    }
    else if(dayOfYear > 212 && dayOfYear <= 243){
        cout << month[7] << dayOfYear - 212;
        
    }
    else if(dayOfYear > 243 && dayOfYear <= 273){
        cout << month[8] << dayOfYear - 243;
    }
    else if(dayOfYear > 273 && dayOfYear <= 304){
        cout << month[9] << dayOfYear - 273;
    }
    else if(dayOfYear > 304 && dayOfYear <= 334){
        cout << month[10] << dayOfYear - 204;
    }
    else{
        cout << month[11] << dayOfYear - 334;
    }
}

