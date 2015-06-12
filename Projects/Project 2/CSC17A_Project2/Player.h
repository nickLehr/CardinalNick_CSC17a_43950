/* 
 * File:   Player.h
 * Author: Owner
 *
 * Created on June 3, 2015, 11:38 AM
 */

#ifndef PLAYER_H
#define	PLAYER_H
#include <exception>
#include <stdexcept>
#include "Person.h"
class Player : protected Person{
    private:
    public:
        Player(){
            name = " ";
            age = 0;
        }
        
        Player(std::string, int);
        
        virtual std::string getName();
        virtual void setName();
        
        virtual void setAge();
        virtual int getAge();
        
        void exception(int);
        
        friend std::ostream &operator<<(std::ostream& out, Player& p);
        friend std::istream &operator>>(std::istream& in, Player& p);
};

#endif	/* PLAYER_H */

