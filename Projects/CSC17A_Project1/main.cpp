/* 
 * File:   main.cpp
 * Author: Nicholas Cardinal
 *
 * Created on April 22, 2015, 10:35 AM
 */

//Libs
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
using namespace std;
//User Libraries
#include "Card.h"
//Functions
void changeActionCard(int &, int &, string &); //Adds the action cards to un-shuffled deck.
Card shuffleDeck(Card *, int); //Shuffles deck and returns the pointer to the deck.
Card resetDeck(Card *, int);//Sets deck back to default.
void outputDeck(Card *, int);//Outputs deck.
Card fillHand(Card *, Card *, int);//Fills players hands with random cards from the deck.

int main(int argc, char** argv) {
    srand(time(0));
    int size = 108;
    int handSize = 7;
    int *dckSize = new int [size];
    int *hndSize = new int [handSize];
    Card *deckPtr;
    Card deck[size];
    deckPtr = deck;
    resetDeck(deck, size);
    outputDeck(deck, size);
    shuffleDeck(deck, size);
    Card p1Hand[handSize];
    Card p2Hand[handSize];
    Card *handOne;
    Card *handTwo;
    handOne = p1Hand;
    handTwo = p2Hand;
    fillHand(handOne, deck, size);
    fillHand(handTwo, deck, size);
    
    for(int i=0;i<handSize;i++){
        if(p1Hand[i].number < 0){
            cout << i+1 << ")!: " << p1Hand[i].action;
        }
        else{
            cout << i+1 << ")#:" << p1Hand[i].number;
        }
        cout << " C: " << p1Hand[i].color;
        cout << endl;
    }
    
    delete [] dckSize;
    delete [] hndSize;
    return 0;
}
void changeActionCard(int &aCrdTyp, int &cNum, string &aCard){
    aCrdTyp++;
    if(aCrdTyp >= 0 && aCrdTyp <= 2){//Set action card to reverse
        cNum = -1;
        aCard = "Reverse";
    }
    else if(aCrdTyp > 2 && aCrdTyp <= 4){//Set action card to Draw2
        aCard = "Draw2";
        cNum = -1;
    }
     else{//Set action card to Skip
        aCard = "Skip";
        cNum = -1;
    }
}
Card shuffleDeck(Card *deck, int size){
    int shuffle = 0;
    for(int i=0;i<size;i++){
        shuffle = rand() % 108 + 0;
        swap(deck[i],deck[shuffle]);
    }
    for(int i=0;i<108;i++){
        if(deck[i].number < 0){
            cout << i <<  "Card Value: " << deck[i].action;
        }
        else{
            cout << i <<"Card Value: " << deck[i].number;
        }
        cout << " Color: " << deck[i].color;
        cout << endl;
    }
    cout << "Shuffled deck" << endl;
    for(int i=0;i<108;i++){
        if(deck[i].number < 0){
            cout << i <<  "Card Value: " << deck[i].action;
        }
        else{
            cout << i <<"Card Value: " << deck[i].number;
        }
        cout << " Color: " << deck[i].color;
        cout << endl;
    }
    return *deck;
}

Card resetDeck(Card *deck, int size){
    int cNum = 1; //Holds a value 1-9 that is to be stored in .number
    string cColor;//Holds the string color(red,green,blue,yellow) & stores in .color
    string aCard;//Holds the string action card(reverse,draw2,skip) & stores in .action
    int aCrdTyp = 0;//After storing 2 action cards the action card is changed.
    for(int i=0;i<size;i++){//Loops in order to change the color of the card stored in .color
        if(i < 24){//If parameters met set card color to Blue
            cColor = "Blue";
            if(i >= 18){//If i is > 18 the color begin placing action cards.
                changeActionCard(aCrdTyp, cNum, aCard);
            }
        }
        else if(i > 24 && i < 48){//If parameters met set card color to Green
            if(aCrdTyp > 6){
                aCrdTyp = 0;
            }
            cColor = "Green";
            if(i >= 42){//If i is > 42 the color begin placing action cards.
                changeActionCard(aCrdTyp, cNum, aCard);
            }
        }
        else if(i > 48 && i < 72){//If parameters met set card color to Red
            if(aCrdTyp > 6){
                aCrdTyp = 0;
            }        
            cColor = "Red";
            if(i >= 66){//If i is > 66 the color begin placing action cards.
                changeActionCard(aCrdTyp, cNum, aCard);
            }
        }
        else if(i > 72 && i < 96){//If parameters met set card color to Yellow
            if(aCrdTyp > 6){
                aCrdTyp = 0;
            }
            cColor = "Yellow";
            if(i >= 90){//If i is > 90 the color begin placing action cards.
                changeActionCard(aCrdTyp, cNum, aCard);
            }
        }
        deck[i].number = cNum;
        deck[i].color = cColor;
        deck[i].action = aCard;
        cNum++; //Increases from 1 - 9 then resets if cNum = 10;
        int count = 0;//Stores the number of times the cNum variable has been reset.
        if(cNum == 10){
             cNum = 1;
             count++;
        }
    }
    deck[90].action = "Draw2";
    deck[97].number = 9;
    deck[97].color = "Green";
    deck[98].number = 9;
    deck[98].color = "Red";
    deck[99].number = 9;
    deck[99].color = "Yellow";
    for(int i=100;i<105;i++){
        deck[i].action = "Wild";
        deck[i].number = -1;
        deck[i].wild = true;
        deck[i].color = "Wild";
    }
    for(int i=104;i<108;i++){
        deck[i].action = "Draw4";
        deck[i].number = -2;
        deck[i].wild = true;
        deck[i].color = "Draw4";
    }
    return *deck;
}

void outputDeck(Card *deck, int size){
    cout << "Default deck " << endl;
    for(int i=0;i<size;i++){
        if(deck[i].number < 0){
            cout << i <<  "Card Value: " << deck[i].action;
        }
        else{
            cout << i <<"Card Value: " << deck[i].number;
        }
        cout << " Color: " << deck[i].color;
        cout << endl;
    }
}

Card fillHand(Card *hand, Card *deck, int size){
    int randCrd;
    for(int i=0;i<7;i++){
        randCrd = rand() % 108+0;
        hand[i].action = deck[randCrd].action;
        hand[i].color = deck[randCrd].color;
        hand[i].number = deck[randCrd].number;
        hand[i].wild = deck[randCrd].wild;
        swap(deck[randCrd],deck[size-1]);
        cout << "randCrd: ";
        cout << randCrd;
        size--;
    }
    return *hand;
}