#ifndef CAR_H
#define CAR_H

#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 4\ABS System\Header\wheel.hpp"


class Car
{
private:
    Wheel Car_Wheel;
    double Car_Weight;
    double Customer_Weight;
    double Total_Weight;
public:
    Car();
    

    double getCarWeight();
    void setCarWeight(double car_weight);

    void addCustomer(double customer_weight);
   
    double getTotalWeight();

    void setSpeed(int speed);
    int getSpeed();


};



#endif