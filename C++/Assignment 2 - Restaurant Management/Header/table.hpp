#ifndef TABLE_H
#define TABLE_H

/*
* File: table.hpp
* Author: Phan Hoang Trung
* Date: 07/08/2023
* Description: This is a file include function declaration of one table
*/

#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 2 - Restaurant Management\Header\order.hpp"


class Table
{
    private:
        std::list <Order> Database_Order;
        bool Status = true;
        double total;
    public:
        bool getStatus();
        void setStatus(bool status);

        void addOrder(Order new_order);
        void deleteOrder();
        void printPayment();
        void printOrder();
        void makePayment();

};

#endif