/* 
 * File:   Deck.cpp
 * Author: Owner
 *
 * Created on May 27, 2015, 10:51 AM
 */

#include <cstdlib>
#include <iostream>
#include "Deck.h"
#include "Card.h"
using namespace std;

enum Action { blank, DRAW2, DRAW4, WILD, SKIP, REVERSE };
enum Color { RED, GREEN, BLUE, YELLOW };

Deck::Deck(){
    size = 109;
    gameDeck = new Card[size];
    for(int i = 0;i<105;i++){
        gameDeck[i].setColor("NA");
        gameDeck[i].setIntAction(-3);
        gameDeck[i].setWild(false);
        gameDeck[i].setStrAction("N/A");
        gameDeck[i].setNum(-5);
    }
}
Deck::~Deck(){
    delete [] gameDeck;
}
void Deck::setUp(){
    createDeck("Red");
    createDeck("Green");
    createDeck("Yellow");
    createDeck("Blue");
    addWilds();
}

void Deck::outputDeck(){
    cout << "Default deck " << endl;
    for(int i=0;i<108;i++){
        if(gameDeck[i].getNum() < 0){
            cout << i <<  "Card Value: " << gameDeck[i].getStrAction();
        }
        else{
            cout << i <<"Card Value: " << gameDeck[i].getNum();
        }
        cout << " Color: " << gameDeck[i].getColor();
        cout << endl;
    }
}

void Deck::createDeck(string color){
    int cNum = 1;
    int end = 0;
    int i = 0;
    if(color == "Red"){
        i = 0; 
        end = 25;
    }
    if(color == "Green"){
        i = 25; 
        end = 50;
    }
    if(color == "Yellow"){
        i = 50;
        end = 75;
    }
    if(color == "Blue"){
        i = 75;
        end = 100;
    }
        for(i;i<end;i++){
            gameDeck[i].setColor(color);
            gameDeck[i].setNum(cNum);
            gameDeck[i].setWild(false);
            gameDeck[i].setIntAction(0);
            cNum++; //Increases from 1 - 9 then resets if cNum == 10;
            if(cNum == 10){
             cNum = 1;
            }
            if(i==end-7){
                gameDeck[i].setStrAction("Reverse");
                gameDeck[i].setIntAction(REVERSE);
                gameDeck[i].setColor(color);
                gameDeck[i+1].setStrAction("Reverse");
                gameDeck[i+1].setIntAction(REVERSE);
                gameDeck[i+1].setColor(color);
                
                gameDeck[i+2].setStrAction("Skip");
                gameDeck[i+2].setIntAction(SKIP);
                gameDeck[i+2].setColor(color);
                gameDeck[i+3].setStrAction("Skip");
                gameDeck[i+3].setIntAction(SKIP);
                gameDeck[i+3].setColor(color);
                
                gameDeck[i+4].setStrAction("Draw2");
                gameDeck[i+4].setIntAction(DRAW2);
                gameDeck[i+4].setColor(color);
                gameDeck[i+5].setStrAction("Draw2");
                gameDeck[i+5].setIntAction(DRAW2);
                gameDeck[i+5].setColor(color);
                
                gameDeck[i+6].setNum(0);
                gameDeck[i+6].setColor(color);
                break;
            }
        }
}

void Deck::addWilds(){
    for(int i = 100;i<105;i++){
        gameDeck[i].setWild(true);
        gameDeck[i].setColor("Wild");
        gameDeck[i].setStrAction("Wild");
        gameDeck[i].setIntAction(WILD);
    }
    for(int i=104;i<109;i++){
        gameDeck[i].setWild(true);
        gameDeck[i].setColor("Draw4");
        gameDeck[i].setStrAction("Draw4");
        gameDeck[i].setIntAction(DRAW4);
    }
}

Card Deck::draw(){
    Card* newDeck = new Card[size-1];
    for(int i = 1; i<size-1;i++){
       newDeck[i-1] = gameDeck[i];
    }
    Card ret = gameDeck[0];
    //Deletes the old deck.
    delete [] gameDeck;
    gameDeck = newDeck;
    cout << "Hello" << endl;
    Card yo;
    yo = ret;
    cout << "hello";
    return ret;
}