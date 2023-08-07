/*
* File: operation.cpp
* Author: Phan Hoang Trung
* Date: 07/08/2023
* Description: This is a file for function definition of operation with dish and order
* 
*/

#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 2 - Restaurant Management\Header\operation.hpp"


/*
* Function: printMenu
* Description: This function will print menu of restaurant
* Input:
*   menu - address of fisrt node in a list, has datatype Dish - list of dish
* Output:
*   a list with new student 
*/
void printMenu(std::list <Dish> &menu)
{
    std::list <Dish> ::iterator it;
    int stt = 1;

    //std::cout << "STT" << '\t' << "|" << '\t' << "ID" << '\t' << "|" << '\t' << "Name" << '\t' << '\t' << "|" << '\t' << "Price" << '\n';

    std::cout << "STT" << "\t | \t" << "ID" << "\t | \t" << "Name" <<  "\t\t | \t" << "Price" << '\n';
    for (it = menu.begin(); it != menu.end(); ++it)
    {
        if ((*it).getName().size() >= 8)
        {
            std::cout << stt << "\t | \t" << (*it).getID() << "\t | \t" << (*it).getName() << "\t | \t" << (*it).getPrice() << '\n';
        }
        else
        {
            std::cout << stt << "\t | \t" << (*it).getID() << "\t | \t" << (*it).getName() << "\t\t | \t" << (*it).getPrice() << '\n';
        }
        ++stt;
    }
    
}




/*
* Function: addNewDish
* Description: This function will add new dish to menu of restaurant
* Input:
*   menu - address of fisrt node in a list, has datatype Dish - list of dish
* Output:
*   a list with new dish 
*/
void addNewDish(std::list <Dish> &menu)
{
    std::string nameNewDish;
    float priceNewDish;

    std::cout << "Enter new dish name: " << '\n';
    std::cin >> nameNewDish;

    std::cout << "Enter new dish price: " << '\n';
    std::cin >> priceNewDish;

    Dish newDish(nameNewDish,priceNewDish);

    menu.push_front(newDish);

    std::cout << "Here is new dish info: " << '\n';
    std::cout << "ID" << "\t | \t" << "Name" <<  "\t\t | \t" << "Price" << '\n';
    newDish.printInfo();
}




/*
* Function: updateInfoDish
* Description: This function will update new info of one dish in menu
* Input:
*   menu - address of fisrt node in a list, has datatype Dish - list of dish
* Output:
*/
void updateInfoDish(std::list <Dish> &menu)
{
    std::list <Dish> ::iterator it;

    printMenu(menu);
    std::cout << "Enter ID of dish you want to update info: " << '\n';
    int id;
    std::cin >> id;
    for (it = menu.begin(); it != menu.end(); ++it)
    {
        if ((*it).getID() == id)
        {
            bool checkUpdate = false;
            do
            {
                int selectOptionUpdate;
                
                do
                {
                    (*it).printInfo();
                    std::cout << "Please choose number to update info of dish: " << '\n' ;
                    std::cout << "1. Name " << '\n';
                    std::cout << "2. Price " << '\n';

                    std::cin >> selectOptionUpdate;
                } while (selectOptionUpdate != 1 && selectOptionUpdate != 2);
                
                if (selectOptionUpdate == 1)
                {
                    std::string newName;
                    std::cout << "Enter dish new name: " << '\n';
                    std::cin >> newName;
                    (*it).setName(newName);
                }

                else if (selectOptionUpdate == 2)
                {
                    double newPrice;
                    std::cout << "Enter dish new price: " << '\n';
                    std::cin >> newPrice;
                    (*it).setPrice(newPrice);
                }
                
                
                int updateOtherInfo;
                do
                {
                    std::cout << "Do you want to update other info ? " << '\n';
                    std::cout << "1. Yes " << '\n';
                    std::cout << "0. No " << '\n';
                    std::cin >> updateOtherInfo;
                } while (updateOtherInfo != 1 && updateOtherInfo != 0);
                
                if (updateOtherInfo == 1)
                {
                    checkUpdate = true;
                }
                else if (updateOtherInfo == 0)
                {
                    checkUpdate = false;
                }        
            } while (checkUpdate);   
            break;
        }
    }
}



/*
* Function: deleteDish
* Description: This function will delete one dish from menu
* Input:
*   menu - address of fisrt node in a list, has datatype Dish - list of dish
* Output:
*/
void deleteDish(std::list <Dish> &menu)
{
    std::list <Dish> ::iterator it;
    std::list <Dish> ::iterator ptr;
    bool checkID = false;

    printMenu(menu);
    std::cout << "Enter ID of dish you want to delete " << '\n';
    int id;
    std::cin >> id;


    for (it = menu.begin(); it != menu.end(); ++it)
    {
        if ((*it).getID() == id)
        {
            checkID = true;
            ptr = it;
            break;
        }
    }

    if (!checkID)
    {
        std::cout << "ID unfound " << '\n';
    }
    else
    {
        std::cout << "Delete dish ID: " << (*ptr).getID() << '\n';
        menu.erase(ptr);
    }
    
    
}



/*
* Function: orderDish
* Description: This function will return one order
* Input:
*   menu - address of fisrt node in a list, has datatype Dish - list of dish
* Output:
*/
Order orderDish(std::list <Dish> &menu)
{
    printMenu(menu);
    std::list <Dish> ::iterator it;

    Dish dishOrder;
    int id;
    unsigned int number_dishes;
    bool checkID = true;

    do
    {
        std::cout << "Enter ID of dish you want to order: " << '\n';
        std::cin >> id;

        for (it = menu.begin(); it != menu.end(); ++it)
        {
            if ((*it).getID() == id)
            {
                
                checkID = false;
                dishOrder = (*it);
                std::cout << "Enter number of dishes: " << '\n';
                std::cin >> number_dishes;
            }
        }

        if (checkID)
        {
            std::cout << "ID unfound " << '\n';
        }
        
    } while (checkID);
    Order newDishOrder(number_dishes, dishOrder);
    return newDishOrder;
}



