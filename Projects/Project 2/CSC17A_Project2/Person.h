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
        char* name;
        char* alias;
    public:
        Person(){};
        virtual char* getName();
        virtual void setName(char*);
        virtual char* getAlias();
        virtual void setAlias(char*);
};



#endif	/* PERSON_H */

