/* 
 * File:   DayOfYear.h
 * Author: Owner
 *
 * Created on May 11, 2015, 11:21 AM
 */

#ifndef DAYOFYEAR_H
#define	DAYOFYEAR_H
using namespace std;

class DayOfYear{
    private:
        int dayOfYear;
        static string month[12];
    public:
        DayOfYear(int);
        void print();
};


#endif	/* DAYOFYEAR_H */

