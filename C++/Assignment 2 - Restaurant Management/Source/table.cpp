/*
* File: table.cpp
* Author: Phan Hoang Trung
* Date: 07/08/2023
* Description: This is a file for function definition of one table
* 
*/

#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 2 - Restaurant Management\Header\table.hpp"


/*
* Function: getStatus
* Description: This funtionc will return table status
* Input:
* Output:
*   Status - bool - table status
*/

bool Table::getStatus()
{
    return Status;
}


/*
* Function: setStatus
* Description: This funtionc will set table status
* Input:
*   status - bool - table status
* Output:
*/
void Table::setStatus(bool status)
{
    Status = status;
}



/*
* Function: addOrder
* Description: This funtionc will add order to table
* Input:
* Output:
*/
void Table::addOrder(Order new_order)
{
    Database_Order.push_front(new_order);
    Status = false;
}


/*
* Function: deleteOrder
* Description: This funtionc will delete one order from table
* Input:
* Output:
*/
void Table::deleteOrder()
{
    std::list <Order> ::iterator it;
    std::list <Order> ::iterator ptr;
    bool checkID = false;

    std::cout << "Enter ID of dish you want to delete " << '\n';
    int id;
    std::cin >> id;


    for (it = Database_Order.begin(); it != Database_Order.end(); ++it)
    {
        if ((*it).getDish().getID() == id)
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
        std::cout << "Delete dish ID: " << (*ptr).getDish().getID() << '\n';
        Database_Order.erase(ptr);
    }
    std::cout << "---------------------------------------------" << '\n';
}



/*
* Function: printPayment
* Description: This funtionc will print list of order and total payment
* Input:
* Output:
*/
void Table::printPayment()
{
    std::list <Order> ::iterator it;
    int stt = 1;
    double total = 0;

    std::cout << "STT" << "\t | \t" << "ID" << "\t | \t" << "Name" << "\t\t | \t" << "Price" << "\t | \t" << "Quantity" << '\n';

    for (it = Database_Order.begin(); it != Database_Order.end(); ++it)
    {
        
        if ((*it).getDish().getName().size() >= 8)
        {
            std::cout << stt << "\t | \t" << (*it).getDish().getID() << "\t | \t" << (*it).getDish().getName() << "\t | \t" << (*it).getDish().getPrice() << "\t | \t" << (*it).getNumberDishes() << '\n';
        }
        else
        {
            std::cout << stt << "\t | \t" << (*it).getDish().getID() << "\t | \t" << (*it).getDish().getName() << "\t\t | \t" << (*it).getDish().getPrice() << "\t | \t" << (*it).getNumberDishes() << '\n';
        }

        ++stt;
        total += (*it).getDish().getPrice() * (*it).getNumberDishes();
    }
    std::cout << "---------------------------------------------" << '\n';
    std::cout << "Total: " << total << '\n';
    std::cout << "---------------------------------------------" << '\n';
}


/*
* Function: printOrder
* Description: This funtionc will list of order
* Input:
* Output:
*/
void Table::printOrder()
{
    std::list <Order> ::iterator it;
    int stt = 1;

    std::cout << "STT" << "\t | \t" << "ID" << "\t | \t" << "Name" << "\t\t | \t" << "Price" << "\t | \t" << "Quantity" << '\n';

    for (it = Database_Order.begin(); it != Database_Order.end(); ++it)
    {
        
        if ((*it).getDish().getName().size() >= 8)
        {
            std::cout << stt << "\t | \t" << (*it).getDish().getID() << "\t | \t" << (*it).getDish().getName() << "\t | \t" << (*it).getDish().getPrice() << "\t | \t" << (*it).getNumberDishes() << '\n';
        }
        else
        {
            std::cout << stt << "\t | \t" << (*it).getDish().getID() << "\t | \t" << (*it).getDish().getName() << "\t\t | \t" << (*it).getDish().getPrice() << "\t | \t" << (*it).getNumberDishes() << '\n';
        }

        ++stt;
    }
    std::cout << "---------------------------------------------" << '\n';
}



/*
* Function: makePayment
* Description: This funtionc will set table to free status
* Input:
* Output:
*/
void Table::makePayment()
{
    total = 0;
    Status = true;
    Database_Order.clear();
}