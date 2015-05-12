/* 
 * File:   Numbers.h
 * Author: Owner
 *
 * Created on May 10, 2015, 6:19 PM
 */

#ifndef NUMBERS_H
#define	NUMBERS_H
using namespace std;
class Numbers{
    private:
        int number;
        static string lessThan20[20];
        static string hundred;
        static string thousand;
        static string multiples10[9];
        int thousandth;
        int hundredth;
        int tenth;
        int first;
        string multiple;
    public:
        Numbers(int);
        void breakDown(int);
        void print();
        int getDigits(int);
        void getMult();
};


#endif	/* NUMBERS_H */

