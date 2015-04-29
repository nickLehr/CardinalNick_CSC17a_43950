/* 
 * File:   main.cpp
 * Author: Nicholas Cardinal
 *
 * Created on April 6, 2015, 7:12 PM
 */

//Use char array to get players name (lol) sry lehr;

//Libs
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <string>
#include <ctime>
using namespace std;
enum Action { blank, DRAW2, DRAW4, WILD, SKIP, REVERSE };

//User Libraries
#include "Card.h"
//Functions
void changeActionCard(int &, int &, int &, string &); //Adds the action cards to un-shuffled deck.
void shuffleDeck(Card *, int &); //Shuffles deck and returns the pointer to the deck.
void resetDeck(Card *, int&);//Sets deck back to default.
void outputDeck(Card *, int);//Outputs deck.
Card* fillHand(Card *, Card *, int&);//Fills players hands with random cards from the deck.
void outputHand(Card *, int); //Displays the players hand after it is randomly picked from the deck.
void gameBegin(Card *, int &, Card *, int);//Places the first card of the shuffled deck down.
Card* gameTurn(Card *, int &, Card *, int &, Card *, int &, Card *, int &, int &);//Handles all actions of players turn.
bool checkCard(Card *, Card *, int &);//Checks to see if the card placed is valid
int cardPlace(Card *, int);
Card* drawCard(Card *, int &, Card *, int &); //Draws a card from the deck.
void checkAction(Card *, int &, Card *, int &, Card *, int &);//Checks what action card was placed.
Card* aiTurn(Card *, int &, Card *, int &,  Card *, int &, Card *, int &, int &);//AI's turn.
void removeCard(Card *, int &, int &, int &);
void dpOut(Card *, int);

int main(int argc, char** argv) {
    srand(time(0));
    int size = 108;
    int handSize = 7;
    int handSize2 = 7;
    Card *deckPtr;//Pointer to the deck.
    Card deck[size];//Holds the deck.
    deckPtr = deck;//Assigns pointer to the deck.
    int dpSize = 1;
    Card discardPile[dpSize];
    Card *dpPtr;
    dpPtr = discardPile;
    int turn = 1;
    resetDeck(deckPtr, size);
    //outputDeck(deck, size);
    shuffleDeck(deckPtr, size);
    Card *hand = new Card[handSize];
    Card *hand2 = new Card[handSize2];
    cout << "Welcome to Uno!" << endl;
    hand = fillHand(hand, deckPtr, size);
    hand2 = fillHand(hand2, deckPtr, size);
    gameBegin(deckPtr, size, dpPtr, dpSize);
    bool won = false;
    while(won == false){
        cout << "Your turn!" << endl;
        cout << "***********************************************************" << endl;
        turn = 1;
        dpOut(discardPile, turn);
        hand = gameTurn(hand, handSize, hand2, handSize2, dpPtr, dpSize, deckPtr, size, turn);
        outputHand(hand, handSize);
        cout << "************************************************************************" << endl;
        turn = 2;
        dpOut(discardPile, turn);
        hand2 = gameTurn(hand2, handSize2, hand, handSize, dpPtr, dpSize, deckPtr, size, turn);
        outputHand(hand2, handSize2);
        if(handSize2 == 0 || handSize == 0){
            won == true;
            break;
        }
    }
    delete [] hand;
    delete [] hand2;
    return 0;
}
void changeActionCard(int &aCrdTyp, int &cNum, int &aCard, string &aCrdStr){
    aCrdTyp++;
    if(aCrdTyp >= 0 && aCrdTyp <= 2){//Set action card to reverse
        cNum = -1;
        aCard = REVERSE;
        aCrdStr = "Reverse";
    }
    else if(aCrdTyp > 2 && aCrdTyp <= 4){//Set action card to Draw2
        aCard = DRAW2;
        cNum = -1;
        aCrdStr = "Draw2";
    }
     else{//Set action card to Skip
        aCard = SKIP;
        cNum = -1;
        aCrdStr = "Skip";
    }
}
void shuffleDeck(Card *deck, int &size){
    int shuffle = 0;
    for(int i=0;i<size;i++){
        shuffle = rand() % 108 + 0;
        swap(deck[i],deck[shuffle]);
    }
}

