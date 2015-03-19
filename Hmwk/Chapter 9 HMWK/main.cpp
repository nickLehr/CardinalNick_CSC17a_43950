/* 
 * File:   main.cpp
 * Author: Nicholas Cardinal
 *
 * Created on March 8, 2015, 2:48 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

bool select();
void bubbleSort(int [], int);
int menu();
void num1();                   //Num 1 main;
int *num11(int);               //Num 1 problem. Dynamically allocate memory;  
void num2();                   //Num 2 main;
void calcAvg(int *, int);      //Num 2 problem. Calculates the average for the array in no.2;
void num5();                   //Num 5 main;
int doSomething(int *, int *); //Num 5 doSomething function from Gaddis book v7
int num6();                    //Num 6 main;
void arrSelectSort(int *[], int);   //~~~~~~
void showArray(const int [], int);  //Functions from Gaddis book v7 for #6
void showArrPtr(int *[], int);      //~~~~~
void num8();                     //Num 8 main;
int *fndMode(int *, int, int *); //Num 8 function to find the mode of the array.
void num9();                     //Num 9 main;
float fndMedi(int *, int);       //Num 9 function to find the median of the array.
void num10();                    //Num 10 main;
void num13();                    //Num 13 main;
int *flipArr(int *, int);
float mean(int [],int);

int main(int argc, char** argv) {
   srand(time(0));
    do{
        int choice = menu();
        switch(choice){
            case 1: 
                 num1(); 
                break;
            case 2:
                num2();
                break;
            case 3:
                num5();
                break;
            case 4:
                num6();
                break;
            case 5:
                num8();
                break;
            case 6:
                num9();
            case 7:
                num10();
                break;
            case 8:
                num13();
                break;
        }
    }while(select());
    return 0;
}
int menu(){
    int choice;
    do{
        cout << endl << endl;
        cout << "Homework Problems: Assignment #1" << endl;
        cout << "[1] Problem 1" << endl;
        cout << "[2] Problem 2/3" << endl;
        cout << "[3] Problem 5" << endl;
        cout << "[4] Problem 6/7" << endl;
        cout << "[5] Problem 8 (Mean, Median, Mode)" << endl;
        cout << "[6] Problem 9" << endl;
        cout << "[7] Problem 10" << endl;
        cout << "[8] Problem 13" << endl;
        cout << "Enter a choice:  ";
        cin >> choice;
        if(!cin){
            cout << "Invalid, enter again: " << endl;
            cin.clear();
            cin.ignore();
            cin >> choice;
        }
        cout<<"=============================================="<<endl;
    }while(choice != 1 && choice!= 2 && choice != 3 && choice != 4
            && choice != 5 && choice != 6 && choice != 7 && choice != 8);
    return choice;
}

void num1(){
    const int SIZE = 10;
    num11(SIZE);
}
int *num11(int SIZE){
    int *p1;
    p1 = new int[SIZE];
    cout << p1 << endl;
    delete [] p1;
    p1 = 0;
    return p1;
}
void num2(){
    int noOfScrs;   //Hold the number of test scores the user wishes to enter.
    cout << "How many scores tests will you be entering? ";
    cin >> noOfScrs;
    int *scrPtr;    //Pointer that point dynamically allocates for the array.
    scrPtr = new int[noOfScrs];
    int testScr;   //Hold the value of each test score.
    cout << "You many now begin entering scores: " << endl;
    
    for(int i = 0; i < noOfScrs; i++){
        cout << "Enter score: ";
        cin >> testScr;
        if(testScr < 0){
            cout << "INVALID! PLEASE ENTER A NON NEGATIVE NUMBER" << endl;
            i--;
        }
        else{
        *(scrPtr + i) = testScr;
        }
    }
    bubbleSort(scrPtr, noOfScrs);
    calcAvg(scrPtr, noOfScrs);
    cout << "Here are your test scores: ";
    for(int i = 0; i < noOfScrs; i++){
        cout << *(scrPtr + i) << " ";
    }
    
    delete [] scrPtr;
    scrPtr = 0;
    
}
void calcAvg(int *scrPtr, int noOfScrs){
    int total;      //Stores the total of all test scores added together.
    for(int i = 0; i < noOfScrs; i++){
        total += *(scrPtr +i);
    }
    cout << "The lowest test score has been dropped." << endl;
    *(scrPtr + 0) = 0;
    float average = (total / noOfScrs);
    cout << "The average of the test scores is: " << average << endl;
}
void num5(){
    int *x,*y;
    int x1,y1;
    x = &x1;
    y = &y1;
    cout << "Enter a number: ";
    cin >> x1;
    cout << "Enter another number: ";
    cin >> y1;
    doSomething(x,y);
    cout << "You numbers multiplied by 10 and added together are " << *x+*y
         << endl;
    
}
int doSomething(int *x, int *y){
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x+*y;
}
int num6(){
     int numDonations;      //Holds the number of donations received. 
     cout << "Enter the number of donations you have received: ";
     cin >> numDonations;
     int *donArr;          //Dynamic array to store the donations
     donArr = new int[numDonations];
     cout << "You may now begin entering the donations: " << endl;
     for(int i = 0; i < numDonations; i++){
         int donation;
         cout << "Enter donation #" << i + 1 << ": ";
         cin >> donation;
         *(donArr + i) = donation;
     }
     
    int *arrPtr[numDonations]; //A pointer array to point at the donations array.
    
    //Points all elements of arrPtr to the donations in numDona.
    for (int i = 0; i < numDonations; i++){
        arrPtr[i] = &donArr[i];
    }
    
    // Sort the elements of the array of pointers.
    arrSelectSort(arrPtr, numDonations);

    // Display the donations using the array of pointers. This
    // will display them in sorted order.
    cout << "The donations, sorted in descending order, are: " << endl;
    showArrPtr(arrPtr, numDonations);
    cout << endl;
    // Display the donations in their original order.
    cout << "The donations, in their original order, are: \n";
    showArray(donArr, numDonations);
    
    delete [] donArr;
    donArr = 0;
    return 0;
}
void num8(){
    const int SIZE = 10;
    int mode[SIZE] = {1,1,0,0,5,5,7,8,9,9};
    bubbleSort(mode, SIZE);
    cout << "The Original Array: " << endl;
    for(int i = 0; i < SIZE; i++){
        cout << *(mode + i) << " ";
    }
    int *modeArr; //Pointer to dynamically allocate the size of the array of modes
                  //after number of modes is found.
    modeArr = fndMode(mode, SIZE, modeArr); 
    cout << endl;
    cout << "Mode Array: " << endl;
    for(int i = 0; i < modeArr[0]+2; i++){
        cout << *(modeArr + i) << " ";
    }
    cout << endl;
    cout << endl;
    int median = fndMedi(mode, SIZE);
    cout << "The median of this array is: " << median << endl;
    mean(mode, SIZE);
    
    
    delete [] modeArr;
    modeArr = 0;
} 
int *fndMode(int *arr, int SIZE, int *modeArr){
    int arr2[SIZE];    //Stores the number of occurrences of each number.
    int highest = 0;   //Stores the highest number of occurrences. 
    int othrMde = 0;
    int mode;
    //cout << "Array 1: " << endl;
    for(int i = 0; i < SIZE; i++){ //Initializes all values of my arr2 to 0;
        *(arr2 + i) = 0;
       //cout << *(arr + i) << " ";
    }
    cout << endl; 
    for(int i = 0; i < SIZE; i++){     //Adds 1 to an array element when it
        arr2[arr[i]] = arr2[arr[i]]+1; //detects 2 numbers are the same
    }
    for(int i = 0; i < SIZE; i++){//Runs through arr2[] to check for the highest 
        if(arr2[i] > highest){    //number of occurrences of numbers from arr[];
            highest = *(arr2 + i);
            mode = i;
        }
    }
    if(highest == 1){
        cout << "No mode found!" << endl;
        
    }
    for(int i = 0; i < SIZE; i++){ //Sets arr1 to 0-9 after the modes have been
        *(arr + i) = i;            //found. 
    }
    /*cout << "Array 2: " << endl;
    for(int i = 0; i < SIZE; i++){
        cout << *(arr2 + i) << " ";
    }*/
    int count = 0;
    for(int i = 0; i < SIZE; i++){ //Finds the number of modes.
        if(arr2[i] == highest){
            count++;
        }
    }
    modeArr = new int[count+2];
    int index = 2;
    *(modeArr + 0) = count;  //Sets the first element to the number of modes.
    *(modeArr + 1) = highest;//Sets the second element to the freq of the modes.
    for(int i = 0; i < SIZE; i++){
        if(arr2[i] == highest){
            modeArr[index] = arr[i];
            index++;
        }
    }
    return modeArr;
}
void num9(){
    const int SIZE = 10;    //Change size of array to get different results.
    int medArr[SIZE] = {1,2,3,4,5,6,6,7,8,9}; //Chance numbers in array to get different result.
    cout << fndMedi(medArr, SIZE);
}
float fndMedi(int *arr, int SIZE){
    int counter = 0;          //Counter to find out if there is an odd or even number of elements.
    for(int i = 0; i < SIZE; i++){
        counter++;
    }
    int pos = counter / 2;
    int pos2 = pos - 1;
    if(counter % 2 == 0){
       float mediOdd = (static_cast<float>(*(arr + pos)) + *(arr + pos2))/2;
       cout << "There is an odd amount of numbers in this array." << endl;
       cout << "The median is: ";
       return mediOdd;
    }
    else{
        int middle = SIZE / 2;
        int mediEvn = *(arr + middle);
        cout << "There is an even amount of numbers in this array." << endl;
        cout << "The median is: ";
        return mediEvn;
    }
}
float mean(int arr[], int SIZE){
    float total;
    for(int i = 0; i < SIZE; i++){
        total += arr[i];
    }
    float mean = 0;
    mean = (total / SIZE);
    cout << "The mean of this array is: " << mean << endl;
    return mean;
}
void num10(){
    const int SIZE = 5;
    int origArr[SIZE] = {1,2,3,4,5};
    for(int i = 0; i < SIZE; i++){
        cout << *(origArr + i) << " ";
    }
    cout << endl;
    cout << "The array in reverse order is." << endl;
    cout << flipArr(origArr, SIZE);
}
int *flipArr(int *arr, int SIZE){
    int backArr = SIZE - 1;
    
    for(int i = 0; i < SIZE; i++){
        *(arr + backArr) = *(arr +i); 
    }
    for(int i = 0; i < SIZE; i++){
        cout << *(arr + i) << " ";
    }
    return arr;
}
void num13(){
    int surveyd = 0;
    
    cout << "How many students participated in your survey?";
    cin >> surveyd;
    
    int *stdnts;
    stdnts = new int[surveyd];
    
    cout << "You may now begin entering the number of movies each"
            "student has seen." << endl;
    int value;
    for(int i = 0; i < surveyd; i++){
    cout << "Enter a value: ";
    cin >> value;
    *(stdnts + i)  = value;
    }
    
    bubbleSort(stdnts, surveyd);
    for(int i = 0; i < surveyd; i++){
        cout << *(stdnts + i) << " ";
    }
    cout << endl;
    int *modeArr; //Pointer to dynamically allocate the size of the array of modes
                  //after number of modes is found.
    fndMode(stdnts, surveyd, modeArr);
    cout << fndMedi(stdnts, surveyd);
    cout << endl;
    calcAvg(stdnts, surveyd);
    
    delete [] stdnts;
    delete [] modeArr;
    stdnts = 0;
}
void arrSelectSort(int *arr[], int size){
    int startScan, minIndex;
    int *minElem;

    for (startScan = 0; startScan < (size - 1); startScan++){
        minIndex = startScan;
        minElem = arr[startScan];
        
    for(int i = startScan + 1; i < size; i++){
        if (*(arr[i]) > *minElem)
        {
            minElem = arr[i];
            minIndex = i;
        }
    }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minElem;
  }
}
void showArray(const int arr[], int size){
    for (int i = 0; i < size; i++){
            cout << arr[i] << " ";
    }
}
void showArrPtr(int *arr[], int size){
    for(int i = 0; i < size; i++){
        cout << *(*arr + i) << " ";
    }
}
bool select(){
    cout << endl;
    cin.clear();
    cin.ignore();
    cout << "Do you want to select another problem? [y/n]:  ";
    char choice;
    cin.get(choice);
    if(choice=='y'){
        return true;
    }
    else{
        return false;
    }
}
void bubbleSort(int a[], int SIZE){
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE-1l; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
            }
        }
    }
}