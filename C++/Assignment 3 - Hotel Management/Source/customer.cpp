/*
* File: customer.cpp
* Author: Phan Hoang Trung
* Date: 12/08/2023
* Description: This is a file for function definition of one customer
* 
*/

#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\customer.hpp"



/*
* Function: Customer
* Description: This is a conductor of Customer class to set new Customer information include name, phone and address
* Input:
*   name - string - customer name
*   phone - string - customer phone
*   address - string - customer address
* Output:
*   
*/
Customer::Customer(std::string name, std::string phone, std::string address)
{
    Name = name;
    Phone = phone;
    Address = address;
    CheckInOut = OUT;
}

Customer::Customer()
{
    Name = "Admin";
    Phone = "Admin";
    Address = "Admin";
}

/*
* Function: getName
* Description: This function will return customer name
* Input:
* Output:
*   Name - string - customer name
*/
std::string Customer::getName()
{
    return Name;
}

/*
* Function: setName
* Description: This function will update name for customer
* Input:
*   name - string - customer new name
* Output:
*/
void Customer::setName(std::string name)
{
    Name = name;
}

/*
* Function: getPhone
* Description: This function will return customer phone
* Input:
* Output:
*   Phone - string - customer phone
*/
std::string Customer::getPhone()
{
    return Phone;
}



/*
* Function: setPhone
* Description: This function will update phone for customer
* Input:
*   phone - string - customer new phone
* Output:
*/
void Customer::setPhone(std::string phone)
{
    Phone = phone;
}


/*
* Function: getAddress
* Description: This function will return customer address
* Input:
* Output:
*   Address - string - customer address
*/
std::string Customer::getAddress()
{
    return Address;
}

/*
* Function: setAddress
* Description: This function will update address for customer
* Input:
*   address - string - customer new address
* Output:
*/
void Customer::setAddress(std::string address)
{
    Address = address;
}


/*
* Function: checkInAndOut
* Description: This function will add date, time and check in/out of customer to booking history to store his/her data
* Input:
*   time - Time - time when customer check in/out
*   date - Date - date when customer check in/out
*   check - Check - to check whether customer check in or check out
* Output:
*/
void Customer::addCheckInAndOutHistory()
{
    Time CheckTime;

    if (CheckInOut == OUT)
    {
        CheckInOut = IN;
    }
    else if (CheckInOut == IN)
    {
        CheckInOut = OUT;
    }

    time_t curr_time;
	curr_time = time(NULL);
	tm *tm_local = localtime(&curr_time);

    if ((tm_local->tm_hour) + 6 > 23)
    {
        CheckTime.hours = (tm_local->tm_hour) + 6 - 24;
    }
    else
    {
        CheckTime.hours = (tm_local->tm_hour) + 6;
    }
    
    CheckTime.minutes = tm_local->tm_min;
    CheckTime.seconds = tm_local->tm_sec;
    
    Date date;
    date.day = tm_local->tm_mday;
    date.month = tm_local->tm_mon + 1;
    date.year = tm_local->tm_year + 1900;

    PaymentStatus payment_status = No;

    BookingHistory newBooking;
    newBooking.time = CheckTime;
    newBooking.date = date;
    newBooking.check = CheckInOut;
    newBooking.payment_status = payment_status;

    BookingHistoryData.push_back(newBooking);
}

Check Customer::getCheckInOut()
{
    return CheckInOut;
}

std::list <BookingHistory> Customer::getBookingHistory()
{
    return BookingHistoryData;
}


void Customer::setPaymentStatus(int day)
{
    std::list <BookingHistory> ::iterator it;
    for (it = BookingHistoryData.begin(); it != BookingHistoryData.end(); ++it)
    {
        if ((*it).date.day == day && (*it).payment_status == No)
        {
            (*it).payment_status = Yes;
        }
        
    }
    
}