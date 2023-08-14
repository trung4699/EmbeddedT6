#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\floor.hpp"


Floor::Floor()
{
    NumberOfRoom.resize(1);
}

void Floor::setRoom()
{
    int numberRoom;
    std::cout << "Enter number of room serve in this floor: " << '\n';
    std::cin >> numberRoom;

    NumberOfRoom.resize(numberRoom);
    std::cout << "Set up success " << '\n';
}


void Floor::selectRoom(Customer customer_room)
{
    int room;
    do
    {
        std::cout << "Enter room you want to book: " << '\n';
        std::cin >> room;
    } while (room > (int)NumberOfRoom.size() || room < 1);
    
    NumberOfRoom.at(room - 1).bookingRoom(customer_room);

}

void Floor::printRoomStatus()
{
    int countRoom = 1;
    
    std::cout << "Room: " << "\t\t";
    for (int i = 0; i < (int)NumberOfRoom.size(); ++i)
    {
        std::cout << countRoom << '\t';
        ++countRoom;
    }
    
    std::cout << '\n';

    std::cout << "Status: " << '\t';
    for (int i = 0; i < (int)NumberOfRoom.size(); ++i)
    {
        if (NumberOfRoom.at(i).getStatus() == Available)
        {
            std::cout << "A" << '\t';
        }
        else if (NumberOfRoom.at(i).getStatus() == Unavailable)
        {
            std::cout << "U" << '\t';
        }
        else if (NumberOfRoom.at(i).getStatus() == Cleaning)
        {
            std::cout << "C" << '\t';
        }
    }

    std::cout << "A: Available " << '\n'
              << "U: Unavailable " << '\n'
              << "C: Cleaning " << '\n';

    std::cout << '\n';
}