#ifndef CUSTOMER_H
#define CUSTOMER_H

/*
* File: customer.hpp
* Author: Phan Hoang Trung
* Date: 12/08/2023
* Description: This is a file include function declaration of one customer
*/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\general.hpp"


typedef enum {
    IN,
    OUT
} Check;

typedef struct {
    Date date;
    Time time;
    Check check;
}  BookingHistory;

class Customer
{
private:
    std::string Name;
    std::string Phone;
    std::string Address;
    Check CheckInOut;
    std::list <BookingHistory> BookingHistoryData;

public:
    Customer(std::string name, std::string phone, std::string address);
    Customer();
    
    std::string getName();
    void setName(std::string name);

    std::string getPhone();
    void setPhone(std::string phone);

    std::string getAddress();
    void setAddress(std::string address);

    void checkInAndOut();
    
    void printBookingHistory();
    void printInfo();
};


#endif