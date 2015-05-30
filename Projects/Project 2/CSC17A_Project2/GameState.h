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
        Card p1Hand[];
        Card p2Hand[];
        int size;
    public:
        GameState();
        ~GameState();
        bool getWon();
        int getTurn();
        void setTurn();
        void setWon();
        void setHand(Deck,int);
        Card getHand();
};


#endif	/* GAMESTATE_H */

