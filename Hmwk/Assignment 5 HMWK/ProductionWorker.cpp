/* 
 * File:   ProductionWorker.cpp
 * Author: Owner
 *
 * Created on May 21, 2015, 6:58 PM
 */
#include "ProductionWorker.h"
#include <iostream>
using namespace std;
void ProductionWorker::setShift(int s){
    if(s<0||s>2){
        cout << "Invalid shift." << endl;
    }
    else{
        shift = s;
    }
}

void ProductionWorker::output(){
    cout << "Name: " << getName() << endl;
    cout << "Employee Number: " << getNum() << endl;
    cout << "Date of Hire: " << getDate() << endl;
    cout << "Shift: " << getShift() << endl;
    cout << "Rate of Pay: " << getRate() << endl;
}
