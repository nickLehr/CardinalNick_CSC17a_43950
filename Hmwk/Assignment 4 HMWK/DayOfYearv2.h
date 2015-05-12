/* 
 * File:   DayOfYearv2.h
 * Author: Owner
 *
 * Created on May 11, 2015, 12:13 PM
 */

#ifndef DAYOFYEARV2_H
#define	DAYOFYEARV2_H
using namespace std;
#include <string>
class DayOfYearv2{
    private:
        int dayOfYear;
        static string month[12];
        string monthy;
    public:
        DayOfYearv2(int);
        DayOfYearv2(string,int);
        void print();
        void printv2();
        DayOfYearv2 operator++();
        DayOfYearv2 operator++(int);
        DayOfYearv2 operator--();
        DayOfYearv2 operator--(int);
};


#endif	/* DAYOFYEARV2_H */

