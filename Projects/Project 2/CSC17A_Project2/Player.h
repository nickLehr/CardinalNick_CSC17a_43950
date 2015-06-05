/* 
 * File:   Player.h
 * Author: Owner
 *
 * Created on June 3, 2015, 11:38 AM
 */

#ifndef PLAYER_H
#define	PLAYER_H
#include "Person.h"
class Player : protected Person{
    private:
        int age;
        char* AIname;
        char* AIalias;
    public:
        Player(){};
        int getAge();
        void setAge(int);
        //Gets and sets the name of the AI. 
        //Overload the getName and setName in Person class.
        virtual char* getName();
        virtual void setName(char*);
        //Gets and sets the alias of the AI.
        //Overload the getAlias and setAlias in Person class.
        virtual char* getAlias();
        virtual void setAlias(char*);
};

#endif	/* PLAYER_H */

