/*
* File: dish.cpp
* Author: Phan Hoang Trung
* Date: 07/08/2023
* Description: This is a file for function definition of one dish
* 
*/

#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 2 - Restaurant Management\Header\dish.hpp"

/*
* Function: Dish
* Description: This is a conductor of Dish class to set name and price for new dish
* Input:
*   name - string - dish name 
*   price - float - dish price
* Output:
*   
*/
Dish::Dish(std::string name, float price)
{
    Name = name;
    Price = price;
    static int id = 2300;
    ID = id;
    id++;
}


/*
* Function: Dish
* Description: This is a conductor of Dish class set default value
* Input:
* Output:
*   
*/
Dish::Dish()
{
    Name = "Coca";
    Price = 10.0;
}

/*
* Function: getID
* Description: This function will return dish ID
* Input:
* Output:
*   ID - integer - dish ID
*/
int Dish::getID()
{
    return ID;
}


/*
* Function: getName
* Description: This function will return dish name
* Input:
* Output:
*   Name - std::string - dish name
*/
std::string Dish::getName()
{
    return Name;
}


/*
* Function: setName
* Description: This function will set dish new name
* Input:
*   name - std::string - dish new name
* Output:
*/
void Dish::setName(std::string name)
{
    Name = name;
}


/*
* Function: getPrice
* Description: This function will return dish price
* Input:
* Output:
*   Price - float - dish price
*/
float Dish::getPrice()
{
    return Price;
}


/*
* Function: setPrice
* Description: This function will set dish new price
* Input:
*   price - float - dish new price
* Output:
*/
void Dish::setPrice(float price)
{
    Price = price;
}



/*
* Function: printInfo
* Description: This function will print info of a dish: ID, name and price
* Input:
* Output:
*/
void Dish::printInfo()
{
    if (Name.size() >= 8 )
    {
        std::cout << ID << "\t | \t" << Name << "\t | \t" << Price << '\n';
    }
    else
    {
        std::cout << ID << "\t | \t" << Name << "\t\t | \t" << Price << '\n';
    }
}