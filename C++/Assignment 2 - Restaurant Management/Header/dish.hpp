#ifndef DISH_H
#define DISH_H

/*
* File: dish.hpp
* Author: Phan Hoang Trung
* Date: 07/08/2023
* Description: This is a file include function declaration of one dish
*/

#include <iostream>
#include <string>
#include <list>


class Dish
{
private:
    int ID;
    std::string Name;
    float Price;
public:
    Dish(std::string name, float price);
    Dish();

    int getID();
    
    std::string getName();
    void setName(std::string name);

    float getPrice();
    void setPrice(float price);

    void printInfo();
};


#endif