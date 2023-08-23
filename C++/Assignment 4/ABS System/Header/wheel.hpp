#ifndef WHEEL_H
#define WHEEL_H

#include <iostream>
#define WHEEL_LIMIT_SPEED 10

class Wheel
{
private:
    int Speed;
public:
    Wheel();
    
    int getSpeed();
    void setSpeed(int speed);

};




#endif