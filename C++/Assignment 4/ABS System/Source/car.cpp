


#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 4\ABS System\Header\car.hpp"

Car::Car()
{
    Car_Weight = 1000;
    Customer_Weight = 0;
    Total_Weight = Car_Weight + Customer_Weight;
}

double Car::getCarWeight()
{
    return Car_Weight;
}

double Car::getTotalWeight()
{
    return Total_Weight;
}

void Car::setCarWeight(double car_weight)
{
    Car_Weight = car_weight;
    Total_Weight = Car_Weight + Customer_Weight;
}

void Car::addCustomer(double customer_weight)
{
    Customer_Weight += customer_weight;
    Total_Weight = Car_Weight + Customer_Weight;
}

void Car::setSpeed(int speed)
{
    Car_Wheel.setSpeed(speed);
}

int Car::getSpeed()
{
    return Car_Wheel.getSpeed();
}