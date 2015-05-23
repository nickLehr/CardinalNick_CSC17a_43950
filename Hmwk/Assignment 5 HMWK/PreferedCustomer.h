/* 
 * File:   PreferedCustomer.h
 * Author: Owner
 *
 * Created on May 22, 2015, 7:40 PM
 */

#ifndef PREFEREDCUSTOMER_H
#define	PREFEREDCUSTOMER_H
#include "CustomerData.h"
class PreferedCustomer : public CustomerData{
    private:
        float purchAmnt;
        float discLvl;
    public:
        void setPAmount(float);
        float getPAmount(){return purchAmnt;}
        float getDiscLvl(){return discLvl;}
};


#endif	/* PREFEREDCUSTOMER_H */

