/* 
 * File:   TeamLeader.h
 * Author: Owner
 *
 * Created on May 22, 2015, 5:51 PM
 */

#ifndef TEAMLEADER_H
#define	TEAMLEADER_H
#include "Employee.h"
#include "ProductionWorker.h"
class TeamLeader :  public Employee{
    private:
        int bonus;
        int trainingHrs;
        int rate;
    public:
        //TeamLeader() : ProductionWorker(), Employee()
        //{bonus = 0; trainingHrs = 0;}
        //TeamLeader(int mb, int t,int s, float r, std::string n, int num, int d) : ProductionWorker(s,r,n,num,d)
        //{bonus = mb; trainingHrs = t;}
        virtual void setBonus(int b)
        {bonus = b;}
        void setHrs(int h)
        {trainingHrs = h;}
        void setRate(float s)
        {rate = s;}
        int getBonus(){return bonus;}
        int getHrs(){return trainingHrs;}
        int getRate(){return rate;}
};

#endif	/* TEAMLEADER_H */

