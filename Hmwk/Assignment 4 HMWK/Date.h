/* 
 * File:   Date.h
 * Author: Owner
 *
 * Created on May 6, 2015, 6:51 PM
 */

#ifndef DATE_H
#define	DATE_H
#include <iostream>
class Date{
    private:
        int month;
        int day;
        int year;
    public:
        int getMonth(){return month;}
        int getDay(){return day;}
        int getYear(){return year;}
        void setMonth(int);
        void setYear(int);
        void setDay(int);
        void shortDate(int,int,int);
        void standardDate(int,int,int);
        void mlaDate(int,int,int);
}; 


#endif	/* DATE_H */

