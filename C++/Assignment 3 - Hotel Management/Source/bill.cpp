#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\bill.hpp"

Bill::Bill()
{
    Payment = 0;
    DayCheckIn = 0;
    DayCheckOut = 0;
    PricePerDay = 200;
}

int Bill::getPayment()
{
    return Payment = (DayCheckOut - DayCheckIn) * PricePerDay;
}

void Bill::setDayCheckIn(int day)
{
    DayCheckIn = day;
}

void Bill::setDayCheckOut(int day)
{
    DayCheckOut = day;
}

void Bill::setPrice(int price)
{
    PricePerDay = price;
}

int Bill::getDayCheckIn()
{
    return DayCheckIn;
}

int Bill::getDayCheckOut()
{
    return DayCheckOut;
}

int Bill::getPrice()
{
    return PricePerDay;
}