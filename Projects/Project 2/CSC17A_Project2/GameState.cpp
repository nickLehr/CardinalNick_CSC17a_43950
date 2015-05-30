/* 
 * File:   GameState.cpp
 * Author: Owner
 *
 * Created on May 27, 2015, 1:06 PM
 */

#include <cstdlib>
#include <iostream>
#include "GameState.h"
#include "Deck.h"
#include "Card.h"
using namespace std;

GameState::GameState(){
    p1Size = 7;
    p2Size = 7;
    p1Hand = new Card[p1Size];
    p2Hand = new Card[p2Size];
    turns = 0;
    won = false;
}

GameState::~GameState(){
    delete [] p1Hand;
    delete [] p2Hand;
}
void GameState::setHand(Deck& gameDeck, int p){
    try{
    if(p == 1){
        for(int i = 0; i < 7; i++){
            p1Hand[i] = gameDeck.draw();
        }
    }
    else{
        for(int i = 0; i < 7; i++){
            p2Hand[i] = gameDeck.draw();
        }
    }
    }
    catch(string ex){cout << ex;}
}

Card* GameState::getHand(int p){
    if(p==1)
    return p1Hand;
    if(p==2)
    return p2Hand; 
}

Card GameState::getDP(){
    return dpPile[0];
}

void GameState::setDP(Card c){
    dpPile[0].setColor(c.getColor());
    dpPile[0].setNum(c.getNum());
    dpPile[0].setIntAction(c.getIntAction());
    dpPile[0].setStrAction(c.getStrAction());
    dpPile[0].setWild(c.getWild());
}

void GameState::outputDP(){
       if(dpPile[0].getNum() < 0){
            cout << "DP: " << dpPile[0].getColor() << " " << dpPile[0].getStrAction() << endl;
        }
        else{
            cout << "DP: " << dpPile[0].getColor() << " " << dpPile[0].getNum() << endl;
        }
}

int GameState::cardChoice(Card* c, int p){
    int choice = 0;
    cout << "Which card would you like to place?" << endl;
    for(int i=0;i<p1Size;i++){
         if(p1Hand[i].getNum() < 0){
            cout << i+1 << ") " << p1Hand[i].getColor() << " " << p1Hand[i].getStrAction() << endl;
        }
        else{
            cout << i+1 << ") " << p1Hand[i].getColor() << " " << p1Hand[i].getNum() << endl;
        }
    }
    cin >> choice; //FIX SO IT DOESN'T ACCEPT CHARS
    
    if(choice < 1 || choice > p1Size){
        return -1;
    }
    setDP(p1Hand[choice-1]);
    return choice;
}

bool GameState::getWon(){
    return won;
}

bool GameState::checkCard(Card* c, int p){
    int choice = cardChoice(c,p);
    if(p==1){
        if(p1Hand[choice-1].getColor() == dpPile[0].getColor() || p1Hand[choice-1].getNum() == dpPile[0].getNum()
                || p1Hand[choice-1].getWild() == true){
            return true;
        }
        else{
            cout << "Please choose a card of the same number, color or a wild" << endl;
            return false;
        }
    }
}

void GameState::removeCard(Card *c, int &size, int choice, int p){
    swap(p1Hand[choice-1], p1Hand[p1Size-1]);
    p1Size--;
    cout << "Your turn is over!" << endl << endl << endl << endl;
}

//bool GameState::operator==(const Card* c){
//    return(c->getColor() == 
//            c->getNum() == b.)
//}

//bool operator!=(const Card*c, const Card& c2){
//    return !(c == c2);
//}