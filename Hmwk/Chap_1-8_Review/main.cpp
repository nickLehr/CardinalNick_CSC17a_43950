/* 
 * File:   main.cpp
 * Author: Owner
 *
 * Created on March 13, 2015, 12:07 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void num3_12();
void num3_13();
void num4_10();
void num5_11();
void num6_7();
float celsius(float);
void num7_6();

int main(int argc, char** argv) {
    //num3_12();
    //num3_13();
    //num4_10();
    //num5_11();
    //num6_7();
    num7_6();
    return 0;
}
void num3_12(){
    string month;
    string year;
    float total = 0;
    cout << "Enter the month: ";
    cin >> month;
    cout << "Enter the year: ";
    cin >> year;
    cout << "Enter the total amount tendered: ";
    cin >> total;
    
    cout << fixed << showpoint << setprecision(2);
    
    float sales = total / 1.06;
    float cntyTax = (total / 1.02) - sales;
    float statTax = (total / 1.04) - sales;
    float totlTax = cntyTax + statTax;
    
    cout << "Month: " << month << endl;
    cout << "--------------------" << endl;
    cout << "Total Collected:     $ " << setw(9) << total << endl; 
    cout << "Sales:               $ " << setw(9) << sales << endl;
    cout << "County Sales Tax:    $ " << setw(9) << cntyTax << endl;
    cout << "State Sales Tax:     $ " << setw(9) << statTax << endl;
    cout << "Total Sales Tax:     $ " << setw(9) << totlTax << endl;
}
void num3_13(){
    float size;
    cout << "Enter the size of the property in acres: ";
    cin >> size;
    
    float assValu = 0;
    float propTax = 0;
    float acrValu = 0;
    cout << fixed << showpoint << setprecision(2);
    acrValu = size * 10000;
    assValu = acrValu * .60;
    propTax = (assValu / 100) / .64;
    cout << "Assessment value: " << setw(5) << assValu << endl;
    cout << "Property Tax: " << setw(5) << propTax << endl;
    
}
void num4_10(){
    int units;
    cout << "How many units of software were sold? ";
    cin >> units;
    
    int total = units * 99;
    if(units > 0){
    cout << fixed << showpoint << setprecision(2);
    if(units <= 19 && units >= 10){
        cout << "You have received a 20% discount." << endl;
        cout << "The total cost of the purchase was " << setw(8) << total * .20;
    }
    else if(units <= 49 && units >= 20){
        cout << "You have received a 30% discount." << endl;
        cout << "The total cost of the purchase was " << setw(8) << total * .30;
    }
    else if(units <= 99 && units >= 50){
        cout << "You have received a 40% discount." << endl;
        cout << "The total cost of the purchase was " << setw(8) << total * .40;
    }
    else{
        cout << "You have received a 50% discount." << endl;
        cout << "The total cost of the purchase was " << setw(8) << total * .50;
    }
  }
    else{
        cout << "Invalid input! Must enter a number higher than 0";
    }
}
void num5_11(){
    int initPop;
    float popIncr;
    int sex;
    cout << "Welcome to population estimator!" << endl;
    cout << "Enter the starting size of the population: ";
    cin >> initPop;
    cout << "Enter the average daily population increase as a %: ";
    cin >> popIncr;
    cout << "Enter the number of days they will multiply: ";
    cin >> sex;
    
    if(initPop <= 2){
        cout << "INVALID INPUT! Initial population must be higher"
                " than 2.";
    }
    if(popIncr < 0){
        cout << "INVALID INPUT! Population increase must be greater than 0";
    }
    if(sex < 0){
        cout << "INVALID INPUT! Number of days they will multiply must "
                "be greater than 0";
        return;
    }
    
    popIncr = popIncr * .01;
    
    float todaysPop = (initPop * popIncr) + initPop;
    
    for(int i = 1; i < sex + 1; i++){
    cout << "Population Day " << i << " is " << todaysPop << endl;
    todaysPop = (todaysPop * popIncr) + todaysPop;
    }            
}
void num6_7(){
    float f;
    cout << "Enter the temp in Fahrenheit: ";
    cin >> f;
    cout << "Celsius of your entered number: ";
    cout << celsius(f) << endl;
    for(int i = 0; i < 21; i++){
        cout << "Fahrenheit " << i << " Celsius: ";
        cout << celsius(i);
        cout << endl;
    }
}
float celsius(float f){
    float celsius = .55 * (f - 32);
    return celsius;
}
void num7_6(){
    //The problem required the user enters a file name
    //but then tells you to use a pre-set file so I'm using that. 
    string fileName;
    cout << "Enter file name toast.txt: " << endl;
    cin >> fileName;
    
    ifstream infile;
    infile.open("toast.txt");
    const int SIZE = 10;
    int arr[SIZE];
   
    for(int i = 0; i < SIZE; i++){ //Inputs numbers from file into the array.
        infile >> arr[i];
    }
    cout << "The contests of this file is: ";
    for(int i = 0; i < SIZE; i++){ //Outputs array of numbers.
        cout << arr[i] << " ";
    }
    int highest = 0;
    int lowest = 10000;
    float total = 0;
    for(int i = 0; i < SIZE; i++){
        if(highest < arr[i]){ // Finds the highest number in the array.
            highest = arr[i];
        }
        if(lowest > arr[i]){ //Find the lowest number in the array.
            lowest = arr[i];
        }
        total += arr[i]; //Adds all the numbers in the array together.
    }
    float average = total / SIZE; //Calculates the average of all the numbers.
    cout << endl;
    cout << "Lowest: " << lowest << endl;
    cout << "Highest: " << highest << endl;
    cout << "Total: " << total << endl;
    cout << "Average: " << average << endl;
     
    infile.close();
}