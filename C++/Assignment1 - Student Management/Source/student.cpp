/*
* File: student.cpp
* Author: Phan Hoang Trung
* Date: 29/07/2023
* Description: This is a main file for program student management assignment
* 
*/


#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment1 - Student Management\Header\student.hpp"

#include <algorithm>

/*
* Function: Student()
* Description: This is a conductor of Student class
* Input:
*   name - string - student name 
*   age - integer - student age
*   gender - TypeGender - student gender
*   math - double - student math score
*   physic - double - student physic score
*   chemical - double - student chemical score
* Output:
*   
*/
Student::Student(std::string name = "Trung", int age = 24, TypeGender gender = Male, double math = 0, double physic = 0, double chemical = 0)
{
    
    Name = name;
    Age = age;
    Gender = gender;
    Score_Math = math;
    Score_Physic = physic;
    Score_Chemical = chemical;
    Score_Overall = (Score_Math + Score_Physic + Score_Chemical)  / 3;

    static int id = 230000;
    ID = id;
    id++;
}


/*
* Function: getID
* Description: This function will print ID of student
* Input:
* Output:
*/
void Student::getID()
{
    std::cout << "ID: " << ID << '\n';
}

/*
* Function: getInfo
* Description: This function will print info of student: name, age, gender
* Input:
* Output:
*/
void Student::getInfo()
{
    std::cout << "This is Student " << Name << '\n';
    std::cout << "Age: " << Age << '\n';
    switch (Gender)
    {
    case 0:
        std::cout << "Gender: Male" << '\n';
        break;
    case 1:
        std::cout << "Gender: Female" << '\n';
        break;
    default:
        break;
    }
}



/*
* Function: getScore
* Description: This function will print student score: math, physic, chemical and overall
* Input:
* Output:
*/
void Student::getScore()
{
    std::cout << "Student " << Name << " has scores: " << '\n';
    std::cout << "Math score: " << Score_Math << '\n';
    std::cout << "Physic score: " << Score_Physic << '\n';
    std::cout << "Chemical score: " << Score_Chemical << '\n';
    std::cout << "Overall: " << Score_Overall << '\n';
    std::cout << '\n';
}

/*
* Function: readID
* Description: This function will return ID of student
* Input:
* Output:
*   ID - integer - student ID
*/
int Student::readID()
{
    return ID;
}


/*
* Function: readName
* Description: This function will return student name
* Input:
* Output:
*   Name - string - student name
*/
std::string Student::readName()
{
    return Name;
}



/*
* Function: readScoreOverall
* Description: This function will return student overall score 
* Input:
* Output:
*   Score_Overall - double - student overall score
*/
double Student::readScoreOverall()
{
    return Score_Overall;
}


/*
* Function: setInfo
* Description: This function will overwrite student info from keyboard, student info include: name, age, gender
* Input:
* Output:
*/
void Student::setInfo()
{
    std::string name;
    int age;
    
    std::cout << "Name: " << '\n';
    std::cin >> name;
    
    do
    {
        std::cout << "Age: " << '\n';
        std::cin >> age;
        if (age < 18 || age > 25)
        {
            std::cout << "Age is not suitable, please try again" << '\n';
        }
        
    } while (age < 18 || age > 25);

    int gender;
    do
    {
        std::cout << "Gender: 0 - Male/ 1 - Female" << '\n';
        std::cin >> gender;
        if (gender != 0 && gender != 1)
        {
            std::cout << "Wrong number, enter 0 for Male, 1 for Female." << '\n';
        }
        
    } while (gender != 0 && gender != 1);

    Name = name;
    Age = age;
    if (gender == 0)
        {
            Gender = Male;
        }
    if (gender == 1)
        {
            Gender = Female;
        }
}




/*
* Function: setScore
* Description: This function will overwrite student score from keyboard, student score include: math, physic, chemical
* Input:
* Output:
*/
void Student::setScore()
{
    int math, physic, chemical;
    do
    {
        std::cout << "Math score: " << '\n';
        std::cin >> math;

        if (math < 0 || math > 10)
        {
            std::cout << "Math score is not suitable, please try again" << '\n';
        }
        
    } while (math < 0 || math > 10);

    do
    {
        std::cout << "Physic score: " << '\n';
        std::cin >> physic;

        if (physic < 0 || physic > 10)
        {
            std::cout << "Physic score is not suitable, please try again" << '\n';
        }
    } while (physic < 0 || physic > 10);

    do
    {
        std::cout << "Chemical score: " << '\n';
        std::cin >> chemical;

        if (chemical < 0 || chemical > 10)
        {
            std::cout << "Chemical score is not suitable, please try again" << '\n';
        }
    } while (chemical < 0 || chemical > 10);

    Score_Math = math;
    Score_Physic = physic;
    Score_Chemical = chemical;

    Score_Overall = (Score_Math + Score_Physic + Score_Chemical) / 3;
}



