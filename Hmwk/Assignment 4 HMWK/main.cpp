/* 
 * File:   main.cpp
 * Author: Nicholas Cardinal
 *
 * Created on May 6, 2015, 6:46 PM
 */
//Library includes Here!!!
#include <cstdlib>
#include <iostream>
#include "Date.h"
#include "Employee.h"
#include "Car.h"
#include "Inventory.h"
#include "RetailItem.h"
#include "Numbers.h"
#include "DayOfYear.h"
#include "DayOfYearv2.h"
#include "NumDays.h"
#include "Month.h"
using namespace std;

//Global Constants Here!!!

//Function Prototypes Here!!!
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();



//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        case 7:    problem7();break;
        case 8:    problem8();break;
        case 9:    problem9();break;
        case 10:    problem10();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=10);
    return 0;
}

void Menu(){
    cout<<"Menu for Assignment 4"<<endl;
    cout<<"Type 1 for problem 13.1"<<endl;
    cout<<"Type 2 for problem 13.2"<<endl;
    cout<<"Type 3 for problem 13.3"<<endl;
    cout<<"Type 4 for problem 13.6"<<endl;
    cout<<"Type 5 for problem 13.5"<<endl;
    cout<<"Type 6 for problem 14.1"<<endl;
    cout<<"Type 7 for problem 14.2"<<endl;
    cout<<"Type 8 for problem 14.3"<<endl;
    cout<<"Type 9 for problem 14.4"<<endl;
    cout<<"Type 10 for problem 14.7"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
        cout<<"In problem # 13.1"<<endl<<endl;
    Date date;
    int day;
    int year;
    int month;
    cout << "Enter the month of the year as an integer: "; 
    cin >> month;
    date.setMonth(month);
    cout << "Enter the day of the year: ";
    cin >> day;
    date.setDay(day);
    cout << "Enter the year: ";
    cin >> year;
    date.setYear(year);
    
    date.shortDate(month,day,year);
    cout << endl;
    date.standardDate(month,day,year);
    cout << endl;
    date.mlaDate(month,day,year);
    
    cout<<endl<<endl<<endl;
}

void problem2(){
        cout<<"In problem # 13.2"<<endl<<endl;
    Employee susan("Susan Meyers", 47899, "Accounting", "Vice President");
    Employee mark("Mark Jones", 39119, "IT", "Programmer");
    Employee joy("Joy Rogers", 81774, "Manufacturing", "Engineer");
    
    susan.outputEmpInfo(susan.getName(),susan.getID(),susan.getDept(),susan.getPos());
    cout << endl;
    mark.outputEmpInfo(mark.getName(),mark.getID(),mark.getDept(),mark.getPos());
    cout << endl;
    joy.outputEmpInfo(joy.getName(),joy.getID(),joy.getDept(),joy.getPos());
    cout<<endl<<endl<<endl;
}

void problem3(){
        cout<<"In problem # 13.3"<<endl<<endl;
    int yearModel;
    string make;
    cout << "Enter the year your car was made: ";
    cin >> yearModel;
    cout << "Enter the make of your car: ";
    cin >> make;
    Car car(yearModel, make);
    cout << "The speed of your " << car.getYM() << " " << car.getMake()
         << " is increasing!" << endl;
    for(int i=0;i<5;i++){
        car.accelerate();
        cout << "Car speed: " << car.getSpeed() << endl;
    }
    
    cout << "The speed of your " << car.getYM() << " " << car.getMake()
         << " is decreasing!" << endl;
    for(int i=0;i<5;i++){
        car.brake();
        cout << "Car speed: " << car.getSpeed() << endl;
    }
    cout<<endl<<endl<<endl;
}

void problem4(){
        cout<<"In problem # 13.6"<<endl<<endl;
    int itemNumber;
    int quantity;
    float cost;
    cout << "Enter the item number: ";
    cin >> itemNumber;
    cout << "Enter the quantity of the item: ";
    cin >> quantity;
    cout << "Enter the cost of the item: ";
    cin >> cost;
    Inventory ralphs(itemNumber,quantity,cost);
    
    cout << "Item Number: " << ralphs.getItemNumber() << endl;
    cout << "Quantity: " << ralphs.getQuantity() << endl;
    cout << "Cost: " << ralphs.getCost() << endl;
    cout << "Total cost: " << ralphs.getTotalCost() << endl;  
    
    cout<<endl<<endl<<endl;
}

void problem5(){
        cout<<"In problem # 13.5"<<endl<<endl;
        
    RetailItem item1("Jacket", 12, 59.95);
    RetailItem item2("Designer Jeans", 40, 34.95);
    RetailItem item3("Shirt", 20, 24.95);
    
    cout << "Item #1 " <<item1.getDesc()<<" "<< item1.getUnits()<<" "<<item1.getPrice();
    cout << endl;
    cout << "Item #2 " <<item2.getDesc()<<" "<< item2.getUnits()<<" "<<item2.getPrice();
    cout << endl;
    cout << "Item #3 " <<item3.getDesc()<<" "<< item3.getUnits()<<" "<<item3.getPrice();
    
    cout<<endl<<endl<<endl;
}

void problem6(){
        cout<<"In problem # 14.1"<<endl<<endl;
    int nums;
    cout << "Enter a number between 0-9999" << endl;
    cin >> nums;
    while(nums < 0 || nums > 10000){
        cout << "Enter a number between 0-9999" << endl;
        cin >> nums;
    }
    cout << "Your input: ";
    Numbers num(nums);
    num.print();
    
    cout<<endl<<endl<<endl;
}

void problem7(){
        cout<<"In problem # 14.2"<<endl<<endl;
    int day;
    cout << "Enter a day 1-365: " << endl;
    cin >> day;
    DayOfYear date(day);
    cout << "You entered: " << endl;
    date.print();
    
    cout<<endl<<endl<<endl;
}

void problem8(){
        cout<<"In problem # 14.3"<<endl<<endl;
    int day;
    string month;
    cout << "Enter a month of the year using an uppercase for the first letter: " << endl;
    cin >> month;
    cout << "Enter a day of the year 1-31: " << endl;
    cin >> day;
    DayOfYearv2 date(month, day);
    cout << "You entered: ";
    date.printv2();
    cout << endl;
    cout << "The next day is: ";
    if(day != 31){
        date++;
    }
    else{
        date.print();
    }
    
    cout<<endl<<endl<<endl;
}

void problem9(){
        cout<<"In problem # 14.4"<<endl<<endl;
    int hours;
    cout << "Enter how many hours you worked this week: ";
    cin >> hours;
    NumDays tri(hours);
    cout << "Your hours converted into days is: ";
    tri.convert(hours);
    
    cout<<endl<<endl<<endl;
}

void problem10(){
        cout<<"In problem # 14.7"<<endl<<endl;
    string month;
    int monthNum;
    cout << "Please type in a month: ";
    cin >> month;
    Month kyle(month);
    kyle.print();
    cout << endl;
    cout << "The previous month is: ";
    kyle--;
    kyle.print();
    cout << endl;
    cout << "Please enter a month 1-12: ";
    cin >> monthNum;
    Month nick(monthNum);
    nick.print();
    cout << endl;
    cout << "The next month is: ";
    nick++;
    nick.print();
    
    cout<<endl<<endl<<endl;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

