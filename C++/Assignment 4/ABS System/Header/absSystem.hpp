#ifndef ABSSYSTEM_H
#define ABSSYSTEM_H

#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 4\ABS System\Header\car.hpp"

class ABS_System
{
private:
    Car *ABS_System_Car;
public:
    ABS_System(Car *car);
    bool isSpeedWheelUnderLimit();
    void brake();

    int getSpeed();

};





#endif