/*
* Function: addStudent
* Description: This function will add a new student to a list, info and score of new student will get from keyboard
* Input:
*   database - address of fisrt node in a list, has datatype Student - pass by reference 
* Output:
*   a list with new student 
*/
void Student::addStudent(std::list <Student> &database)
{
    // Get student info and score from keyboard
    std::cout << "Enter student info: " << '\n';
    
    std::cout << "Name: " << '\n';
    std::cin >> Name;
    
    do
    {
        std::cout << "Age: " << '\n';
        std::cin >> Age;
        if (Age < 18 || Age > 25)
        {
            std::cout << "Age is not suitable, please try again" << '\n';
        }
    } while (Age < 18 || Age > 25);

    int gender;
    do
    {
        std::cout << "Gender: 0 - Male/ 1 - Female" << '\n';
        std::cin >> gender;
        if (gender == 0)
        {
            Gender = Male;
        }
        if (gender == 1)
        {
            Gender = Female;
        }

        if (gender != 0 && gender != 1)
        {
            std::cout << "Wrong number, enter 0 for Male, 1 for Female." << '\n';
        }
        
    } while (gender != 0 && gender != 1);
    
    do
    {
        std::cout << "Math score: " << '\n';
        std::cin >> Score_Math;

        if (Score_Math < 0 || Score_Math > 10)
        {
            std::cout << "Math score is not suitable, please try again" << '\n';
        }

    } while (Score_Math < 0 || Score_Math > 10);

    do
    {
        std::cout << "Physic score: " << '\n';
        std::cin >> Score_Physic;

        if (Score_Physic < 0 || Score_Physic > 10)
        {
            std::cout << "Physic score is not suitable, please try again" << '\n';
        }
    } while (Score_Physic < 0 || Score_Physic > 10);

    do
    {
        std::cout << "Chemical score: " << '\n';
        std::cin >> Score_Chemical;

        if (Score_Chemical < 0 || Score_Chemical > 10)
        {
            std::cout << "Chemical score is not suitable, please try again" << '\n';
        }
    } while (Score_Chemical < 0 || Score_Chemical > 10);
    
    // create a new student with info and score have from keyboard
    Student newStudent(Name, Age, Gender, Score_Math, Score_Physic, Score_Chemical);


    // add that student at the end of the list
    database.push_back(newStudent);

}



/*
* Function: updateInfo
* Description: This function will update info and score of a student by ID
* Input:
*   id - an integer value - id of student you want to update info 
*   database - address of fisrt node in a list, has datatype Student - pass by reference
* Output:
*/
void Student::updateInfo(std::list <Student> &database, int id)
{
    std::list<Student> ::iterator it;

    bool checkID = 1;

    std::cout << "Checking ID ... " << '\n';
    
    for (it = database.begin(); it != database.end(); it++)
    {
        if ((*it).readID() == id)
        {
            std::cout << "Update info and score for student ID " << id << '\n';
            (*it).setInfo();
            (*it).setScore();
            checkID = 0;
        }
    }

    if (checkID)
    {
        std::cout << "ID unfound" << '\n';
    }
    
}





/*
* Function: deleteByID
* Description: This function will delete a student from a list by ID
* Input:
*   id - an integer value - id of student you want to update info 
*   database - address of fisrt node in a list, has datatype Student - pass by reference
* Output:
*/
void Student::deleteByID(std::list <Student> &database, int id)
{
    std::list<Student> ::iterator it;

    std::list<Student> ::iterator ptr;

    bool checkID = 1;

    std::cout << "Checking ID ... " << '\n';
    
    for (it = database.begin(); it != database.end(); it++)
    {
        if ((*it).readID() == id)
        {
            ptr = it;
            checkID = 0;
        }
    }

    if (checkID)
    {
        std::cout << "ID unfound" << '\n';
    }
    else
    {
        std::cout << "Delete student ID " << id << '\n';
        database.erase(ptr);
    }
}




/*
* Function: searchByName
* Description: This function will search to check if there is any student have the same name with name input
* Input:
*   name - a string value - name of student you want to check
*   database - address of fisrt node in a list, has datatype Student - pass by reference
* Output:
*/
void Student::searchByName(std::list <Student> &database, std::string name)
{
    std::list<Student> ::iterator it;

    bool checkName = 1;

    std::cout << "Checking Name ... " << '\n';
    
    for (it = database.begin(); it != database.end(); it++)
    {
        if ((*it).readName() == name)
        {
            std::cout << "Student found: " << '\n';
            (*it).getID();
            (*it).getInfo();
            (*it).getScore();
            checkName = 0;
        }
    }

    if (checkName)
    {
        std::cout << "Student unfound" << '\n';
    }
}


/*
* Function: print
* Description: This function will print info and score of every student in the list
* Input:
*   database - address of fisrt node in a list, has datatype Student - pass by reference
* Output:
*/
void Student::print(std::list <Student> &database)
{
    std::list <Student> ::iterator it;

    for ( it = database.begin(); it != database.end(); it++)
    {
        (*it).getID();
        (*it).getInfo();
        (*it).getScore();
    }
    
}




/*
* Function: sortByGPA
* Description: This function will sort the list ascending by student GPA
* Input:
*   database - address of fisrt node in a list, has datatype Student - pass by reference
* Output:
*/
void Student::sortByGPA(std::list <Student> &database)
{
    database.sort([](Student &a, Student &b) -> bool{return a.readScoreOverall() < b.readScoreOverall() ;});
}



/*
* Function: sortByName
* Description: This function will sort the list ascending by student name
* Input:
*   database - address of fisrt node in a list, has datatype Student - pass by reference
* Output:
*/
void Student::sortByName(std::list <Student> &database)
{
    database.sort([](Student &a, Student &b) -> bool{return a.readName() < b.readName() ;});
}