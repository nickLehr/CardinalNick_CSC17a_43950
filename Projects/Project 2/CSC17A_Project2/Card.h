/* 
 * File:   Card.h
 * Author: Owner
 *
 * Created on May 27, 2015, 10:35 AM
 */

#ifndef CARD_H
#define	CARD_H
#include <string>
class Card{
    private:
        std::string color;
        int number;
        int action;
        bool wild;
        std::string strAction;   
    public:
        Card();
        std::string getColor(){return color;}
        std::string getStrAction(){return strAction;}
        int getIntAction(){return action;}
        int getNum(){return number;}
        bool getWild(){return wild;}
        void setColor(std::string c) {color = c;}
        void setStrAction(std::string sA){strAction = sA;}
        void setIntAction(int iA){action = iA;}
        void setNum(int n){number = n;}
        void setWild(bool w){wild = w;}
};

#endif	/* CARD_H */

