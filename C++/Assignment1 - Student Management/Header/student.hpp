#ifndef STUDENT_H
#define STUDENT_H

/*
* File: student.hpp
* Author: Phan Hoang Trung
* Date: 28/07/2023
* Description: This is a file include everything in preprocessor for student.cpp and main.cpp
*/

#include <iostream>
#include <string>
#include <list>

typedef enum
{
    Male,
    Female
}TypeGender;

typedef enum
{
    Excelent,
    Great,
    Middle,
    Weak
} TypeRank;

class Student
{
private:
    int ID ;
    std::string Name;
    TypeGender Gender;
    int Age;
    double Score_Math;
    double Score_Physic;
    double Score_Chemical;
    double Score_Overall;
    TypeRank Rank;
    
public:
    Student(std::string name, int age, TypeGender gender, double math, double physic, double chemical);

    void getID();
    void getInfo();
    void getScore();

    int readID();
    std::string readName();
    double readScoreOverall();

    void setInfo();
    void setScore();

    void addStudent(std::list <Student> &database);
    void updateInfo(std::list <Student> &database, int id);
    void deleteByID(std::list <Student> &database, int id);
    void searchByName(std::list <Student> &database, std::string name);

    void print(std::list <Student> &database);

};

#endif