/*
* File: employee.cpp
* Author: Phan Hoang Trung
* Date: 12/08/2023
* Description: This is a file for function definition of one employee
* 
*/

#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\employee.hpp"

WorkSchedule::WorkSchedule(Date date, ShiftWork shift)
{
    Date_Work = date;
    Shift = shift;
    static int id = 10;
    ID = id;
    id++;
}

int WorkSchedule::getID()
{
    return ID;
}


void WorkSchedule::printShift()
{
    if (Shift == Morning_Shift)
    {
        std::cout << ID << "\t|\t" << "Morning  " << "\t|\t" << Date_Work.day << "/" << Date_Work.month << "/" << Date_Work.year << '\n';
    }
    else if (Shift == Afternoon_Shift)
    {
        std::cout << ID << "\t|\t" << "Afternoon" << "\t|\t" << Date_Work.day << "/" << Date_Work.month << "/" << Date_Work.year << '\n';
    }
    else if (Shift == Night_Shift)
    {
        std::cout << ID << "\t|\t" << "Night    " << "\t|\t" << Date_Work.day << "/" << Date_Work.month << "/" << Date_Work.year << '\n';
    }
    
}


Employee::Employee(std::string name, std::string phone, JobPosition position)
{
    Authenticate_Employee = false;
    Authenticate_Admin = false;
    Name = name;
    Phone = phone;
    Position = position;
    User_Account newAccount;
    newAccount.userName = Name + Phone;
    newAccount.password = Phone;
    Account = newAccount;
}

std::string Employee::getName()
{
    return Name;
}

void Employee::setName(std::string name)
{
    if (Authenticate_Employee || Authenticate_Admin)
    {
        Name = name;
    }
}

std::string Employee::getPhone()
{
    return Phone;
}

void Employee::setPhone(std::string phone)
{
    if (Authenticate_Employee || Authenticate_Admin)
    {
        Phone = phone;
    }
}

JobPosition Employee::getPosition()
{
    return Position;
}

void Employee::setPosition(JobPosition position)
{

    if (Authenticate_Admin)
    {
        Position = position;
        std::cout << "Change position success " << '\n';
    }
    else
    {
        std::cout << "You don't have permission to change this " << '\n';
    }
}



void Employee::checkLogIn(User_Account account)
{
    bool checkUserName = false, checkPassword = false;
    if (Account.userName == account.userName || "Admin")
    {
        checkUserName = true;
    }

    if (Account.password == account.password || "Admin")
    {
        checkPassword = true;
    }
    
    if (checkUserName && checkPassword)
    {
        Authenticate_Employee = true;
    }
}


bool Employee::checkLogInUsername(User_Account account)
{
    return (Account.userName == account.userName);
}

bool Employee::checkLogInPassword(User_Account account)
{
    return (Account.password == account.password);
}


bool Employee::checkAdminLogIn()
{
    User_Account checkAdminAccount;
    std::cout << "Enter admin username: " << '\n';
    std::cin >> checkAdminAccount.userName;
    std::cout << "Enter admin password: " << '\n';
    std::cin >> checkAdminAccount.password;

    if (checkAdminAccount.userName == "Admin")
    {
        if (checkAdminAccount.password == "Admin")
        {
            Authenticate_Admin = true;
            std::cout << "Log in admin success " << '\n';
        }
        else
        {
            std::cout << "Wrong admin password " << '\n';
        }
    }
    else   
    {
        std::cout << "Wrong admin username " << '\n';
    }
    return Authenticate_Admin;
}


void Employee::checkLogOut()
{
    std::cout << "You have log out " << '\n';
    Authenticate_Employee = false;
    Authenticate_Admin = false;
}

void Employee::addShift()
{
    if (Authenticate_Admin)
    {
        Date newDateWork;
        ShiftWork newShiftWork;
        int numWorkShift;

        std::cout << "Enter work day: " << '\n';
        std::cin >> newDateWork.day;

        std::cout << "Enter work month: " << '\n';
        std::cin >> newDateWork.month;

        std::cout << "Enter work year: " << '\n';
        std::cin >> newDateWork.year;

        do
        {
            std::cout << "Enter work shift: " << '\n'
                      << "1. Morning shift " << '\n'
                      << "2. Afternoon shift " << '\n'
                      << "3. Night shift " << '\n';
            std::cin >> numWorkShift;
        } while (numWorkShift != 1 && numWorkShift != 2 && numWorkShift != 3);

        if (numWorkShift == 1)
        {
            newShiftWork = Morning_Shift;
        }
        else if (numWorkShift == 2)
        {
            newShiftWork = Afternoon_Shift;
        }
        else if (numWorkShift == 3)
        {
            newShiftWork = Night_Shift;
        }
    
        WorkSchedule newWorkSchedule(newDateWork,newShiftWork);
        Schedule_Database.push_back(newWorkSchedule);
    }
    else
    {
        std::cout << "You don't have permission " << '\n';
    }
}


void Employee::deleteShift()
{
    std::list <WorkSchedule> ::iterator it, ptr;
    std::cout << "Enter ID of shift you want to delete: " << '\n';
    int deleteID;
    std::cin >> deleteID;
    bool checkID = true;

    for (it = Schedule_Database.begin(); it != Schedule_Database.end() ; ++it)
    {
        if ((*it).getID() == deleteID)
        {
            checkID = false;
            ptr = it;
        }
    }

    if (checkID)
    {
        std::cout << "ID unfound " << '\n';
    }
    else
    {
        Schedule_Database.erase(ptr);
        std::cout << "Delete success " << '\n';
    }
}


void Employee::printWorkSchedule()
{
    std::list <WorkSchedule> ::iterator it;

    std::cout << "ID" << "\t|\t" << "Shift   " << "\t|\t" << "Date" << '\n';

    for (it = Schedule_Database.begin(); it != Schedule_Database.end(); ++it)
    {
        (*it).printShift();
    }
}




void Employee::changePassword(std::string password)
{
    if (Authenticate_Employee)
    {
        Account.password = password;
    }
    
}


void Employee::printInfo()
{
    std::cout << Name << "\t|\t" << Phone << "\t|\t";

    if (Position == Hotel_Manager)
    {
        std::cout << "Hotel Manager " << '\n';
    }
    else if (Position == Hotel_HouseKeeper)
    {
        std::cout << "Housekeeper " << '\n';
    }
    else if (Position == Hotel_Receptionist)
    {
        std::cout << "Receptionist " << '\n';
    }
    else if (Position == Maintainance_Technician)
    {
        std::cout << "Maintaninace Technician " << '\n';
    }
    else if (Position == Room_Attendant)
    {
        std::cout << "Room Attendant " << '\n';
    }
    
}