#ifndef STUDENT_H
#define STUDENT_H

/*
* File: student.hpp
* Author: Phan Hoang Trung
* Date: 30/07/2023
* Description: This is a file include function declaration of student 
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
    Excellent = 1,
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
    Student(std::string name, int age, TypeGender gender, double score_math, double score_physic, double score_chemical);

    int getID();

    std::string getName();
    void setName(std::string name);

    int getAge();
    void setAge(int age);

    TypeGender getGender();
    void setGender(TypeGender gender);

    double getScoreMath();
    void setScoreMath(double score_math);

    double getScorePhysic();
    void setScorePhysic(double score_physic);

    double getScoreChemical();
    void setScoreChemical(double score_chemical);

    TypeRank getRank();

    double getScoreOverall();

    void printInfo();

    
};


#endif