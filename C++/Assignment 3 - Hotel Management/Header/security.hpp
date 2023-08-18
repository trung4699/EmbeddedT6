#ifndef SECURITY_H
#define SECURITY_H

/*
* File: customer.hpp
* Author: Phan Hoang Trung
* Date: 12/08/2023
* Description: This is a file include function declaration of one customer
*/

#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\employee.hpp"

class Security
{
private:
    User_Account Admin_Account;
    bool Authenticate;

public:
    Security();

    bool getAuthenticate();

    void checkAdminLogIn(User_Account account);
    void setPassword(std::string password);
    void adminLogOut();
    
};



#endif