/* 
 * File:   ShiftSupervisor.cpp
 * Author: Owner
 *
 * Created on May 22, 2015, 8:00 PM
 */

#include <cstdlib>
#include <iostream>
#include "ShiftSupervisor.h"
using namespace std;

void ShiftSupervisor::output(ShiftSupervisor &n){
    cout << n.getName() << " \nEmployee Number:" << n.getNum() << endl;
    cout << "Salary: $" << n.getSalary() << endl;
    cout << "Production Goal: " << n.getGoal() << endl;
    cout << "Bonus to be received: $" << n.getBonus() << endl;
}