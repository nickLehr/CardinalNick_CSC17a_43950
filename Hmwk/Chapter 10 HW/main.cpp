/* 
 * File:   main.cpp
 * Author: Owner
 *
 * Created on March 29, 2015, 12:21 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

//Prototypes
bool select();
int menu();
void num103();
int nOfWrds(char *, int);
void num106();
int menu2(char *, int);
int isVowel(char *);
int isCons(char *);

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
    cin.getline(sentnce, SIZE, '\n');
    menu2(sntPrt, SIZE);
}

int menu2(char * text, int SIZE){
    char choice;
    do{
        cout << endl;
        cout << "A) Count the number of vowels in the string." << endl;
        cout << "B) Count the number of consonants in the string." << endl;
        cout << "C) Count both the vowels and consonants in the string." << endl;
        cout << "D) Enter another string." << endl;
        cout << "E) Exit the program." << endl;
        cout << "Enter a choice:  ";
        cin >> choice;
        if(!cin){
            cout << "Invalid, enter again: " << endl;
            cin.clear();
            cin.ignore();
            cin >> choice;
        }
        cout<<"=============================================="<<endl;
        
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
            
        }
        if(tolower(choice) == 'd'){
            num106();
        }
        if(tolower(choice) == 'e'){
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
    for(int i=0;i<strlen(*text);i++){
        if(tolower(*text[i]) != 'a' || tolower(*text[i]) != 'e' || 
                tolower(*text[i]) != 'i' || tolower(*text[i]) != 'o' ||
                tolower(*text[i]) != 'u'){
            cons++;
        }
    }
    return cons; 
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
