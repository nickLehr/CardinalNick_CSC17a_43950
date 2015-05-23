/* 
 * File:   ShiftSupervisor.h
 * Author: Owner
 *
 * Created on May 21, 2015, 7:41 PM
 */

#ifndef SHIFTSUPERVISOR_H
#define	SHIFTSUPERVISOR_H
#include "Employee.h"
class ShiftSupervisor : public Employee{
    private:
        float salary;
        int prodBonus;
        int goal;
    public:
        ShiftSupervisor()
        {salary = 0; prodBonus = 0;}
        ShiftSupervisor(float s, int p, int g, std::string n, int num, int d) : Employee(n,num,d)
        {salary = s; prodBonus = p; goal = g;}
        void setSalary(float s)
        {salary = s;}
        void setBonus(int b)
        {prodBonus = b;}
        void setGoal(int g)
        {goal = g;} 
        int getSalary(){return salary;}
        int getBonus(){return prodBonus;}
        int getGoal(){return goal;}
        void output(ShiftSupervisor&);
};

#endif	/* SHIFTSUPERVISOR_H */

