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
using namespace std;

int main(int argc, char** argv) {
    srand(time(0));
    GameState UNO;
    Deck cardDeck;
    cardDeck.setUp();
    cardDeck.shuffleDeck();
    //cardDeck.outputDeck();
    UNO.setHand(cardDeck);
    UNO.setHand(cardDeck);
    UNO.setDP(cardDeck.draw());
    UNO.outputDP();
    bool accepted = false; //Controls whether the card the user placed is accepted.
    do{
        do{
            accepted = UNO.checkCard(UNO.getHand(1),1,cardDeck);
        }while(accepted == false);
    UNO.outputDP();
    accepted = false;
        do{
            accepted = UNO.checkCard(UNO.getHand(2),2,cardDeck);
        }while(accepted == false);
    UNO.outputDP();
    accepted = false;
    }while(UNO.getWon() == false);
    return 0;
}