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
    size = 7;
    p1Hand[size];
    p2Hand[size];
    turns = 0;
    won = false;
}

GameState::~GameState(){
    //delete [] p1Hand;
    //delete [] p2Hand;
}
void GameState::setHand(Deck gameDeck, int p){
    //if(p == 1){
     //   for(int i = 0; i < 8; i++){
       //     cout << "P1" << endl;
            Card yo = gameDeck.draw();
            cout << "Hello";
            p1Hand[0] = yo;
        //}
    //}
    //else{
      //  for(int i = 0; i < 8; i++){
        //    p2Hand[i] = gameDeck.draw();
        //}
    //}
}

