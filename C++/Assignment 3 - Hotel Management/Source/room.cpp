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
        std::cout << "Booking success " << '\n';
    }
    else
    {
        std::cout << "Cannot booking this room now " << '\n';
    }
}


void Room::checkOut()
{
    if (Status == Unavailable)
    {
        Status = Cleaning;
        Customer admin;
        Customer_Room = admin;
        std::cout << "Check out success " << '\n';
    }
    else if (Status == Cleaning)
    {
        std::cout << "This room is cleaning " << '\n';
    }
    else
    {
        std::cout << "This room is available " << '\n';
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
        std::cout << "Now this room is available " << '\n';
    }
    else
    {
        std::cout << "This room is unavailable" << '\n';
    }
}

void Room::printCustomer()
{
    std::cout << "Name" << "\t|\t" << "Phone" << "\t|\t" << "Address" << '\n';
    Customer_Room.printInfo();
}



