/* 
 * File:   main.cpp
 * Author: Nicholas Cardinal
 *
 * Created on March 29, 2015, 12:21 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

enum Info { blank, NAME, PHONE, TOPIC, FEE };
enum speakerMenu { blnk, ENTER, CHANGE, VIEW };
enum Division { blk, NORTH, SOUTH, EAST, WEST };
//User libraries
//#include <speaker.h>
struct Speaker{
    string name;
    float phoneNum;
    string topic;
    unsigned int fee;
};

struct Data{
    string divName[4];
    float sales[4][4];
};
struct Movie{
    string title;
    string director;
    int year;
    int runTime;
    int prodCost;
    int revenue;
};

//Prototypes
bool select();
bool playAgain();
int menu();
void num103();
int nOfWrds(char *, int);
void num106();
int menu2(char *, int);
int isVowel(char *);
int isCons(char *);
void num119();
void menu3();
void prntEle(Speaker [], int);
Speaker* addElem(Speaker*, int);
Speaker* chngeEle(Speaker []);
void num111();
void prtData(Movie);
void num127();
void num128();
void arrayToFile(string, char *, int);
void fileToArray(string, char *, int);
int num1211();
void num101();

int main(int argc, char** argv) {
    //MAIN FUNTION CONTAINING THE HQ FOR MY MENU
    
   srand(time(0));
    do{
        int choice = menu();
        switch(choice){
            case 1: 
                num103();
                break;
            case 2:
                num106();
                break;
            case 3:
                num119();
                break;
            case 4:
                num111();
                break;
            case 5:
                num127();
                break;
            case 6:
                num128();
                break;
            case 7:
                num1211();
                break;
            case 8:
                num101();
                break;
        }
    }while(select());
    return 0;
}

int menu(){
    //The Menu that is displayed for the user
    int choice;
    do{
        cout << endl << endl;
        cout << "Assignment 3" << endl;
        cout << "[1] Problem 10.3/10.4" << endl;
        cout << "[2] Problem 10.6" << endl;
        cout << "[3] Problem 11.9" << endl;
        cout << "[4] Problem 11.1/11.2" << endl;
        cout << "[5] Problem 12.7" << endl;
        cout << "[6] Problem 12.8" << endl;
        cout << "[7] Problem 12.11" << endl;
        cout << "[8] Problem 10.1" << endl;
        cout << "Enter a choice:  ";
        cin >> choice;
        cin.clear();
        cin.ignore();
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

void num103(){
    const int SIZE = 51;    //Constant int of 32 to set the size of my array.
    char *sntPrt;           //Pointer which points to the char array.
    char sentnce[SIZE];
    sntPrt = sentnce;
    cout << "Enter a sentence (Under 50 character): ";
    cin.getline(sentnce, SIZE, '\n');
    int numWord = nOfWrds(sntPrt,SIZE); //Stores the number of words in "numWord"
    cout << "The number of words in your sentence is " << numWord << "." << endl;
    cout << endl;
    cout << "Press Enter";
}
int nOfWrds(char * text, int SIZE){
    int space=0;  //Counts the number of spaces in the string. 
    int letter=0;   //Counts the number of letters in the array. 
    for(int i=0;i<SIZE;i++){    //For loop to count the number of white space
        if(isspace(text[i])){   //characters in the array. 
            space++;  
        }
    }    
    letter = strlen(text) - space + 1;
    float average = static_cast<float>(letter) / static_cast<float>(space);
    cout << "The average number of letters is " << average <<  "." << endl;
    return space;
}
void num106(){
    const int SIZE = 51;    //Constant int of 51 to set the size of my array.
    char *sntPrt;           //Pointer which points to the char array.
    char sentnce[SIZE];
    sntPrt = sentnce;
    cout << "Enter a sentence (Under 50 character): ";
    cin.clear();
    cin.getline(sentnce, SIZE, '\n');
    menu2(sntPrt, SIZE);
}

int menu2(char * text, int SIZE){
    char choice;
    //Second menu for problem 12.4
    do{
        cout << endl;
        cout << "A) Count the number of vowels in the string." << endl;
        cout << "B) Count the number of consonants in the string." << endl;
        cout << "C) Count both the vowels and consonants in the string." << endl;
        cout << "D) Enter another string." << endl;
        cout << "E) Exit the program." << endl;
        cout << "Enter a choice:  ";
        cin >> choice;
        cout<<"=============================================="<<endl;
        //"Switch" begins.
        //Through char choice.
        if(tolower(choice) == 'a'){                    
            int vowels = isVowel(text);
            cout << "The number of vowels is " << vowels << "." << endl;
            menu2(text, SIZE);
        }
        if(tolower(choice) == 'b'){
            int cons = isCons(text);
            cout << "The number of consonants is " << cons << "." << endl;
            menu2(text, SIZE);
        }
        if(tolower(choice) == 'c'){
            int v = isVowel(text);
            int c = isCons(text);
            cout << "The number of characters in your string is " <<
                    c+v << "." << endl;
            cout << endl;
            num106();
        }
        if(tolower(choice) == 'd'){
            cin.ignore();
            num106();
        }
        if(tolower(choice) == 'e'){

            return 0;
        }
    }while(tolower(choice) != 'a' && tolower(choice) != 'b'
            && tolower(choice) != 'c' && tolower(choice) != 'e');
    
    return choice;
}
int isVowel(char * text){
    int vowels=0;
    for(int i=0;i<strlen(text);i++){
        cout << text[i] << " ";
    }
    for(int i=0;i<strlen(text);i++){
        if(tolower(text[i]) == 'a' || tolower(text[i]) == 'e' || 
                tolower(text[i]) == 'i' || tolower(text[i]) == 'o' ||
                tolower(text[i]) == 'u'){
            vowels++;
        }
    }
    return vowels;
}
int isCons(char * text){
    int cons=0;
    for(int i=0;i<strlen(text);i++){
        if(!(tolower(text[i]) == 'a' || tolower(text[i]) == 'e' || 
                tolower(text[i]) == 'i' || tolower(text[i]) == 'o' ||
                tolower(text[i]) =='u' || text[i] == ' ')){
            cons++;
        }
    }
    return cons;
}
void num119(){
    int choice;
    const int SIZE = 10;
    Speaker *person = new Speaker[SIZE];
    //Put in a function;
    do{
    do{
        cout << endl << endl;
        cout << "[1] Enter Speaker's Information" << endl;
        cout << "[2] Change Speaker's Information" << endl;
        cout << "[3] View All Speaker's Information" << endl;
        cout << "[4] Exit" << endl;
        cout << "Enter a choice:  ";
        cin >> choice;
        cin.clear();
        cin.ignore();
        if(!cin){
            cout << "Invalid, enter again: " << endl;
            cin.clear();
            cin.ignore();
            cin >> choice;
        }
    }while(choice != ENTER && choice!= CHANGE && choice != VIEW && choice != 4);
    
    if(choice == ENTER){
        person = addElem(person, SIZE);
    }
    if(choice == CHANGE){
        person = chngeEle(person);
    }
    if(choice == VIEW){
        prntEle(person, SIZE);
    }
    if(choice == 4){
        cout << "Press enter";
        break;
    }
    }while(choice != 4);
    
    delete [] person;
}
Speaker* addElem(Speaker *p, int SIZE){
    int n = 1;
    Speaker *ptr = new Speaker[SIZE];
    for(int i=0;i<SIZE;i++){
        cout << "Enter speaker " << n << "'s first name: ";
        cin >> ptr[i].name;
        cout << ptr[i].name<<endl;
        cout << "Enter speaker " << n << "'s telephone number: ";
        cin >> ptr[i].phoneNum;
        cout << "Enter speaker " << n << "'s speaking topic: ";
        cin >> ptr[i].topic;
        cout << "Enter speaker " << n << "'s fee required: ";
        cin >> ptr[i].fee;
        if(ptr[i].fee < 0){
            cout << "INVALID! No negative numbers!" << endl;
            cout << "Please enter again: ";
            cin >> ptr[i].fee;
        }
        n++; 
        cout << endl;
        cin.ignore();
        bool choice = playAgain();
        if(choice == false){
            break;
        }
    }
    
    return ptr;
}

Speaker* chngeEle(Speaker p[]){
    int choice;
    int strNum;  //Stores the number of the structure the user wants to change.
    cout << "Which structure would you like to access?[0-9] ";
    cin >> strNum;
    cout << "What element would you like to change?" << endl;
    do{
        cout << endl << endl;
        cout << "1) Name" << endl;
        cout << "2) Telephone Number" << endl;
        cout << "3) Speaking Topic" << endl;
        cout << "4) Fee Required" << endl;
        cout << "Enter a choice:  ";
        cin >> choice;
        cin.clear();
        cin.ignore();
        if(!cin){
            cout << "Invalid, enter again: " << endl;
            cin.clear();
            cin.ignore();
            cin >> choice;
        }
    }while(choice != NAME && choice!= PHONE && choice != TOPIC && choice != FEE); 
    
    Speaker *ptr = new Speaker[10];
    ptr = p;
    
    if(choice == NAME){
        cout << "New name: ";
        cin >> ptr[strNum].name;
    }
    else if(choice == PHONE){
        //Add of the customer.
        cout << "New telephone number: ";
        cin >> ptr[strNum].phoneNum;
    }
    else if(choice == TOPIC){
        cout << "New speaking topic: ";
        cin >> ptr[strNum].topic;
    }
    else{
        cout << "New fee required: ";
        cin >> ptr[strNum].fee;
        if(ptr[strNum].fee < 0){
            cout << "INVALID! No negative numbers!" << endl;
            cout << "Please enter again: ";
            cin >> ptr[strNum].fee;
        }
    }
    return ptr;
}

void prntEle(Speaker p[], int SIZE){
    for(int i=0;i<SIZE;i++){
        cout << "Speaker #"<< i+1 << endl;
        cout << "=========" << endl;
        cout << "Name: " << p[i].name << endl;
        cout << "Telephone Number: " << p[i].phoneNum << endl;
        cout << "Speaking Topic: " << p[i].topic << endl;
        cout << "Fee Required: " << p[i].fee << endl;
        cout << endl;
    }
}

void num111(){
    Movie m1;
    Movie m2;
    cout << "Enter movie title: ";
    cin >> m1.title;
    cout << "Enter movie director: ";
    cin >> m1.director;
    cout << "Enter the year released: ";
    cin >> m1.year;
    cout << "Enter the run-time of the movie (in minutes): ";
    cin >> m1.runTime;
    cout << "Enter the production cost of the movie: ";
    cin >> m1.prodCost;
    cout << "Enter the first year's revenue of the movie: ";
    cin >> m1.revenue;
    prtData(m1);
}
void prtData(Movie m){
    cout << "Movie's Title: " << m.title << endl;
    cout << "Movie's Director: " << m.director << endl;
    cout << "Movie's Year of Release: " << m.year << endl;
    cout << "Movie's Run Time (in minutes): " << m.runTime << endl;
    cout << "Movie's Profit/Loss: $" << m.revenue - m.prodCost << endl;   
}

void num127(){
    //Makes the user think they are actually opening a file.
    string file;
    cout << "Enter a file name with a '.txt' extention: ";
    cin >> file;
    
    char ch;
    fstream upper("uppercase.txt", ios::in);
    fstream lower("lowercase.txt", ios::out);
    
    if(upper){
        //Reads the contents into ch.
        upper.get(ch);
 
        while(upper){
            lower.put(tolower(ch));
            
            upper.get(ch);
        }
    }
    //Close files.
    upper.close();
    lower.close();
    
    cout << "Process complete" << endl;
}

void num128(){
    const int SIZE = 5;
    char array[SIZE] = {'1','2','3','4','5'};
    string fileName;
    char *ptr; 
    ptr = array;
    char array2[SIZE];
    char *ptr2;
    ptr2 = array;
    cout << "Enter a file name with a '.txt' extention" << endl;
    cin >> fileName;
    //Adding the contents of the array to the file.
    cout << "Beginning to add contents of the array to the file " << 
            fileName << "." << endl;
    arrayToFile(fileName, ptr, SIZE);
    cout << "Finished" << endl;
    cout << endl;
    cout << "Beginning to read back from the file " << fileName << "." << endl;
    fileToArray(fileName, ptr2, SIZE);
    cout << "Finished" << endl;
    
    cout << "The contents of the first array: " << endl;
    for(int i=0;i<SIZE;i++){
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "The contents of the second array: ";
    for(int i=0;i<SIZE;i++){ 
        cout << array2[i] << " ";
    }
}
void arrayToFile(string fileName, char *arr, int SIZE){
    fstream file;
    //Opens file in output and binary mode.
    file.open(fileName.c_str(), ios::out | ios::binary);
    //Writes the contents of the file into the array.
    file.write(arr, SIZE);
    //Closes file.
    file.close();
}

void fileToArray(string fileName, char *arr, int SIZE){
    char ch;
    fstream file;
    file.open(fileName.c_str(), ios::in | ios:: binary);
    file.get(ch);
    while(file){
        for(int i=0;i<SIZE;i++){
        arr[i] = ch;
        file.get(ch); 
        }
    }
    //Closes file.
    file.close();
}

int num1211(){
    int choice;
    const int SIZE = 4;
    Data div;
    fstream file("compData.txt", ios::out | ios::binary);
    
    for(int i=0;i<SIZE;i++){
        cout << "Enter the name of the division";
        cin >> div.divName[i];
        for(int j=0;j<SIZE;j++){
            cout << "Enter the sales for quarter " << j + 1 << ": $";
    do{  
        cin >> div.sales[i][j];
        if(div.sales[i][j] < 0){
            cout << "Invalid amount. Please enter again: ";
    }
            }while(div.sales[i][j] < 0);
        }
    }
    file.write(reinterpret_cast<char *>(&file), sizeof(file));
    file.close();
}
void num101(){
    fstream file;
    string input;
    string fileName;
    cout << "Enter the name of a file: (text.txt) " << endl;
    cin >> fileName;
    file.open(fileName.c_str(), ios::in);
    int counter = 0;
    while(file >> input){
        cout << input << endl;
        counter++;
        if(counter == 10){
            break;
        }
    }
    if(counter == 10){
            cout << "Unable to display full file";
        }
        else{
            cout << "The full file has been displayed for your viewing pleasure";
        }
    file.close();
}

bool playAgain(){
    cout << endl;
    cout << "Do you want to enter again? [y/n]:  ";
    char choice;
    cin.get(choice);
    if(choice=='y'){
        return true;
    }
    else{
        return false;
    }
}

bool select(){
    //Used in the main function to call the looping of the whole program.
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
