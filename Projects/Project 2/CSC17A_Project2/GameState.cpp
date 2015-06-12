/* 
 * File:   GameState.cpp
 * Author: Owner
 *
 * Created on May 27, 2015, 1:06 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "GameState.h"
#include "Deck.h"
#include "Card.h"
#include "Player.h"
using namespace std;
enum Action { blank, DRAW2, DRAW4, WILD, SKIP, REVERSE };

GameState::GameState(){
    p1Size = 7;
    p2Size = 7;
    p1Hand = new Card[p1Size];
    p2Hand = new Card[p2Size];
    turn = 1;
    won = false;
    skipped = false;
}

GameState::~GameState(){
    delete [] p1Hand;
    delete [] p2Hand;
}
void GameState::setHand(Deck& gameDeck){
        //Sets up player 1's hand.
        for(int i = 0; i < 7; i++){
            p1Hand[i] = gameDeck.draw();
        }
        //Sets up player 2's hand.
        for(int i = 0; i < 7; i++){
            p2Hand[i] = gameDeck.draw();
        } 
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
    //Sets card to DP.
    dpPile[0].setColor(c.getColor());
    dpPile[0].setNum(c.getNum());
    dpPile[0].setIntAction(c.getIntAction());
    dpPile[0].setStrAction(c.getStrAction());
    dpPile[0].setWild(c.getWild());
    
}

void GameState::outputDP(){
    //Used for outputting the discard pile to the user.
       if(dpPile[0].getNum() < 0){
            cout << "DP: " << dpPile[0].getColor() << " " << dpPile[0].getStrAction() << "!" << endl;
        }
        else{
            cout << "DP: " << dpPile[0].getColor() << " " << dpPile[0].getNum() << "!" << endl;
        }
}

int GameState::cardChoice(Player p,Player p2){
    int choice = 0;
    int size = 0;
    Card* phTemp;
    //If it's player one's turn.
    if(turn % 2 == 1){
        size = p1Size;
        phTemp = p1Hand;
        cout << p.getName() << " it's your turn!" << endl;
    }
    //If it's player 2's turn.
    if(turn % 2 == 0){
        size = p2Size;
        phTemp = p2Hand;
        cout << p2.getName() << " it's your turn!" << endl;
    }
    cout << "Which card would you like to place?" << endl;
    cout << "Enter " << size+1 << " to draw a card." << endl; 
    //Outputs the hand for the user to select.
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
    //If the players choice was to draw a card.
    if(choice == size+1){
        return 109;
    }
    //If the player entered an invalid card.
    if(choice < 1){
        return -1;
    }
    //Returns the choice the player made if it is valid.
    else{
        return choice;
    }
}

bool GameState::getWon(){
    return won;
}

bool GameState::checkCard(Deck& d,Player p, Player p2){
    setSkip(false);
    //Controls the card that the user picks.
    int choice = cardChoice(p,p2);
    if(choice < 0){
        choice = cardChoice(p,p2);
    }
    bool draw = false;
    if(choice == 109){
        //If the user drew a card.
        draw = addNewCard(d,false,p,p2);
        return draw;
    }
    Card* phTemp;
    int tempSize = 0;
    //If player 1's turn
    if(turn % 2 == 1){
        phTemp = p1Hand; //Temp stores the player 1's hand.
        tempSize = p1Size;   //Temp stores the player 2's hand size.
    }
    //If Player 2's turn.
    if(turn % 2 == 0){
        phTemp = p2Hand; //Temp stores the player 2's hand.
        tempSize=p2Size;     //Temp stores the player 2's hand size.
    }
    bool isSkip = false; //Is true if the card placed is an skip or a reverse.
    //Checks if the card placed is valid. 
    if(phTemp[choice-1].getColor() == dpPile[0].getColor() || phTemp[choice-1].getNum() == dpPile[0].getNum()
            || phTemp[choice-1].getWild() == true){
        //Adds the card to the discard pile.
        setDP(phTemp[choice-1]);
        //Checks if the card is a skip card.
        isSkip = checkAction(d,0,p,p2);
        //Removes the card from the players hand.
        removeCard(tempSize,choice,isSkip,p,p2); 
        return true;
    }
    else{
        cout << "Please choose a card of the same number, color or a wild" << endl;
        return false;
    }
}

void GameState::removeCard(int &size, int choice, bool a,Player p, Player p2){
    Card* phTemp;
    //If player one's turn.
    if(turn % 2 == 1){
        phTemp = p1Hand; //Temp stores the player 1's hand.
    }
    //If player two's turn.
    if(turn % 2 == 0){
        phTemp = p2Hand; //Temp stores the player 2's hand
    }
    //Swaps the card chosen with the last card and then the card is deleted.
    swap(phTemp[choice-1], phTemp[size-1]);
    if(turn % 2 == 1){
        p1Size--;
        p1Hand = phTemp;
    }
    if(turn % 2 == 0){
        p2Size--;
        p2Hand = phTemp;
    }
    if(turn%2 == 0){
        cout << p2.getName() << " your turn is over."  << endl << endl << endl;
        cout << p2.getName() << " placed: "; outputDP();  cout<<endl;
    }
    else{
    cout << p.getName() << " your turn is over."  << endl << endl << endl;
    cout << p.getName() << " placed: "; outputDP();  cout<<endl;
    }
    //Increments to the next players turn.
    if(a == true){
        turn++;
    }
    turn++;
    checkWin(p,p2);
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
 
 bool GameState::addNewCard(Deck& d, bool draw, Player p, Player p2){
     if(turn % 2 == 1){
    //Allocates a new card array with one extra space.
    Card* newHand = new Card[p1Size+1];
    //Copies contents of the old hand to the new.
    for(int i = 0; i < p1Size; i++){
        newHand[i] = p1Hand[i];
    }
    newHand[p1Size] = d.draw();
    p1Size++;
    //Deallocated the memory of the old hand.
    delete [] p1Hand;
    //Sets the new hand equal to the old hand.
    p1Hand = newHand;
    if(draw == false){
    cout << p.getName() << " your turn is over."  << endl << endl << endl;
    turn++;
    }
    }
    else if(turn % 2 == 0){
    Card* newHand = new Card[p2Size+1];
        for(int i = 0; i < p2Size; i++){
            newHand[i] = p2Hand[i];
        }
    newHand[p2Size] = d.draw();
    p2Size++;
    delete [] p2Hand;
    p2Hand = newHand;
    if(draw == false){
    cout << p2.getName() << " your turn is over."  << endl << endl << endl;
    turn++;
    }
    }
     return true;
 }
 
 bool GameState::checkAction(Deck& d,int ai,Player p, Player p2){
     Player dummy;
    if(ai==0){
    checkWild();
    }
    else{
        checkAIWild();
    }
    bool isSkip = checkSkip(p,p2);
    if(isSkip == true){
        return true;
    }
    if(ai==0){
    checkDrawAct(d,dummy,dummy);
    }
    else{
        checkDrawAI(d);
    }
    return false;
}
 void GameState::checkWin(Player p, Player p2){
    if(p1Size == 0){
        won = true;
        cout << p.getName() << " wins!" << endl;
        storeStats(p);
        checkStats(p);
    }
    if(p2Size == 0){
        won = true;
        cout << p2.getName() << " wins!" << endl;
        storeStats(p2);
        checkStats(p);
    }
 }
 void GameState::checkWild(){
     //If it is a wild card the user is prompted to enter a color.
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
 
 bool GameState::checkSkip(Player p, Player p2){
     //If the card is a skip then isSkip is set to true allowing for the turn to be skipped.
     if(dpPile[0].getIntAction()== SKIP || dpPile[0].getIntAction() == REVERSE){
        if(turn % 2 == 0){
            cout << p.getName() << "'s turn has been skipped!" << endl;
        }
        else{
            cout << p2.getName() << "'s turn has been skipped!" << endl;
        }
        setSkip(true);
        return true;
    }
     return false;
}
 
 void GameState::checkDrawAct(Deck& d, Player p, Player p2){
    bool draw = false;
    //Adds 2 new cards to the hand if true.
    if(dpPile[0].getIntAction() == DRAW2){
        for(int i = 0; i<2;i++){
            draw = true;
            turn++;
            addNewCard(d,draw,p,p2);
            turn--;
        }
    }
    //Adds 4 new cards to the hand if true.
    if(dpPile[0].getIntAction() == DRAW4){
        for(int i = 0; i<4;i++){
            draw = true;
            turn++;
            addNewCard(d,draw,p,p2);
            turn--;
        }
    }
    draw = false;
}

 int GameState::getTurn(){
     return turn;
 }
 
 void GameState::setTurn(int t){
     turn = t;
 }
 
 void GameState::setSkip(bool s){
     skipped = s;
 }
 
 bool GameState::getSkip(){
     return skipped;
 }
 
 void GameState::AI(Deck& d){
     Player dummy;
     //Controls all aspects of the AI's turn.
     setSkip(false);
     int choice;
     bool draw = false;
     bool isSkip = false;

     choice = checkAI();
     if(choice < 0){
         AIDraw(d);
         draw = true;
     }
     if(choice >= 0){
        setDP(p2Hand[choice]);
        cout << "The AI placed "; outputDP(); cout<<endl;
        cout << "The AI now has " << p2Size << " cards" << endl << endl;
        isSkip = checkAction(d,1,dummy,dummy);
        AIRemove(choice);
     }
}
 
 int GameState::checkAI(){
     int choice = 0;
     bool found = false;
     //Runs through AI's hand and chooses the first card able to be placed. 
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
         cout << "The computer drew a card!" << endl;
         return -1;
     }
     return choice;
 }
 
 void GameState::AIDraw(Deck& d){
     //Draws a card for the AI.
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
     //Removed a card from the AI's hand.
     swap(p2Hand[choice], p2Hand[p2Size-1]);
     p2Size--;
 }
 
 void GameState::checkAIWild(){
     //Runs through the AI's hand and the wild card is chosen by the most 
     //frequently occurring color and sets the wild to that.
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
     //If the AI places a draw 2 it adds 2 cards to p1's hand.
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
     //If the AI places a draw 4 it adds 4 cards to p1's hand.
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
 
 int GameState::menu(){
     int choice;
     cout << "WELCOME TO UNO!" << endl;
     cout << "Which game would you like to play?" << endl;
     cout << "1) Player vs. Player" << endl;
     cout << "2) Player vs. AI" << endl;
     cin >> choice;
     if(choice > 2 || choice < 0){
         cout << "Please choose a valid game!" << endl;
         cin >> choice;
     }
     return choice;
 }
 
 void GameState::setUp(Player &p, Player &p2){
     cout << "Welcome Player 1." << endl;
     p.setName();
     p.setAge();
     cout << endl<<endl;
     cout << "Welcome Player 2." << endl;
     p2.setName();
     p2.setAge();
     
     if(p.getAge() < p2.getAge()){
        cout << p;
        turn = 1;
     }
     else{
         cout << p2;
         turn = 2;
     }
}
 
 void GameState::storeStats(Player p){
    fstream file("stats.bin",ios::binary | ios::in | ios::out | ios::trunc);
    
    if(!file.is_open()){
        cout << "Error opening file" << endl;
    }
    else{
        file.write((char*)&p, sizeof(Player));
        file.seekg(0);
    }
    
    file.close();
 }
 
 void GameState::statsOut(Player winner){     
    fstream file("stats.bin",ios::binary | ios::in | ios::out);
    if(!file.is_open()){
        cout << "Error opening file" << endl;
    }
    else{
        file.read((char*)&winner, sizeof(Player));
    }
    
    cout << winner.getName() << " won in " << turn << " turns!" << endl;
    file.close();
 }
 
 void GameState::checkStats(Player p){
     char answer;
     cout << "Would you like to see see the game stats? [y/n]" << endl;
     cin >> answer;
     if(!cin){
         cout << "Invalid answer!" << endl;
         checkStats(p);
     }
     else if(tolower(answer) == 'y'){
         statsOut(p);
     }
 }