void resetDeck(Card *deck, int &size){
    int cNum = 1; //Holds a value 1-9 that is to be stored in .number
    string cColor;//Holds the string color(red,green,blue,yellow) & stores in .color
    int aCard;//Holds the action card(draw4,wild,reverse,draw2,skip) & stores in .action
    int aCrdTyp = 0;//After storing 2 action cards the action card is changed
    string aCrdStr;
    for(int i=0;i<size;i++){//Loops in order to change the color of the card stored in .color
        if(i < 24){//If parameters met set card color to Blue
            aCard = 0;
            cColor = "Blue";
            if(i >= 18){//If i is > 18 the color begin placing action cards.
                changeActionCard(aCrdTyp, cNum, aCard, aCrdStr);
            }
        }
        else if(i > 24 && i < 48){//If parameters met set card color to Green
            if(aCrdTyp > 6){
                aCrdTyp = 0;
            }
            aCard = 0;
            cColor = "Green";
            if(i >= 42){//If i is > 42 the color begin placing action cards.
                changeActionCard(aCrdTyp, cNum, aCard, aCrdStr);
            }
        }
        else if(i > 48 && i < 72){//If parameters met set card color to Red
            if(aCrdTyp > 6){
                aCrdTyp = 0;
            }
            aCard = 0;
            cColor = "Red";
            if(i >= 66){//If i is > 66 the color begin placing action cards.
                changeActionCard(aCrdTyp, cNum, aCard, aCrdStr);
            }
        }
        else if(i > 72 && i < 96){//If parameters met set card color to Yellow
            if(aCrdTyp > 6){
                aCrdTyp = 0;
            }
            aCard = 0;
            cColor = "Yellow";
            if(i >= 90){//If i is > 90 the color begin placing action cards.
                changeActionCard(aCrdTyp, cNum, aCard, aCrdStr);
            }
        }
        deck[i].number = cNum;
        deck[i].color = cColor;
        deck[i].action = aCard;
        deck[i].strAction = aCrdStr;
        deck[i].wild = false;
        cNum++; //Increases from 1 - 9 then resets if cNum = 10;
        int count = 0;//Stores the number of times the cNum variable has been reset.
        if(cNum == 10){
             cNum = 1;
             count++;
        }
    }
    //deck[90].action = DRAW2; //Not sure why this is here.
    //Adds the missing 9's to the deck.
    deck[97].number = 9;
    deck[97].color = "Green";
    deck[97].wild = false;
    deck[98].number = 9;
    deck[98].color = "Red";
    deck[98].wild = false;
    deck[99].number = 9;
    deck[99].color = "Yellow";
    deck[99].wild = false;
    for(int i=100;i<105;i++){//Adds wilds to the deck.
        deck[i].action = WILD;
        deck[i].number = -1;
        deck[i].wild = true;
        deck[i].color = "Wild";
        deck[i].strAction = "Wild";
    }
    for(int i=104;i<108;i++){//Adds wild draw4's to the deck.
        deck[i].action = DRAW4;
        deck[i].number = -1;
        deck[i].wild = true;
        deck[i].color = "Wild";
        deck[i].strAction = "Draw4";
    }
}

void outputDeck(Card *deck, int size){
    cout << "Default deck " << endl;
    for(int i=0;i<size;i++){
        if(deck[i].number < 0){
            cout << i <<  "Card Value: " << deck[i].strAction;
        }
        else{
            cout << i <<"Card Value: " << deck[i].number;
        }
        cout << " Color: " << deck[i].color;
        cout << endl;
    }
}

Card* fillHand(Card *hand, Card *deck, int &size){
    int randCrd;
    for(int i=0;i<7;i++){
        randCrd = rand() % size+0;
        hand[i].action = deck[randCrd].action;
        hand[i].color = deck[randCrd].color;
        hand[i].number = deck[randCrd].number;
        hand[i].wild = deck[randCrd].wild;
        hand[i].strAction = deck[randCrd].strAction;
        swap(deck[randCrd],deck[size-1]);
        size--;
    }
    //hand[0].action = DRAW4;
    //hand[0].number = -1;
   // hand[0].wild = true;
    //hand[0].color = "Wild";
    //hand[0].strAction = "Draw4";
    return hand;
}

