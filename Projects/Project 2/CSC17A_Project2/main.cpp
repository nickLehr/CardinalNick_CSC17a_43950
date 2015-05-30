/* 
 * File:   main.cpp
 * Author: Owner
 *
 * Created on May 27, 2015, 10:30 AM
 */

#include <cstdlib>
#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "GameState.h"
using namespace std;


int main(int argc, char** argv) {
    GameState UNO;
    Deck cardDeck;
    cardDeck.setUp();
    cardDeck.outputDeck();
    UNO.setHand(cardDeck,1);
    //UNO.setHand(cardDeck,2);
    cardDeck.outputDeck();
    
    return 0;
}

