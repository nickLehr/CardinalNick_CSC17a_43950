/* 
 * File:   Car.h
 * Author: Owner
 *
 * Created on May 6, 2015, 8:21 PM
 */

#ifndef CAR_H
#define	CAR_H
#include <string>
class Car{
    private:
        int yearModel;
        std::string make;
        int speed;
    public:
        Car(int,std::string);
        int getYM(){return yearModel;}
        std::string getMake(){return make;}
        int getSpeed(){return speed;}
        void setYM(int);
        void setMake(std::string);
        void setSpeed(int);
        void accelerate();
        void brake();
};

#endif	/* CAR_H */

