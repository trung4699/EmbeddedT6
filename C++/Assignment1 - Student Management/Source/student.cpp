


#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment1 - Student Management\Header\student.hpp"

#include <algorithm>

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

void Student::getID()
{
    std::cout << "ID: " << ID << '\n';
}

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

void Student::getScore()
{
    std::cout << "Student " << Name << " has scores: " << '\n';
    std::cout << "Math score: " << Score_Math << '\n';
    std::cout << "Physic score: " << Score_Physic << '\n';
    std::cout << "Chemical score: " << Score_Chemical << '\n';
    std::cout << "Overall: " << Score_Overall << '\n';
    std::cout << '\n';
}

int Student::readID()
{
    return ID;
}

std::string Student::readName()
{
    return Name;
}

double Student::readScoreOverall()
{
    return Score_Overall;
}

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

void Student::addStudent(std::list <Student> &database)
{
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
    
    Student newStudent(Name, Age, Gender, Score_Math, Score_Physic, Score_Chemical);

    database.push_back(newStudent);

}

void Student::updateInfo(std::list <Student> &database, int id)
{
    std::list<Student> ::iterator it;

    bool checkID = 1;

    std::cout << "Checking ID ... " << '\n';
    
    for (it = database.begin(); it != database.end(); it++)
    {
        if ((*it).readID() == id)
        {
            std::cout << "Update info for student ID " << id << '\n';
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
