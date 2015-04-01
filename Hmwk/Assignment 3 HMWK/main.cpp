/* 
 * File:   main.cpp
 * Author: Nicholas Cardinal
 *
 * Created on March 29, 2015, 12:21 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

enum Info { blank, NAME, PHONE, TOPIC, FEE };
enum speakerMenu { blnk, ENTER, CHANGE, VIEW };
//User libraries
//#include <speaker.h>
struct Speaker{
    string name;
    int phoneNum;
    string topic;
    unsigned int fee;
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
void prntEle(Speaker, int);
Speaker addElem(Speaker &, int);
Speaker chngeEle(Speaker &);

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
                num119;
                break;
            case 4:
                break;
            case 5:
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
        cout << "[3]" << endl;
        cout << "[4]" << endl;
        cout << "[5]" << endl;
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
            && choice != 5);
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
        }
        if(tolower(choice) == 'd'){
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
    Speaker person[SIZE];
    //Put in a function;
    do{
        cout << endl << endl;
        cout << "[1] Enter Speaker's Information" << endl;
        cout << "[2] Change Speaker's Information" << endl;
        cout << "[3] View All Speaker's Information" << endl;
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
    }while(choice != ENTER && choice!= CHANGE && choice != VIEW);
    
    if(choice == ENTER){
        addElem(person, SIZE);
    }
    if(choice == CHANGE){
        chngeEle(person);
    }
    if(choice == VIEW){
        prntEle(person);
    }
    
}
Speaker addElem(Speaker &p, int SIZE){
    int n = 1;
    for(int i=0;i<SIZE;i++){
        cout << "Enter speaker " << n << "'s name: ";
        cin >> p[i].name;
        cout << "Enter speaker " << n << "'s telephone number: ";
        cin >> p[i].phoneNum;
        cout << "Enter speaker " << n << "'s speaking topic: ";
        cin >> p[i].topic;
        cout << "Enter speaker " << n << "'s fee required: ";
        cin >> p[i].fee;
        n++;
    }
    return p;
}

Speaker chngeEle(Speaker &p){
    char choice;
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
    
    if(choice == NAME){
        cout << "New name: ";
        //Figure out how to sort through different structure instances???
        cin >> p[strNum].name;
    }
    else if(choice == PHONE){
        //Add of the customer.
        cout << "New telephone number: ";
        cin >> p[strNum].phoneNum;
    }
    else if(choice == TOPIC){
        cout << "New speaking topic: ";
        cin >> p[strNum].topic[strNum];
    }
    else{
        cout << "New fee required: ";
        cin >> p[strNum].fee[strNum];
    }
    return p;
}














void prntEle(Speaker p, int SIZE){
    int speekr = 1;
    for(int i=0;i<SIZE;i++){
        cout << "Speaker #"<<speekr << endl;
        cout << "=========" << endl;
    }
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
