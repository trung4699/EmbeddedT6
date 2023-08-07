/*
* File: order.cpp
* Author: Phan Hoang Trung
* Date: 07/08/2023
* Description: This is a file for function definition of one order
* 
*/

#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 2 - Restaurant Management\Header\order.hpp"

/*
* Function: Order
* Description: This is a conductor of Order class to set number of dish and dish for new order
* Input:
*   number_dish - unsinged integer - number of dish
*   dish - Dish - dish
* Output:
*   
*/
Order::Order(unsigned int number_dish, Dish dish)
{
    NumberDish = number_dish;
    DishOrder = dish;
}



/*
* Function: getNumberDishes
* Description: This function will return number of dish
* Input:
*   name - string - dish name 
*   price - float - dish price
* Output:
*   NumberDish - unsigned integer - number of dish
*/
int Order::getNumberDishes()
{
    return NumberDish;
}



/*
* Function: setNumberDishes
* Description: This function will set new number of dish
* Input:
*   number_dishes - unsigned integer - new number of dish
* Output:
*/
void Order::setNumberDishes(unsigned int number_dishes)
{
    NumberDish = number_dishes;
}


/*
* Function: getDish
* Description: This function will return dish
* Input:
* Output:
*   DishOrder - Dish - dish
*/
Dish Order::getDish()
{
    return DishOrder;
}