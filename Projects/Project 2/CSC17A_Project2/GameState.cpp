/* 
 * File:   GameState.cpp
 * Author: Owner
 *
 * Created on May 27, 2015, 1:06 PM
 */

#include <cstdlib>
#include <iostream>
#include "GameState.h"
#include "Deck.h"
#include "Card.h"
#include "Stats.h"
#include "Player.h"
using namespace std;
enum Action { blank, DRAW2, DRAW4, WILD, SKIP, REVERSE };

GameState::GameState(){
    p1Size = 7;
    p2Size = 7;
    p1Hand = new Card[p1Size];
    p2Hand = new Card[p2Size];
    p = 1;
    won = false;
    skipped = false;
}

GameState::~GameState(){
    delete [] p1Hand;
    delete [] p2Hand;
}
void GameState::setHand(Deck& gameDeck){
        for(int i = 0; i < 7; i++){
            p1Hand[i] = gameDeck.draw();
        }
        for(int i = 0; i < 7; i++){
            p2Hand[i] = gameDeck.draw();
        }
//        p2Hand[0].setColor("Red");
//        p2Hand[0].setNum(-5);
//        p2Hand[0].setIntAction(SKIP);
//        p2Hand[0].setStrAction("Skip");
//        p2Hand[0].setWild(false);
        
}

Card* GameState::getHand(int p){
    if(p==1)
    return p1Hand;
    if(p==2)
    return p2Hand; 
}

Card GameState::getDP(){
    return dpPile[0];
}

void GameState::setDP(Card c){
    dpPile[0].setColor(c.getColor());
    dpPile[0].setNum(c.getNum());
    dpPile[0].setIntAction(c.getIntAction());
    dpPile[0].setStrAction(c.getStrAction());
    dpPile[0].setWild(c.getWild());
}

void GameState::outputDP(){
       if(dpPile[0].getNum() < 0){
            cout << "DP: " << dpPile[0].getColor() << " " << dpPile[0].getStrAction() << "!" << endl;
        }
        else{
            cout << "DP: " << dpPile[0].getColor() << " " << dpPile[0].getNum() << "!" << endl;
        }
}

int GameState::cardChoice(Card* c, int p){
    int choice = 0;
    int size = 0;
    Card* phTemp;
    //If it's player one's turn.
    if(GameState::p % 2 == 1){
        size = p1Size;
        phTemp = p1Hand;
        cout << "Player 1, it's your turn!" << endl;
    }
    if(GameState::p % 2 == 0){
        size = p2Size;
        phTemp = p2Hand;
        cout << "Player 2, it's your turn!" << endl;
    }
    cout << "Which card would you like to place?" << endl;
    cout << "Enter " << size+1 << " to draw a card." << endl; 
    for(int i=0;i<size;i++){
         if(phTemp[i].getNum() < 0){
            cout << i+1 << ") " << phTemp[i].getColor() << " " << phTemp[i].getStrAction() << endl;
        }
        else{
            cout << i+1 << ") " << phTemp[i].getColor() << " " << phTemp[i].getNum() << endl;
        }
    }
    do{
        while(!(cin >> choice)){
            cout << "Please choose a valid card!" << endl;
            cin.clear();
            cin.ignore();
        }
    }while(choice > size+1);
    if(choice == size+1){
        return 109;
    }
    if(choice < 1){
        return -1;
    }
    else{
        return choice;
    }
}

bool GameState::getWon(){
    return won;
}

bool GameState::checkCard(Card* c, int p, Deck& d){
    setSkip(false);
    int choice = cardChoice(c,GameState::p);
    if(choice < 0){
        choice = cardChoice(c,GameState::p);
    }
    bool draw = false;
    if(choice == 109){
        draw = addNewCard(GameState::p,d,false);
        return draw;
    }
    Card* phTemp;
    int tempSize = 0;
    if(GameState::p % 2 == 1){
        phTemp = p1Hand; //Temp stores the player 1's hand.
        tempSize = p1Size;   //Temp stores the player 2's hand size.
    }
    if(GameState::p % 2 == 0){
        phTemp = p2Hand; //Temp stores the player 2's hand.
        tempSize=p2Size;     //Temp stores the player 2's hand size.
    }
    bool isSkip = false; //Is true if the card placed is an skip or a reverse.
    if(phTemp[choice-1].getColor() == dpPile[0].getColor() || phTemp[choice-1].getNum() == dpPile[0].getNum()
            || phTemp[choice-1].getWild() == true){
        
        setDP(phTemp[choice-1]);
        isSkip = checkAction(d,0);
        removeCard(c,tempSize,choice,GameState::p,isSkip); 
        return true;
    }
    else{
        cout << "Please choose a card of the same number, color or a wild" << endl;
        return false;
    }
}

