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
    UNO.setHand(cardDeck,1);
    UNO.setHand(cardDeck,2);
    UNO.setDP(cardDeck.draw());
    UNO.outputDP();
    do{
    UNO.checkCard(UNO.getHand(1),1);
    }while(UNO.getWon() == false);
    return 0;
}

