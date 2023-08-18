#ifndef FLOOR_H
#define FLOOR_H

#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\room.hpp"
#include <vector>

class Floor
{
private:
    std::vector <Room> NumberOfRoom;
    int Revenue;
public:
    Floor();

    void setRoom(int numberRoom);

    std::vector <Room> getRoomData();
    
    int getNumberOfRoom();
    void checkOutRoom(int numberRoom);
    void setFreeRoom(int numberRoom);

    void selectRoom(Customer customer_room, int room);
  
    
};

#endif