/* 
 * File:   ProductionWorker.h
 * Author: Owner
 *
 * Created on May 21, 2015, 6:58 PM
 */

#ifndef PRODUCTIONWORKER_H
#define	PRODUCTIONWORKER_H
#include "Employee.h"
class ProductionWorker : public Employee{
    private:
        int shift;
        float rate;
    public:
        ProductionWorker() : Employee()
        {shift = 0; rate = 0;}
        ProductionWorker(int s, float r, std::string n, int num, int d) : Employee(n,num,d)
        {shift = s, rate = r;}
        void setShift(int);
        int getShift(){return shift;}
        void setRate(int r){rate = r;}
        float getRate(){return rate;}
        void output();
};

#endif	/* PRODUCTIONWORKER_H */

