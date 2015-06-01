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
using namespace std;
enum Action { blank, DRAW2, DRAW4, WILD, SKIP, REVERSE };

GameState::GameState(){
    p1Size = 7;
    p2Size = 7;
    p1Hand = new Card[p1Size];
    p2Hand = new Card[p2Size];
    p = 1;
    won = false;
}

GameState::~GameState(){
    delete [] p1Hand;
    delete [] p2Hand;
}
void GameState::setHand(Deck& gameDeck){
//    try{
//    if(p % 2 == 1){
        for(int i = 0; i < 7; i++){
            p1Hand[i] = gameDeck.draw();
        }
//    }
//    else{
        for(int i = 0; i < 7; i++){
            p2Hand[i] = gameDeck.draw();
        }
//    }
//    }
//    catch(string ex){cout << ex;}
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
            cout << "DP: " << dpPile[0].getColor() << " " << dpPile[0].getStrAction() << endl;
        }
        else{
            cout << "DP: " << dpPile[0].getColor() << " " << dpPile[0].getNum() << endl;
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
    cin >> choice; //FIX SO IT DOESN'T ACCEPT CHARS
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
    int choice = cardChoice(c,GameState::p);
    if(choice < 0){
        choice = cardChoice(c,GameState::p);
    }
    bool draw = false;
    if(choice == 109){
        draw = addNewCard(GameState::p,d);
        return draw;
    }
    Card* phTemp;
    int tempSize = 0;
    if(GameState::p % 2 == 1){
        phTemp = p1Hand; //Temp stores the player 1's hand.
        tempSize = p1Size;   //Temp stores the player 2's hand size.
    }
    if(GameState::p % 2 == 0){
        phTemp = p2Hand; //Temp stores the player 2's hand
        tempSize=p2Size;     //Temp stores the player 2's hand size.
    }
    bool isSkip = false; //Is true if the card placed is an skip or a reverse.
    if(phTemp[choice-1].getColor() == dpPile[0].getColor() || phTemp[choice-1].getNum() == dpPile[0].getNum()
            || phTemp[choice-1].getWild() == true){
        //cout << "WILD: " << p1Hand[choice-1].getWild()<<endl;
        //cout << "Number: " << p1Hand[choice-1].getNum()<<endl;
        //cout << "Color: " << p1Hand[choice-1].getColor() << endl;
        setDP(phTemp[choice-1]);
        isSkip = checkAction(GameState::p);
        removeCard(c,tempSize,choice,GameState::p,isSkip); 
        return true;
    }
    else{
        cout << "Please choose a card of the same number, color or a wild" << endl;
        return false;
    }
}

void GameState::removeCard(Card *c, int &size, int choice, int p, bool a){
    if(a == true){
        GameState::p++;
    }
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
    }
    if(GameState::p % 2 == 0){
        p2Size--;
    }
    cout << "Player " << GameState::p%2+1 << " your turn is over."  << endl << endl << endl;
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
 
 bool GameState::addNewCard(int p, Deck& d){
     if(GameState::p % 2 == 1){
    Card* newHand = new Card[p1Size+1];
    for(int i = 0; i < p1Size; i++){
        newHand[i] = p1Hand[i];
    }
    newHand[p1Size] = d.draw();
    p1Size++;
    delete [] p1Hand;
    p1Hand = newHand;
    cout << "Player " << GameState::p%2+1 << " your turn is over."  << endl << endl << endl;
    GameState::p++;
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
    cout << "Player " << GameState::p%2+1 << " your turn is over."  << endl << endl << endl;
    GameState::p++;
    }
     return true;
 }
 
 bool GameState::checkAction(int p){
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
    else if(dpPile[0].getIntAction()== SKIP || dpPile[0].getIntAction() == REVERSE){
        if(GameState::p % 2 == 0){
            cout << "Your turn has been skipped!" << endl;
        }
        else{
            cout << "Your turn has been skipped!" << endl;
        }
        return true;
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