void outputHand(Card *hand, int handSize){
    for(int i=0;i<handSize;i++){
         if(hand[i].number < 0){
            cout << i+1 << ") " << hand[i].color << " " << hand[i].strAction << endl;
        }
        else{
            cout << i+1 << ") " << hand[i].color << " " << hand[i].number << endl;
        }
    }
}

void gameBegin(Card *deck, int &size, Card *discardPile, int dpSize){
    int randCrd = rand()% size+0;
    if(deck[randCrd].wild == true){
        gameBegin(deck, size, discardPile, dpSize);
    }
    else{
        if(deck[randCrd].number < 0){
            cout << deck[randCrd].strAction << " ";
        }
        else{
            cout << deck[randCrd].number << " ";
        }
        cout << deck[randCrd].color << endl;
        discardPile[0].action = deck[randCrd].action;
        discardPile[0].color = deck[randCrd].color;
        discardPile[0].number = deck[randCrd].number;
        discardPile[0].wild = deck[randCrd].wild;
        discardPile[0].strAction = deck[randCrd].strAction;
        swap(deck[randCrd], deck[size-1]);
        size--;
    }
}

Card* gameTurn(Card *hand, int &handSize, Card *hand2, int &hand2Size, Card *discardPile, int &dpSize, Card *deck, int &deckSize, int &turn){
    int choice = cardPlace(hand, handSize); //Stores the choice of the users card.
    bool accepted = false;
    bool drew = false;
    Card cardPlaced[1]; //Stores the card that the user attempts to place.
    Card *cpPtr;
    cpPtr = cardPlaced;
    Card *newHand;
    while(choice < 0){
        choice = cardPlace(hand, handSize);
    }
    if(choice == 109){
        newHand = drawCard(hand, handSize, deck, deckSize);
        drew = true;
        accepted = true;
    }
    if(drew == false){
        cpPtr[0].action =  hand[choice-1].action;
        cpPtr[0].color =  hand[choice-1].color;
        cpPtr[0].number =  hand[choice-1].number;
        cpPtr[0].wild =  hand[choice-1].wild;
        cpPtr[0].strAction = hand[choice-1].strAction;
        accepted = checkCard(cpPtr, discardPile, dpSize);
    }
    while(accepted == false){//If card is invalid loops until it is.
        choice = cardPlace(hand, handSize);
        cpPtr[0].action =  hand[choice-1].action;
        cpPtr[0].color =  hand[choice-1].color;
        cpPtr[0].number =  hand[choice-1].number;
        cpPtr[0].wild =  hand[choice-1].wild;
        cpPtr[0].strAction = hand[choice-1].strAction;
        accepted = checkCard(cpPtr, discardPile, dpSize);
    }
        if(drew == true){
            cout << "You drew card: ";
            if(newHand[handSize-1].number < 0){
                cout << newHand[handSize-1].color << " " << newHand[handSize-1].strAction;
            }
            else{
                cout << newHand[handSize-1].color << " " << newHand[handSize-1].number;
            }
        }
        else{
            cout << "You placed card: " << choice << endl;
            if(discardPile[0].number < 0){
                cout << discardPile[0].color << " " << discardPile[0].strAction;
            }
            else{
                cout << discardPile[0].color << " " << discardPile[0].number;
            }
        }
    cout << endl;
    if(drew == false && turn == 1){
        //if(discardPile[0].number < 0){
        //    checkAction(hand2, hand2Size, deck, deckSize, discardPile, turn);  
        //}
        //else{
            removeCard(hand,handSize,choice,turn);
            //turn = 2;
        //}
    }
    else if(drew == false && turn == 2){
        //if(discardPile[0].number < 0){
        //    checkAction(hand, handSize, deck, deckSize, discardPile, turn);  
        //}
        //else{
            removeCard(hand2,hand2Size,choice,turn);
            //turn = 1;
        //}
    }
    if(drew == true){
        return newHand;
    }
    else{
        return hand;
    }
}

