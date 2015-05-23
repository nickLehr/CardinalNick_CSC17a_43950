/* 
 * File:   main.cpp
 * Author: Nicholas Thomas Cardinal
 *
 * Created on May 20, 2015, 8:33 PM
 */

//Library includes Here!!!
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ProductionWorker.h"
#include "ShiftSupervisor.h"
#include "TeamLeader.h"
#include "CustomerData.h"
#include "PreferedCustomer.h"
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
ShiftSupervisor* setUp();
void miniGame(TeamLeader);

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
        default:   def(inN);}
    }while(inN>=1&&inN<=5);
    return 0;
}

void Menu(){
    cout<<"Menu for Assignment 5"<<endl;
    cout<<"Type 1 for problem 15.1"<<endl;
    cout<<"Type 2 for problem 15.2"<<endl;
    cout<<"Type 3 for problem 15.3"<<endl;
    cout<<"Type 4 for problem 15.7"<<endl;
    cout<<"Type 5 for problem 15.8"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
        cout<<"In problem # 15.1"<<endl<<endl;
    ProductionWorker erick;
    string name;
    int num,date,shift;
    float rate;
    cout << "Enter the employee's first name: ";
    cin >> name;
    erick.setName(name);
    cout << "Enter " << erick.getName() << "'s employee number: ";
    cin >> num;
    cout << "Enter " << erick.getName() << "'s date of hire: ";
    cin >> date;
    cout << "Enter " << erick.getName() << "'s shift number (1 or 2): ";
    cin >> shift;
    cout << "Enter " << erick.getName() << "'s rate of pay: ";
    cin >> rate;
    ProductionWorker jones(shift,rate,name,num,shift);
    cout << endl;
    jones.output();
    cout<<endl<<endl<<endl;
}

void problem2(){
        cout<<"In problem # 15.2"<<endl<<endl;
    string input = " ";
    ShiftSupervisor *joe;
    joe = setUp();
    cout<<endl<<endl<<endl;
}

void problem3(){
        cout<<"In problem # 15.3"<<endl<<endl;
    srand(time(0));
    string name;
    int num,date,bonus,training;
    float salary;

    cout << "Enter the employee's name: ";
    cin >> name;
    cout << "Enter the employee's number: ";
    cin >> num;
    cout << "Enter the employee's date of hire: ";
    cin >> date;
    cout << "Enter the employee's salary: ";
    cin >> salary;
    cout << "Enter the employee's monthly bonus: ";
    cin >> bonus;
    cout << "Enter the employee's required amount of training per year: ";
    cin >> training;
    try{
    TeamLeader carlos;
    carlos.setBonus(bonus);
    carlos.setDate(date);
    carlos.setHrs(training);
    carlos.setName(name);
    carlos.setNum(num);
    carlos.setRate(salary);
    cout << "Hello " << carlos.getName() << "! Welcome to your first month!" << endl;
    cout << "We are going to start you off with a pay rate of: " << carlos.getRate() << endl;
    cout << "You need to do some training for the month!" << endl;
    miniGame(carlos);
    cout << "It's been one month! Your bonus is in!" << endl;
    cout << "You have received a " << carlos.getBonus() << "!" << endl;
    cout << "Your rate is $" << carlos.getRate() << " per month!" << endl;
    carlos.setRate((carlos.getRate() * 31));
    float moneys = carlos.getRate();
    cout << "Your have now made: $" << moneys << "!";
    cout<<endl<<endl<<endl<<endl;
    cout << "You have now been fired! :(";
    }
    catch(string msg){cout << msg;}
    
    cout<<endl<<endl<<endl;
}

