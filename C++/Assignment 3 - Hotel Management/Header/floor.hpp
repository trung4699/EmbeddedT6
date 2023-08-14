#ifndef FLOOR_H
#define FLOOR_H

#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\room.hpp"
#include <vector>

class Floor
{
private:
    std::vector <Room> NumberOfRoom;
public:
    Floor();

    void setRoom();
    void selectRoom(Customer customer_room);
    void printRoomStatus();
    
};

#endif