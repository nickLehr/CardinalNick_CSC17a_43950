/* 
 * File:   Employee.cpp
 * Author: Nicholas Cardinal
 *
 * Created on May 6, 2015, 7:57 PM
 */

#include <cstdlib>
#include "Employee.h"

void Employee::setName(string n){
    name = n;
}

void Employee::setID(int id){
    idNumber = id;
}

void Employee::setDept(string d){
    department = d;
}

void Employee::setPos(string p){
    position = p;
}

Employee::Employee(string n,int id,string d,string p){
    name = n;
    idNumber = id;
    department = d;
    position = p;
}

Employee::Employee(string n, int id){
    name = n;
    idNumber = id;
    department = "";
    position = "";
}

Employee::Employee(){
    name = "";
    idNumber = 0;
    department = "";
    position = "";
}

void Employee::outputEmpInfo(string n,int id,string d,string p){
    cout << n << " " << id << " " << d << " " << p; 
}


