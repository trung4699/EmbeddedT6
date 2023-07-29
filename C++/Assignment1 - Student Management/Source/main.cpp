/*
* File: main.cpp
* Author: Phan Hoang Trung
* Date: 29/07/2023
* Description: This is a main file for testing student management program
*/

#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment1 - Student Management\Header\student.hpp"


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

   
    student.addStudent(database);   // add new student to database from keyboard
    student.addStudent(database);   // add new student to database from keyboard
    
    std::cout << "Print student list: " << '\n';
    student1.print(database);  
    
    std::cout << "Update info for student ID 232 - This in main file " << '\n';
    student1.updateInfo(database, 232);

    std::cout << "Update info for student ID 230002 - This in main file " << '\n';
    student1.updateInfo(database, 230002);

    std::cout << "Print student list after update info for ID 230002" << '\n';
    student1.print(database);

    std::cout << "Delete student ID 2303 - This in main file" << '\n';
    student1.deleteByID(database, 2303);

    std::cout << "Delete student ID 230003 - This in main file" << '\n';
    student1.deleteByID(database, 230003);

    std::cout << "Print student list after delete student ID 230003" << '\n';
    student1.print(database);

    std::cout << "Test function search by name " << '\n';

    std::cout << "Search name Linh" << '\n';
    student1.searchByName(database, "Linh");

    std::cout << "Search name Trung" << '\n';
    student1.searchByName(database,"Trung");

    std::cout << "Search name Phong" << '\n';
    student1.searchByName(database,"Phong");

    std::cout << "Search name Trang" << '\n';
    student1.searchByName(database,"Trang");

    std::cout << "Print the list before sort by GPA" << '\n';
    student1.print(database);

    std::cout << "Now sort the list by GPA and then print the list" << '\n';
    student1.sortByGPA(database);
    student1.print(database);

    std::cout << "Now sort the list by name and then print the list" << '\n';
    student1.sortByName(database);
    student1.print(database);
    

    return 0;
}