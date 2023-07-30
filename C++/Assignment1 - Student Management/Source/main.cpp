/*
* File: main.cpp
* Author: Phan Hoang Trung
* Date: 30/07/2023
* Description: This is a main file for testing student management program
*/


//#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment1 - Student Management\Header\student.hpp"
//#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment1 - Student Management\Header\studentOperation.hpp"

#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment1 - Student Management\Header\student.hpp"
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment1 - Student Management\Header\studentOperation.hpp"

int main()
{
    std::list <Student> database;
    Student student("Trung", 24, Male, 9, 9, 9);
    Student student1("Phong", 23 , Male , 8, 7, 6);
    Student student2("Linh", 22, Female, 7, 9, 10);
    Student student3("Trang", 20, Female, 9, 8, 8);

    
    database.push_back(student);    // add student to database
    database.push_back(student1);   // add student1 to database
    database.push_back(student2);   // add student2 to database
    database.push_back(student3);   // add student3 to database

    
    addStudent(database);   // add new student to database from keyboard
    addStudent(database);   // add new student to database from keyboard
    
    std::cout << "Print student list: " << '\n';
    print(database);  
    
    updateInfo(database);

    std::cout << "Print student list after update info: " << '\n';
    print(database);

    deleteByID(database);

    std::cout << "Print student list after delete student ID: " << '\n';
    print(database);

    searchByName(database);

    std::cout << "Print the list before sort by GPA" << '\n';
    print(database);

    std::cout << "Now sort the list by GPA and then print the list" << '\n';
    sortByGPA(database);
    print(database);

    std::cout << "Now sort the list by name and then print the list" << '\n';
    sortByName(database);
    print(database);
    
    
    return 0;
}