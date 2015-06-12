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
        int turn;
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
        int cardChoice(Player,Player);
        bool checkCard(Deck&,Player,Player);
        void removeCard(int&,int,bool,Player, Player);
        bool addNewCard(Deck&,bool,Player,Player);
        bool checkAction(Deck&,int,Player,Player);
        void checkWin(Player,Player);
        void checkWild();
        bool checkSkip(Player,Player);
        void checkDrawAct(Deck&,Player,Player);
        //AI Functions
        void AI(Deck&);
        int checkAI();
        void AIDraw(Deck&);
        void AIRemove(int);
        void checkAIWild();
        void checkDrawAI(Deck&);
        void setSkip(bool);
        bool getSkip();
        //
        bool operator==(const Card*);
        bool operator!=(const Card*);
        //File IO / Try-Catch function.
        void setUp(Player&, Player&);
        void nameSet();
        void storeStats(Player);
        //Display stats.
        void statsOut(Player);
        //Asks user if they want to check stats.
        void checkStats(Player);
        //Menu
        int menu();
};

#endif	/* GAMESTATE_H */