bool checkCard(Card *cardPlaced, Card *discardPile, int &dpSize){
    if(cardPlaced[0].color == discardPile[0].color || 
            cardPlaced[0].number == discardPile[0].number || 
            cardPlaced[0].wild == true){
            dpSize++;
            discardPile[0].action = cardPlaced[0].action;
            discardPile[0].color = cardPlaced[0].color;
            discardPile[0].number = cardPlaced[0].number;
            discardPile[0].strAction = cardPlaced[0].strAction;
        return true;
    }
    else{
        cout << "Please choose a card of the same number, color or a wild" << endl;
        return false;
    }
}

int cardPlace(Card *hand, int handSize){
    int choice;
    cout << "Which card would you like to place?" << endl;
    for(int i=0;i<handSize;i++){
         if(hand[i].number < 0){
            cout << i+1 << ") " << hand[i].color << " " << hand[i].strAction << endl;
        }
        else{
            cout << i+1 << ") " << hand[i].color << " " << hand[i].number << endl;
        }
    }
    cout << "109) Draw!" << endl;
    cin >> choice; //FIX SO IT DOESN'T ACCEPT CHARS
    if(choice == 109){
        return choice;
    }
    if(choice < 1 || choice > handSize){
        return -1;
    }
    return choice;
}

Card* aiTurn(Card *hand, int &handSize, Card *hand2, int &hand2Size, Card *deck, int &deckSize, Card *discardPile, int &dpSize, int &turn){

}

Card* drawCard(Card *hand, int &handSize, Card *deck, int &deckSize){
    Card *tempHnd = new Card[handSize+1]; //Stores the hand passed in and adds one element.
    for(int i=0;i<handSize;i++){
        tempHnd[i].action = hand[i].action;
        tempHnd[i].color = hand[i].color;
        tempHnd[i].number = hand[i].number;
        tempHnd[i].strAction = hand[i].strAction;
        tempHnd[i].wild = hand[i].wild;
    }
    tempHnd[handSize].action = deck[0].action;
    tempHnd[handSize].color = deck[0].color;
    tempHnd[handSize].number = deck[0].number;
    tempHnd[handSize].strAction = deck[0].strAction;
    tempHnd[handSize].wild = deck[0].wild;
    swap(deck[0],deck[deckSize-1]);
    deckSize--;
    handSize++;
    return tempHnd;
}

void checkAction(Card *hand, int &handSize, Card *deck, int &deckSize, Card *discardPile, int &turn){
    if(discardPile[0].action == DRAW2){
        cout << "Two cards have been added to your enemy's hand!" << endl;
        for(int i=0;i<2;i++){
            hand = drawCard(hand, handSize, deck, deckSize);
        }
    }
    else if(discardPile[0].action == DRAW4){
        cout << "Four cards have been added to your enemy's hand!" << endl;
        for(int i=0;i<4;i++){
            hand = drawCard(hand, handSize, deck, deckSize);
        }
        int pColor;
        string pColors;//Possibly make a function for this.
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
        discardPile[0].color = pColors;
        discardPile[0].number = -1;
    }
    else if(discardPile[0].action == WILD){
        int pColor;
        string pColors;//Possibly make a function for this.
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
        discardPile[0].color = pColors;
    }
    else if(discardPile[0].action == SKIP || discardPile[0].action == REVERSE){
        if(turn == 1){
            turn = 2;
        }
        else{
            turn = 1;
        }
    }
}
void removeCard(Card *hand, int &handSize, int &choice, int &turn){
    cout << "Player " << turn << endl;
    cout << "Card Removed: " << hand[choice-1].color << hand[choice-1].number << hand[choice-1].strAction << endl;
    swap(hand[choice-1], hand[handSize-1]);
    handSize--;
    cout << "****************************************************** " << endl; 
}

void dpOut(Card *discardPile, int turn){
    cout << "Player " << turn << endl;
    if(discardPile[0].number < 0){
            cout << "DP: " << discardPile[0].color << " " << discardPile[0].strAction << endl;
        }
        else{
            cout << "DP: " << discardPile[0].color << " " << discardPile[0].number << endl;
        }
}