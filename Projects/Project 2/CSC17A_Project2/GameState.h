/* 
 * File:   GameState.h
 * Author: Owner
 *
 * Created on May 27, 2015, 1:06 PM
 */

#ifndef GAMESTATE_H
#define	GAMESTATE_H
#include "Card.h"
#include "Deck.h"
class GameState{
    private:
        int turns;
        bool won;
        Card *p1Hand;
        Card *p2Hand;
        Card dpPile[1];
        int p2Size;
        int p1Size;
    public:
        GameState();
        ~GameState();
        bool getWon();
        int getTurn();
        void setTurn();
        void setWon();
        void setHand(Deck&,int);
        Card* getHand(int);
        Card getDP();
        void setDP(Card);
        void outputDP();
        int cardChoice(Card*, int);
        bool checkCard(Card*,int);
        void removeCard(Card*,int&,int,int);
        bool operator==(const Card*);
        bool operator!=(const Card*);
};

#endif	/* GAMESTATE_H */

