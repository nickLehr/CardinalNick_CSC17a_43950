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
    int choice = 0;
    cardDeck.setUp();
    cardDeck.shuffleDeck();
    UNO.setHand(cardDeck);
    UNO.setHand(cardDeck);
    UNO.setDP(cardDeck.draw());
    //UNO.nameSet();
    choice = UNO.menu();
    bool accepted = false; //Controls whether the card the user placed is accepted.
    do{
    if(choice == 1){
    UNO.outputDP();
        do{
            accepted = UNO.checkCard(UNO.getHand(1),1,cardDeck);
        }while(accepted == false);
    UNO.outputDP();
    accepted = false;
    if(UNO.getWon() == false){
        do{
            accepted = UNO.checkCard(UNO.getHand(2),2,cardDeck);
        }while(accepted == false);
    }
    accepted = false;
    }
    else{
        UNO.setTurn(1);
        UNO.outputDP();
        do{
            if(UNO.getSkip() == false){
            accepted = UNO.checkCard(UNO.getHand(1),1,cardDeck);
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