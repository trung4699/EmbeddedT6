#ifndef BILL_H
#define BILL_H

#include <iostream>



class Bill
{
private:
    int Payment;
    int DayCheckIn;
    int DayCheckOut;
    int PricePerDay;
public:
    Bill();
    
    int getPayment();

    void setDayCheckIn(int day);
    int getDayCheckIn();

    void setDayCheckOut(int day);
    int getDayCheckOut();

    void setPrice(int price);
    int getPrice();
};




#endif