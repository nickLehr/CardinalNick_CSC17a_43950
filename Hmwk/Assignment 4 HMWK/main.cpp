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
        default:   def(inN);}
    }while(inN>=1&&inN<=10);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type 7 for problem 7"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
        cout<<"In problem # 1"<<endl<<endl;
            Date date;
    int day;
    int year;
    int month;
    cout << "Enter the month of the year: "; 
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
        cout<<"In problem # 2"<<endl<<endl;
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
        cout<<"In problem # 3"<<endl<<endl;
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
        cout<<"In problem # 4"<<endl<<endl;
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
}

void problem5(){
        cout<<"In problem # 5"<<endl<<endl;
}

void problem6(){
        cout<<"In problem # 6"<<endl<<endl;
}

void problem7(){
        cout<<"In problem # 7"<<endl<<endl;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

