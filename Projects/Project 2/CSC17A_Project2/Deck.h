/* 
 * File:   Deck.h
 * Author: Owner
 *
 * Created on May 27, 2015, 10:35 AM
 */

#ifndef DECK_H
#define	DECK_H
#include "Card.h"
#include <string>
class Deck{
    private:
        Card *gameDeck;
        void createDeck(std::string);
        void addWilds();
        int size;
    public:
        Deck();
        virtual ~Deck();
        void setUp();
        void setUpHand();
        void shuffleDeck();
        void outputDeck();
        virtual Card draw();
};
#endif	/* DECK_H */

