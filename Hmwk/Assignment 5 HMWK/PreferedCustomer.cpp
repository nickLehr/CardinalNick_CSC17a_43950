/* 
 * File:   PreferedCustomer.cpp
 * Author: Owner
 *
 * Created on May 22, 2015, 7:41 PM
 */

#include <cstdlib>
#include <iostream>
#include "PreferedCustomer.h"
using namespace std;
void PreferedCustomer :: setPAmount(float p){
    if(p < 0){
        cout << "You owe us money, sir or ma'am." << endl;
    }
    else if(p >= 500 && p < 1000){
        discLvl = .05;
    }
    else if(p >= 1000 && p < 1500){
        discLvl = .06;
    }
    else if(p >= 1500 && p < 2000){
        discLvl = .07;
    }
    else{
        discLvl = .10;
    }
    purchAmnt = p;
}
