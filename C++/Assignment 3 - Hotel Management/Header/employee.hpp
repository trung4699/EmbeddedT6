#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <list>
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\general.hpp"

typedef enum {
    Hotel_Manager,
    Room_Attendant,
    Hotel_Receptionist,
    Hotel_HouseKeeper,
    Maintainance_Technician,
} JobPosition;


typedef struct {
    std::string userName;
    std::string password;
} User_Account;

typedef enum {
    Morning_Shift,
    Afternoon_Shift,
    Night_Shift
} ShiftWork;


class WorkSchedule
{
private:
    Date Date_Work;
    ShiftWork Shift;
    int ID;
public:
    WorkSchedule(Date date, ShiftWork shift);

    int getID();
    void printShift();
};


class Employee
{
private:
    std::string Name;
    std::string Phone;
    JobPosition Position;
    std::list <WorkSchedule> Schedule_Database;
    User_Account Account;
    bool Authenticate_Employee;
    bool Authenticate_Admin;

public:
    Employee(std::string name, std::string phone, JobPosition position);
    
    std::string getName();
    void setName(std::string name);

    std::string getPhone();
    void setPhone(std::string phone);

    JobPosition getPosition();
    void setPosition(JobPosition position);

    void addShift();
    void deleteShift();
    void printWorkSchedule();

    void changePassword(std::string password);

    void checkLogIn(User_Account account);
    bool checkLogInUsername(User_Account account);
    bool checkLogInPassword(User_Account account);

    bool checkAdminLogIn();
    void checkLogOut();

    void printInfo();

};




#endif