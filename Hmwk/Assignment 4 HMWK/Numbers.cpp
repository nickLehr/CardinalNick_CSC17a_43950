/* 
 * File:   Numbers.cpp
 * Author: Owner
 *
 * Created on May 10, 2015, 6:20 PM
 */

#include <cstdlib>
#include <iostream>
#include "Numbers.h"
using namespace std;

string Numbers::lessThan20[20] = {"one","two","three","four","five","six","seven",
                                 "eight", "nine", "ten","eleven","twelve","thirteen",
                                 "fourteen","fifteen","sixteen","seventeen","eighteen",
                                 "nineteen"};
string Numbers::multiples10[9] = {"twenty","thirty","forty","fifty","sixty",
                                  "seventy","eighty","ninety"};
string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";

Numbers::Numbers(int num){
    if(num < 0){
        cout << "Please enter a nonnegative number.";
    }
    else{
        if(num == 0){
            print();
        }
        breakDown(num);
        if(tenth >= 2){
            getMult();
        }
    }
}

void Numbers::breakDown(int num){
    if(getDigits(num) == 4){
        thousandth = num / 1000 % 10;
        hundredth = num / 100 % 10;
        tenth = num / 10 % 10;
        first = num % 10;  
    }
    else if(getDigits(num) == 3){
        thousandth = 0;
        hundredth = num / 100 % 10;
        tenth = num / 10 % 10;
        first = num % 10;  
    }
    else if(getDigits(num) == 2){
        thousandth = 0;
        hundredth = 0;
        tenth = num / 10 % 10;
        first = num % 10;
    }
    else{
        thousandth = 0;
        hundredth = 0;
        tenth = 0;
        first = num % 10;
    }
}

void Numbers::print(){
        if(thousandth == 0 && hundredth == 0 && tenth == 0 && first == 0){
        cout << "zero";
    }
    else if(thousandth == 0 && hundredth == 0 && tenth == 0){
        cout << lessThan20[first-1];
    }
    else if(thousandth == 0 && hundredth == 0 && tenth < 2){
        cout << lessThan20[(first+(tenth*10))-1];
    }
    else if(thousandth == 0 && hundredth == 0 && tenth >= 2){
        cout << multiple << " ";
        if(first > 0){
            cout << lessThan20[first-1];
        }
    }
    else if(thousandth == 0){
        cout << lessThan20[hundredth-1] << " " <<  hundred << " "; 
        if(tenth > 0){
            cout << multiple << " ";
        }
        if(first > 0){
            cout << lessThan20[first-1];
        }
    }
    else{
        cout << lessThan20[thousandth-1] << " " << thousand << " ";
        if(hundredth > 0){
            cout << lessThan20[hundredth-1] << " " << hundred << " ";
        }
        if(tenth > 0){
            cout << multiple << " ";
        }
        if(first > 0){
            cout << lessThan20[first-1];
        }
    }
}

int Numbers::getDigits(int n){
    int digits = 0;
    while (n != 0) {
        n /= 10;
        digits++;
    }
    return digits;
}
    
void Numbers::getMult(){
    multiple = multiples10[tenth - 2];
}


