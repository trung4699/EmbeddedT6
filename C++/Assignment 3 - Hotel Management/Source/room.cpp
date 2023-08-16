/*
* File: room.cpp
* Author: Phan Hoang Trung
* Date: 12/08/2023
* Description: This is a file for function definition of one room
* 
*/


#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\room.hpp"

Room::Room()
{
    Status = Available;
    static int id = 101;
    
    ID = id;
    id++;
}

int Room::getID()
{
    return ID;
}

void Room::bookingRoom(Customer customer_room)
{
    if (Status == Available)
    {
        Status = Unavailable;
        Customer_Room = customer_room;
    }
}


void Room::checkOut()
{
    if (Status == Unavailable)
    {
        Status = Cleaning;
        Customer admin;
        Customer_Room = admin;
    }
}


RoomStatus Room::getStatus()
{
    return Status;
}


void Room::freeRoom()
{
    if (Status == Cleaning)
    {
        Status = Available;
    }
}

Customer Room::getCustomerRoom()
{
    return Customer_Room;
}


