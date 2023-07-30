/*
* File: student.cpp
* Author: Phan Hoang Trung
* Date: 30/07/2023
* Description: This is a file for function definition 
* 
*/


#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment1 - Student Management\Header\student.hpp"
#include <cassert>

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
Student::Student(std::string name = "Trung", int age = 24, TypeGender gender = Male, double score_math = 0, double score_physic = 0, double score_chemical = 0)
{
    
    Name = name;
    Age = age;
    Gender = gender;
    Score_Math = score_math;
    Score_Physic = score_physic;
    Score_Chemical = score_chemical;
    Score_Overall = (Score_Math + Score_Physic + Score_Chemical)  / 3;

    static int id = 230000;
    ID = id;
    id++;
}



/*
* Function: getID
* Description: This function will return student ID
* Input:
* Output:
*   ID - integer - student ID
*/
int Student::getID()
{
    return ID;
}


/*
* Function: getName
* Description: This function will return student name
* Input:
* Output:
*   Name - string - student name
*/
std::string Student::getName()
{
    return Name;
}

/*
* Function: setName
* Description: This function will set new name to student
* Input:
*   name - string - new name of student
* Output:
*/
void Student::setName(std::string name)
{
    Name = name;
}



/*
* Function: readScoreOverall
* Description: This function will return student overall score 
* Input:
* Output:
*   Score_Overall - double - student overall score
*/
double Student::getScoreOverall()
{
    return Score_Overall = (Score_Math + Score_Physic + Score_Chemical) / 3;
}




/*
* Function: getAge
* Description: This function will return student age
* Input:
* Output:
*   Age - int - student age, age is from 0 to 100
*/
int Student::getAge()
{
    return Age;
}


/*
* Function: setAge
* Description: This function will set new age to student
* Input:
*   age - integer - new age of student, age is from 0 to 100
* Output:
*/
void Student::setAge(int age)
{
    assert((age >= 0 && age <= 100) && "ERROR: Age is from 0 to 100");
    
    Age = age;
}


/*
* Function: getGender
* Description: This function will return student gender
* Input:
* Output:
*   Gender - TypeGender - student gender
*/
TypeGender Student::getGender()
{
    return Gender;
}


/*
* Function: setGender
* Description: This function will set new gender to student
* Input:
*   gender - TypeGender - new gender of student
* Output:
*/
void Student::setGender(TypeGender gender)
{
    assert((gender == Male || gender == Female) && "ERROR: gender is Male or Female" );
    Gender = gender;
}




/*
* Function: getScoreMath
* Description: This function will return student math score
* Input:
* Output:
*   Score_Math - double - student math score
*/
double Student::getScoreMath()
{
    return Score_Math;
}


/*
* Function: setScoreMath
* Description: This function will set new math score to student
* Input:
*   score_math - double - new math score of student, math_score is from 0 to 10
* Output:
*/
void Student::setScoreMath(double score_math)
{
    assert((score_math >= 0 && score_math <= 10) && "ERROR: Math score is from 0 to 10");
    Score_Math = score_math;
}



/*
* Function: getScorePhysic
* Description: This function will return student physic score
* Input:
* Output:
*   Score_Physic - double - student physic score
*/
double Student::getScorePhysic()
{
    return Score_Physic;
}


/*
* Function: setScorePhysic
* Description: This function will set new physic score to student
* Input:
*   score_physic - double - new physic score of student, physic_score is from 0 to 10
* Output:
*/
void Student::setScorePhysic(double score_physic)
{
    assert((score_physic >= 0 && score_physic <= 10) && "ERROR: Physic score is from 0 to 10");
    Score_Physic = score_physic;
}




/*
* Function: getScoreChemical
* Description: This function will return student chemical score
* Input:
* Output:
*   Score_Chemical - double - student chemical score
*/
double Student::getScoreChemical()
{
    return Score_Chemical;
}



/*
* Function: setScoreChemical
* Description: This function will set new chemical score to student
* Input:
*   score_chemical - double - new chemical score of student, chemical_score is from 0 to 10
* Output:
*/
void Student::setScoreChemical(double score_chemical)
{
    assert((score_chemical >= 0 && score_chemical <= 10) && "ERROR: Chemical score is from 0 to 10");
    Score_Chemical = score_chemical;
}


/*
* Function: getRank
* Description: This function will return student rank
* Input:
* Output:
*   Rank - TypeRank - student rank
*/
TypeRank Student::getRank()
{
    if (getScoreOverall() >= 8)
    {
        return Rank = Excellent;
    }
    else if (getScoreOverall() >= 6.5)
    {
        return Rank = Great;
    }
    else if (getScoreOverall() >= 5)
    {
        return Rank = Middle;
    }
    else
    {
        return Rank = Weak;
    }
}

/*
* Function: printInfo
* Description: This function will print student info
* Input:
* Output:
*/
void Student::printInfo()
{
    std::cout << "This is student " << Name << " Info: " << '\n';
    std::cout << "ID: " << ID << '\n';
    std::cout << "Age: " << Age << '\n';

    if (Gender == Male)
    {
        std::cout << "Gender: Male" << '\n';
    }
    else
    {
        std::cout << "Gender: Female" << '\n';
    }
    
    std::cout << "Math score: " << Score_Math << '\n';
    std::cout << "Physic score: " << Score_Physic << '\n';
    std::cout << "Chemical score: " << Score_Chemical << '\n';
    std::cout << "Overall: " << Score_Overall << '\n';

    getRank();
    switch (Rank)
    {
    case Excellent:
        std::cout << "Rank: Excellent" << '\n';
        break;
    case Great:
        std::cout << "Rank: Great" << '\n';
        break;
    case Middle:
        std::cout << "Rank: Middle" << '\n';
        break;
    case Weak:
        std::cout << "Rank: Weak" << '\n';
        break;

    default:
        break;
    }

}