/* 
 * File:   Inventory.cpp
 * Author: Owner
 *
 * Created on May 6, 2015, 9:22 PM
 */

#include <cstdlib>
#include "Inventory.h"
using namespace std;

Inventory::Inventory(){
    itemNumber = 0;
    quantity = 0;
    cost = 0;
    totalCost = 0;
}

Inventory::Inventory(int iN, int q, float c){
    itemNumber = iN;
    quantity = q;
    cost = c;
    setTotalCost(q,c);
}

void Inventory::setItemNumber(int iN){
    if(iN < 0){
        cout << "Invalid Item Number." << endl;
        itemNumber = 0;
    }
    else{
        itemNumber = iN;
    }
}

void Inventory::setQuantity(int q){
    if(q < 0){
        cout << "Invalid Quantity" << endl;
        quantity = 0;
    }
    else{
        quantity = q;
    }
}

void Inventory::setCost(float c){
    if(c < 0){
        cout << "Invalid Cost" << endl;
        cost = 0;
    }
    else{
        cost = c;
    }   
}

void Inventory::setTotalCost(int q, float c){
    totalCost = q * c;
}