void GameState::removeCard(Card *c, int &size, int choice, int p, bool a){
    Card* phTemp;
    if(GameState::p % 2 == 1){
        phTemp = p1Hand; //Temp stores the player 1's hand.
    }
    if(GameState::p % 2 == 0){
        phTemp = p2Hand; //Temp stores the player 2's hand
    }
    swap(phTemp[choice-1], phTemp[size-1]);
    if(GameState::p % 2 == 1){
        p1Size--;
        p1Hand = phTemp;
    }
    if(GameState::p % 2 == 0){
        p2Size--;
        p2Hand = phTemp;
    }
    if(GameState::p%2 == 0){
        cout << "Player " << GameState::p%2+2 << " your turn is over."  << endl << endl << endl;
    }
    else{
    cout << "Player " << GameState::p%2 << " your turn is over."  << endl << endl << endl;
    }
    if(a == true){
        GameState::p++;
    }
    GameState:: p++;
    checkWin();
}


 int GameState::getSize(Card* ph){
     int size = 0;
     if(ph == p1Hand){
         size = p1Size;
     }
     if(ph == p2Hand){
         size = p2Size;
     }
     return size;
 }
 
 bool GameState::addNewCard(int p, Deck& d, bool draw){
     if(GameState::p % 2 == 1){
    Card* newHand = new Card[p1Size+1];
    for(int i = 0; i < p1Size; i++){
        newHand[i] = p1Hand[i];
    }
    newHand[p1Size] = d.draw();
    p1Size++;
    delete [] p1Hand;
    p1Hand = newHand;
    if(draw == false){
    cout << "Player " << GameState::p%2+1 << " your turn is over."  << endl << endl << endl;
    GameState::p++;
    }
    }
     else if(GameState::p % 2 == 0){
    Card* newHand = new Card[p2Size+1];
        for(int i = 0; i < p2Size; i++){
            newHand[i] = p2Hand[i];
        }
    newHand[p2Size] = d.draw();
    p2Size++;
    delete [] p2Hand;
    p2Hand = newHand;
    if(draw == false){
    cout << "Player " << GameState::p%2+1 << " your turn is over."  << endl << endl << endl;
    GameState::p++;
    }
    }
     return true;
 }
 
 bool GameState::checkAction(Deck& d,int ai){
    if(ai==0){
    checkWild();
    }
    else{
        checkAIWild();
    }
    bool isSkip = checkSkip();
    if(isSkip == true){
        return true;
    }
    if(ai==0){
    checkDrawAct(d);
    }
    else{
        checkDrawAI(d);
    }
    return false;
}
 void GameState::checkWin(){
    if(p1Size == 0){
        won = true;
        cout << "Player 1 wins!" << endl;
    }
    if(p2Size == 0){
        won = true;
        cout << "Player 2 wins!" << endl;
    }
 }
 void GameState::checkWild(){
 if(dpPile[0].getWild() == true){
        int pColor;
        string pColors;
        cout << "You placed a wild! Choose a color!" << endl;
        cout << "1) Red " << endl << "2) Blue " << endl << "3) Green " << endl 
                << "4) Yellow" << endl;
        cin >> pColor;
        while(pColor < 0 && pColor > 4){
            cout << "Please choose a valid number." << endl;
            cin >> pColor;
        }
        if(pColor==1){pColors = "Red";}
        else if(pColor==2){pColors = "Blue";}
        else if(pColor==3){pColors = "Green";}
        else{pColors == "Yellow";}
        dpPile[0].setColor(pColors);
    }
}
 
 bool GameState::checkSkip(){
     if(dpPile[0].getIntAction()== SKIP || dpPile[0].getIntAction() == REVERSE){
        if(GameState::p % 2 == 0){
            cout << "Player " << (p%2)+1  << " turn has been skipped!" << endl;
        }
        else{
            cout << "Player "<< (p%2)+1 << " turn has been skipped!" << endl;
        }
        setSkip(true);
        return true;
    }
     return false;
}
 
 void GameState::checkDrawAct(Deck& d){
    bool draw = false;
    if(dpPile[0].getIntAction() == DRAW2){
        for(int i = 0; i<2;i++){
            draw = true;
            p++;
            addNewCard(GameState::p,d,draw);
            p--;
        }
    }
    if(dpPile[0].getIntAction() == DRAW4){
        for(int i = 0; i<4;i++){
            draw = true;
            addNewCard(GameState::p+1,d,draw);
        }
    }
    draw = false;
}

 int GameState::getTurn(){
     return p;
 }
 
 void GameState::setTurn(int t){
     p = t;
 }
 void GameState::setUp(int numOfPlayers){
     Player p;
     Stats stats;
     char name[20]; 
     cout << "Welcome to UNO!" << endl;
     cout << "Enter your first name: " << endl;
     stats.outfile(p,20);
     stats.infile(p);
     cout << "Welcome "; p.getName(); cout << "!" << endl;
 }
 
 void GameState::setSkip(bool s){
     skipped = s;
 }
 
 bool GameState::getSkip(){
     return skipped;
 }
 
 void GameState::AI(Deck& d){
     setSkip(false);
     int choice;
     bool draw = false;
     bool isSkip = false;
     bool placed = false;
     int tempSize = p2Size;
     choice = checkAI();
     if(choice < 0){
         AIDraw(d);
         draw = true;
     }
     if(choice >= 0){
        setDP(p2Hand[choice]);
        cout << "Your opponent placed "; outputDP(); cout<<endl;
        isSkip = checkAction(d,1);
        AIRemove(choice);
     }
}
 
 int GameState::checkAI(){
     int choice = 0;
     bool found = false;
     //outputDP();
     for(int i = 0; i < p2Size;i++){
     if(p2Hand[i].getColor() == dpPile[0].getColor() || p2Hand[i].getNum() == dpPile[0].getNum()
             || p2Hand[i].getWild() == true){
         choice = i;
         found = true;
         if(found == true){
             break;
         }
        }
     }
     if(found == false){
         cout << "Your opponent drew a card!" << endl;
         return -1;
     }
     
//     cout << "AI HAND:" << endl << endl;
//     for(int i=0;i<p2Size;i++){
//         if(p2Hand[i].getNum() < 0){
//            cout << i+1 << ") " << p2Hand[i].getColor() << " " << p2Hand[i].getStrAction() << endl;
//        }
//        else{
//            cout << i+1 << ") " << p2Hand[i].getColor() << " " << p2Hand[i].getNum() << endl;
//        }
//    }
//     cout << "CHOICE OF AI : " << choice << "!" << endl << endl << endl;
     return choice;
 }
 
 void GameState::AIDraw(Deck& d){
    Card* newHand = new Card[p2Size+1];
        for(int i = 0; i < p2Size; i++){
            newHand[i] = p2Hand[i];
        }
    newHand[p2Size] = d.draw();
    p2Size++;
    delete [] p2Hand;
    p2Hand = newHand;
 }
 
 void GameState::AIRemove(int choice){
     swap(p2Hand[choice], p2Hand[p2Size-1]);
     p2Size--;
 }
 
 void GameState::checkAIWild(){
     int red = 0;
     int blue = 0;
     int yellow = 0;
     int green = 0;
     if(dpPile[0].getWild() == true){
     for(int i=0;i<p2Size;i++){
         if(p2Hand[i].getColor() == "Red"){
             red++;
         }
         else if(p2Hand[i].getColor() == "Blue"){
             blue++;
         }
         else if(p2Hand[i].getColor() == "Yellow"){
             yellow++;
         }
         else if(p2Hand[i].getColor() == "Green"){
             green++;
         }
     }
     if(red>blue&&red>yellow&&red>green){
         dpPile[0].setColor("Red");
     }
     else if(blue>red&&blue>yellow&&blue>green){
         dpPile[0].setColor("Blue");
     }
     else if(yellow>red&&yellow>blue&&yellow>green){
         dpPile[0].setColor("Yellow");
     }
     else{
         dpPile[0].setColor("Green");
     }
     }
 }
 
 void GameState::checkDrawAI(Deck& d){
     bool draw = false;
     if(dpPile[0].getIntAction() == DRAW2){
         for(int i = 0; i < 2; i++){
        Card* newHand = new Card[p1Size+1];
        for(int i = 0; i < p1Size; i++){
            newHand[i] = p1Hand[i];
        }
        newHand[p1Size] = d.draw();
        p1Size++;
        delete [] p1Hand;
        p1Hand = newHand;
        }
     }
     if(dpPile[0].getIntAction() == DRAW4){
         for(int i = 0; i < 4; i++){
        Card* newHand = new Card[p1Size+1];
        for(int i = 0; i < p1Size; i++){
            newHand[i] = p1Hand[i];
        }
        newHand[p1Size] = d.draw();
        p1Size++;
        delete [] p1Hand;
        p1Hand = newHand;
        }
     }
 }