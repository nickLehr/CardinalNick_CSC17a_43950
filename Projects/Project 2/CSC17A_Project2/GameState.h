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
#include "Player.h"

class GameState{
    private:
        int p;
        bool won;
        Card *p1Hand;
        Card *p2Hand;
        Card dpPile[1];
        int p1Size;
        int p2Size;
        bool skipped;
    public:
        //Constructor
        GameState();
        //Destructor
        virtual ~GameState();
        //Mutators/Accessors
        bool getWon();
        int getTurn();
        void setTurn(int);
        void setWon();
        void setHand(Deck&);
        Card* getHand(int);
        Card getDP();
        void setDP(Card);
        int getSize(Card*);
        //Game functionality.
        void outputDP();
        int cardChoice();
        bool checkCard(Card*,int,Deck&);
        void removeCard(Card*,int&,int,int,bool);
        bool addNewCard(int,Deck&,bool);
        bool checkAction(Deck&,int);
        void checkWin();
        void checkWild();
        bool checkSkip();
        void checkDrawAct(Deck&);
        //AI Functions
        void AI(Deck&);
        int checkAI();
        void AIDraw(Deck&);
        void AIRemove(int);
        void checkAIWild();
        void checkDrawAI(Deck&);
        void setSkip(bool);
        bool getSkip();
        //Exception function for the try catch.
        void exception(int);
        //
        bool operator==(const Card*);
        bool operator!=(const Card*);
        //File IO / Try-Catch function.
        void nameSet();
        //Menu
        int menu();
};

#endif	/* GAMESTATE_H */