/* 
 * File:   CustomerData.h
 * Author: Owner
 *
 * Created on May 22, 2015, 7:03 PM
 */

#ifndef CUSTOMERDATA_H
#define	CUSTOMERDATA_H
#include "PersonData.h"
#include <iostream>
using std::cout;
using std::endl;
class CustomerData : public PersonData{
    private:
        int customerNumber;
        bool mailingList;
    public:
        void setCustNum(int n)
        {customerNumber = n;}
        void setML(bool m)
        {   
            mailingList = m;
            if(m != 0 && m!=1){
            cout << "You didn't do as told." << endl;
            cout << "Sorry but you have been added to the mailing list!"<<endl;
            }
        }
        int getCustNum(){return customerNumber;}
        bool getML(){return mailingList;}
};

#endif	/* CUSTOMERDATA_H */

