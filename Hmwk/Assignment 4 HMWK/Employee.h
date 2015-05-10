/* 
 * File:   Employee.h
 * Author: Owner
 *
 * Created on May 6, 2015, 7:56 PM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H
#include <iostream>
using namespace std;
class Employee{
    private:
        string name;
        int idNumber;
        string department;
        string position;
    public:
        Employee(string,int,string,string);
        Employee(string,int);
        Employee();
        void setName(string);
        void setID(int);
        void setDept(string);
        void setPos(string);
        string getName(){return name;}
        int getID(){return idNumber;}
        string getDept(){return department;}
        string getPos(){return position;}
        void outputEmpInfo(string,int,string,string);   
};

#endif	/* EMPLOYEE_H */

