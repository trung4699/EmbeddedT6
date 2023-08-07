#ifndef ORDER_H
#define ORDER_H

/*
* File: order.hpp
* Author: Phan Hoang Trung
* Date: 07/08/2023
* Description: This is a file include function declaration of one order
*/

#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 2 - Restaurant Management\Header\dish.hpp"


class Order
{
    private:
        unsigned int NumberDish;
        Dish DishOrder;
        
    public:
        Order(unsigned int number_dish, Dish dish);

        int getNumberDishes();
        void setNumberDishes(unsigned int number_dishes);

        Dish getDish();
};

#endif