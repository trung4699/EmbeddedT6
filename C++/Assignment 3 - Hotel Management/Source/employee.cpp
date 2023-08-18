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

ShiftWork WorkSchedule::getShiftWork()
{
    return Shift;
}


Date WorkSchedule::getDateWork()
{
    return Date_Work;
}





/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/




Employee::Employee(std::string name, std::string phone, JobPosition position, User_Account employee_account)
{
    Authenticate_Employee = false;
    Authenticate_Admin = false;
    Name = name;
    Phone = phone;
    Position = position;
    Employee_Account = employee_account;
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
    }
}



std::string Employee::getUsernameAccount()
{
    return Employee_Account.userName;
}



std::list <WorkSchedule> Employee::getWorkSchedule()
{
    return Schedule_Database;
}


void Employee::checkLogIn(User_Account account)
{
    bool checkUserName = false, checkPassword = false;
    if (Employee_Account.userName == account.userName)
    {
        checkUserName = true;
    }

    if (Employee_Account.password == account.password)
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
    return (Employee_Account.userName == account.userName);
}

bool Employee::checkLogInPassword(User_Account account)
{
    return (Employee_Account.password == account.password);
}


bool Employee::checkAdminLogIn(User_Account checkAdminAccount)
{

    if (checkAdminAccount.userName == "Admin" && checkAdminAccount.password == "Admin")
    {
        Authenticate_Admin = true;
    }

    return Authenticate_Admin;
}


void Employee::checkLogOut()
{
    Authenticate_Employee = false;
    Authenticate_Admin = false;
}

void Employee::addShift(WorkSchedule workschedule)
{
    Schedule_Database.push_back(workschedule);
}

void Employee::deleteShift(int id)
{
    std::list <WorkSchedule> ::iterator it, ptr;
    for (it = Schedule_Database.begin(); it != Schedule_Database.end(); ++it)
    {
        if ((*it).getID() == id)
        {
            ptr = it;
        }
    }

    Schedule_Database.erase(ptr);
}



void Employee::changePassword(std::string password)
{
    if (Authenticate_Employee || Authenticate_Admin)
    {
        Employee_Account.password = password;
    }
    
}

