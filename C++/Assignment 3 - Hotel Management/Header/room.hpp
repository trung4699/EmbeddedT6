#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\customer.hpp"

typedef enum {
    Available,
    Unavailable,
    Cleaning
} RoomStatus;


class Room
{
private:
    int ID;
    Customer Customer_Room;
    RoomStatus Status;
    int Bill;
    
public:
    Room();

    int getID();

    RoomStatus getStatus();

    Customer getCustomerRoom();

    void bookingRoom(Customer customer_room);
    void checkOut();
    
    void freeRoom();

};








#endif