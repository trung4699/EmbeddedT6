#ifndef STUDENT_OPERATION_H
#define STUDENT_OPERATION_H

/*
* File: studentOperation.hpp
* Author: Phan Hoang Trung
* Date: 30/07/2023
* Description: This is a file include function declaration for some operation with database
*/

#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment1 - Student Management\Header\student.hpp"


    void addStudent(std::list <Student> &database);
    void updateInfo(std::list <Student> &database, int id);
    void deleteByID(std::list <Student> &database, int id);
    void searchByName(std::list <Student> &database, std::string name);

    void print(std::list <Student> &database);
    void sortByGPA(std::list <Student> &database);
    void sortByName(std::list <Student> &database);

#endif