void problem4(){
        cout<<"In problem # 15.7"<<endl<<endl;
    string fName,lName,city,state,addy;
    int zip,phone;
    bool list;
    char input;
    CustomerData krule;
    krule.setCustNum(23949);
    cout << "Welcome customer! Enter your first name: " << endl;
    cin >> fName;
    krule.setFName(fName);
    cout << krule.getFName() << ", please enter your last name: ";
    cin >> lName;
    krule.setLName(lName);
    cout << "Welcome " << krule.getFName() << " " << krule.getLName() << "!" << endl;
    cout << "Please enter your street name: ";
    cin >> addy;
    krule.setAddress(addy);
    cout << "Please enter your city: ";
    cin >> city;
    krule.setCity(city);
    cout << "Please enter your state: ";
    cin >> state;
    krule.setState(state);
    cout << "Please enter your zip-code: ";
    cin >> zip;
    krule.setZip(zip);
    cout << "Would you like to provide your phone number? [y/n]";
    cin >> input;
    if(input == 'y'){
        cout << "Enter your phone number: ";
        cin >> phone;
        krule.setPhone(phone);
    }
    else{
        cout << "You have chosen no." << endl;
        krule.setPhone(0);
    }
    cout << "Would you like to be added to the mailing list? (0 = No, 1 = Yes)" ;
    cin >> list;
    krule.setML(list);
    cout<<endl<<endl<<endl;
    cout << "Thank you for subscribing to Poultry Painters Anonymous!" << endl;
    cout << "Here is the information you have provided: " << endl;
    cout << krule.getFName() << " " << krule.getLName() << endl;
    cout << krule.getAddress() << " " << krule.getCity() << " " << krule.getState()
            << " " << krule.getZip() << endl;
    if(krule.getPhone() == 0){
        cout << "You did not provide a phone number" << endl;
    }
    else{
        cout << krule.getPhone() << endl;;
    }
    if(krule.getML() == 1){
        cout << "You are part of the mailing list!";
    }
    else{
        cout << "You are not part of the mailing list!";
    }
    cout<<endl<<endl<<endl;
}

void problem5(){
        cout<<"In problem # 5"<<endl<<endl;
        string fName,lName;
    int zip,phone;
    float amnt;
    PreferedCustomer angel;
    cout << "Welcome customer! Enter your first name: " << endl;
    cin >> fName;
    angel.setFName(fName);
    cout << angel.getFName() << ", please enter your last name: ";
    cin >> lName;
    angel.setLName(lName);
    cout << "Welcome " << angel.getFName() << " " << angel.getLName() << "!" << endl;
    cout << angel.getFName() << " " << angel.getLName() << ", how much did you spend this evening? $";
    cin >> amnt;
    angel.setPAmount(amnt);
    cout << "Well good thing you shopped at Nick's Shoe Barn because " << endl;
    cout << "with a discount level of " << angel.getDiscLvl() << " you saved: $";
    cout << (angel.getDiscLvl() * angel.getPAmount()) << "!";
    cout<<endl<<endl<<endl;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

ShiftSupervisor* setUp(){
        string name;
        int num,date,goal,bonus;
        float salary;
        cout << "Enter the employee's name: ";
        cin >> name;
        cout << "Enter the employee's number: ";
        cin >> num;
        cout << "Enter the employee's date of hire: ";
        cin >> date;
        cout << "Enter the employee's salary: ";
        cin >> salary;
        cout << "Enter the employee's target production goal: ";
        cin >> goal;
        cout << "Enter the bonus the employee will receive when the goal is reached: ";
        cin >> bonus;
        ShiftSupervisor joe(salary,bonus,goal,name,num,date);
        ShiftSupervisor *j = &joe;
        joe.output(joe);
        cout<<endl<<endl<<endl;
        return j;
}

void miniGame(TeamLeader c){
    int randNum = 0;
    int input;
    static int totalHrs = c.getHrs();
    int hrs = c.getHrs();
    cout << "Welcome to training " << c.getName() << "!" << endl;
    cout << "You need to complete " << c.getHrs() << " of training!" << endl;
    cout << "Enter the number that appears!" << endl;
    for(int i=0;i<totalHrs;i++){
        randNum = rand()% 20 + 3;
        cout << "The number is: " << randNum << endl;
        cin >> input;
        if(input != randNum){
            cout << "Wrong! You failed training, you've gained hours!" << endl;
            hrs++;
            cout << "You now have " << hrs << " hours remaining!" << endl;
        }
        else{
            hrs--;
            cout << "Correct! You now have " << hrs << " hours remaining!" << endl;
         }
    }
}