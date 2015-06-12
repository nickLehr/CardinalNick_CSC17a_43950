/* 
 * File:   main.cpp
 * Author: Owner
 *
 * Created on May 27, 2015, 10:30 AM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Deck.h"
#include "Card.h"
#include "GameState.h"
#include "Player.h"
using namespace std;

int main(int argc, char** argv) {
    srand(time(0));
    GameState UNO;
    Deck cardDeck;
    Player p;
    Player p2;
    int choice = 0;
    cardDeck.setUp();
    cardDeck.shuffleDeck();
    UNO.setHand(cardDeck);
    UNO.setHand(cardDeck);
    UNO.setDP(cardDeck.draw());
    choice = UNO.menu();
    bool prompt = true;
    bool accepted = false; //Controls whether the card the user placed is accepted.
    do{
    if(choice == 1){ // Player vs. Player
        if(prompt){
            UNO.setUp(p,p2);
            prompt = false;
        }
    UNO.outputDP();
        do{
            accepted = UNO.checkCard(cardDeck,p,p2);
        }while(accepted == false);
    accepted = false;
    UNO.outputDP();
    if(UNO.getWon() == false){
        do{
            accepted = UNO.checkCard(cardDeck,p,p2);
        }while(accepted == false);
    }
    accepted = false;
    }
    else{   //Player vs. AI
        UNO.setTurn(1);
        UNO.outputDP();
        do{
            if(UNO.getSkip() == false){
            accepted = UNO.checkCard(cardDeck,p,p2);
            UNO.setTurn(1);
            }
            else{
                UNO.setSkip(false);
            }
        }while(accepted == false);
        if(UNO.getSkip() == false){
        UNO.AI(cardDeck);
        }
        else{
            UNO.setSkip(false);
        }
    }
    }while(UNO.getWon() == false);
    return 0;
}