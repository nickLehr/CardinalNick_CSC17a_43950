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
    UNO.setUp(1);
    int game = 0;
    cout << "Enter 1 or 2" << endl;
    cin >> game;
    bool accepted = false; //Controls whether the card the user placed is accepted.
    do{
    if(game == 1){
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
    UNO.outputDP();
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