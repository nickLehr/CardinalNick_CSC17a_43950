/* 
 * File:   Person.h
 * Author: Owner
 *
 * Created on June 3, 2015, 11:28 AM
 */

#ifndef PERSON_H
#define	PERSON_H

class Person{
    protected:
        std::string name;
        int age;
    public:
        //Declared virtual in order to be overridden by the Player class.
        virtual std::string getName() = 0;
        virtual void setName() = 0;
        
        virtual void setAge() = 0;
        virtual int getAge() = 0;
};

#endif	/* PERSON_H */

