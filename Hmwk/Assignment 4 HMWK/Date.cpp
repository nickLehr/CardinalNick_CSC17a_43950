/* 
 * File:   Date.cpp
 * Author: Owner
 *
 * Created on May 6, 2015, 6:51 PM
 */

#include <cstdlib>
#include "Date.h"
using namespace std;

void Date::setMonth(int m){
    if(m < 0 || m > 12){
        cout << "Invalid month." << endl;
        month = 0;
    }
    else{
        month = m; 
    }
}
void Date::setDay(int d){
    if(d < 0 || d > 31){
        cout << "Invalid day." << endl;
        day = 0;
    }
    else{
        day = d; 
    }
}
void Date::setYear(int y){
    year = y;
}
void Date::shortDate(int m,int d,int y){
    cout << m << "/" << d << "/" << y;
}

void Date::standardDate(int m,int d,int y){
    if(m == 1){
        cout << "January ";
    }
    else if(m ==2){
        cout << "February ";
    }
    else if (m==3){
        cout << "March ";
    }
    else if(m==4){
        cout << "April ";
    }
    else if(m==5){
        cout << "May ";
    }
    else if(m==6){
        cout << "June ";
    }
    else if(m==7){
        cout << "July ";
    }
    else if(m==8){
        cout << "August ";
    }
    else if(m==9){
        cout << "September ";
    }
    else if(m==10){
        cout << "October ";
    }
    else if(m==11){
        cout << "November ";
    }
    else{
        cout << "December ";
    }
    
    cout << d << "," << y;
    
}

void Date::mlaDate(int m,int d,int y){
    cout << d << " ";
    if(m == 1){
        cout << "January ";
    }
    else if(m ==2){
        cout << "February ";
    }
    else if (m==3){
        cout << "March ";
    }
    else if(m==4){
        cout << "April ";
    }
    else if(m==5){
        cout << "May ";
    }
    else if(m==6){
        cout << "June ";
    }
    else if(m==7){
        cout << "July ";
    }
    else if(m==8){
        cout << "August ";
    }
    else if(m==9){
        cout << "September ";
    }
    else if(m==10){
        cout << "October ";
    }
    else if(m==11){
        cout << "November ";
    }
    else{
        cout << "December ";
    }
    cout << y;
}
