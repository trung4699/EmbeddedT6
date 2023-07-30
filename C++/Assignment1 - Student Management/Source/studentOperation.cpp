
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment1 - Student Management\Header\studentOperation.hpp"
#include <cassert>
/*
* Function: addStudent
* Description: This function will add a new student to a list, info and score of new student will get from keyboard
* Input:
*   database - address of fisrt node in a list, has datatype Student - pass by reference 
* Output:
*   a list with new student 
*/
void addStudent(std::list <Student> &database)
{
    // Get student info and score from keyboard
    std::string name;
    int age;
    TypeGender Gender;
    double score_math, score_physic, score_chemical;

    std::cout << "Enter student info: " << '\n';
    std::cout << "Name: " << '\n';
    std::cin >> name;
    
    do
    {
        std::cout << "Age: " << '\n';
        std::cin >> age;
        assert((age >= 0 && age <= 100) && "ERROR: Age is from 0 to 100");
    } while (age < 0 || age > 100);

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

        assert((gender == 0 || gender == 1) && "ERROR: Gender is 0 or 1");
        
    } while (gender != 0 && gender != 1);
    
    do
    {
        std::cout << "Math score: " << '\n';
        std::cin >> score_math;

        assert((score_math >= 0 && score_math <= 10) && "ERROR: Math score is from 0 to 10");

    } while (score_math < 0 || score_math > 10);

    do
    {
        std::cout << "Physic score: " << '\n';
        std::cin >> score_physic;

        assert((score_physic >= 0 && score_physic <= 10) && "ERROR: Physic score is from 0 to 10");
    } while (score_physic < 0 || score_physic > 10);

    do
    {
        std::cout << "Chemical score: " << '\n';
        std::cin >> score_chemical;

        assert((score_chemical >= 0 && score_chemical <= 10) && "ERROR: Chemical score is from 0 to 10");
    } while (score_chemical < 0 || score_chemical > 10);
    
    // create a new student with info and score have from keyboard
    Student newStudent(name, age, Gender, score_math, score_physic, score_chemical);


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
void updateInfo(std::list <Student> &database, int id)
{
    std::list<Student> ::iterator it;

    bool checkID = 1;

    std::cout << "Checking ID ... " << '\n';
    
    for (it = database.begin(); it != database.end(); it++)
    {
        if ((*it).getID() == id)
        {
            std::cout << "Update info for student ID " << id << "." <<'\n';

            int checkChoose = -1;
            bool checkDone;

            do
            {
                do
                {
                    std::cout << "Please choose info you want to update: " << '\n';
                    std::cout << "0 for Name" << '\n';
                    std::cout << "1 for Age" << '\n';
                    std::cout << "2 for Gender" << '\n';
                    std::cout << "3 for Math score" << '\n';
                    std::cout << "4 for Physic score" << '\n';
                    std::cout << "5 for Chemical score" << '\n';

                    std::cin >> checkChoose;
                } while (checkChoose != 0 && checkChoose != 1 && checkChoose != 2 && checkChoose != 3 && checkChoose != 4 && checkChoose != 5);
                

                if (checkChoose == 0)
                {
                 std::string new_name;
                 std::cout << "Enter your new name: " << '\n';
                 std::cin >> new_name;
                 (*it).setName(new_name);
                }

                else if (checkChoose == 1)
                {
                    int new_age;
                    std::cout << "Enter your new age: " << '\n';
                    std::cin >> new_age;
                
                    (*it).setAge(new_age);
                }
            
                else if (checkChoose == 2)
                {
                    int num_gender;
                    TypeGender new_gender;

                    do
                    {
                        std::cout << "Enter your new gender: 0 for Male/ 1 for Female" << '\n';
                        std::cin >> num_gender;
                    } while (num_gender != 0 && num_gender != 1);
                
                    if (num_gender == 0)
                    {
                        new_gender = Male;
                    }
                    else
                    {
                        new_gender = Female;
                    }

                    (*it).setGender(new_gender);
                }
            
                else if (checkChoose == 3)
                {
                    double score_math;
                    std::cout << "Enter your new math score: " << '\n';
                    std::cin >> score_math;
                    (*it).setScoreMath(score_math);
                }

                else if (checkChoose == 4)
                {
                    double score_physic;
                    std::cout << "Enter your new physic score: " << '\n';
                    std::cin >> score_physic;
                    (*it).setScoreMath(score_physic);
                }

                else if (checkChoose == 5)
                {
                    double score_chemical;
                    std::cout << "Enter your new chemical score: " << '\n';
                    std::cin >> score_chemical;
                    (*it).setScoreMath(score_chemical);
                }

                std::cout << "Do you want to update any info else ? 1 for yes/ 0 for no" ;
                std::cin >> checkDone;

            
            } while (checkDone);
            
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
void deleteByID(std::list <Student> &database, int id)
{
    std::list<Student> ::iterator it;


    bool checkID = 1;

    std::cout << "Checking ID ... " << '\n';
    
    for (it = database.begin(); it != database.end(); ++it)
    {
        if ((*it).getID() == id)
        {
            std::cout << "Delete student ID " << id << '\n';
            database.erase(it);
            checkID = 0;
        }
    }

    if (checkID)
    {
        std::cout << "ID unfound" << '\n';
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
void searchByName(std::list <Student> &database)
{
    std::list<Student> ::iterator it;

    std::cout << "Enter name you want to search: " << '\n';
    std::string name;
    std::cin >> name;

    bool checkName = 1;
    int count_name = 0;

    std::cout << "Checking Name ... " << '\n';
    
    for (it = database.begin(); it != database.end(); it++)
    {
        if ((*it).getName() == name)
        {
            std::cout << "Student found: " << '\n';
            std::cout << "ID: " << (*it).getID() << '\n';
            
            count_name++;
        }
    }

    if (count_name != 0)
    {
        checkName = 0;
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
void print(std::list <Student> &database)
{
    std::list <Student> ::iterator it;

    for ( it = database.begin(); it != database.end(); it++)
    {
        (*it).printInfo();
        std::cout << '\n';
    }
}


void swap(std::list <Student> ::iterator *student1, std::list <Student> ::iterator *student2)
{
    std::list <Student> ::iterator temp = *student1;
    (*(*student1)) = (*(*student2));
    (*(*student2)) = (*temp);
}


void sortByGPA(std::list <Student> &database)
{

    std::list <Student> ::iterator i;
    std::list <Student> ::iterator j;
    
    i = database.begin();
    std::cout << (*i).getName() << '\n';
    j = ++i;
    std::cout << (*j).getName() << '\n';
    swap(&i , &j);
}



/*
* Function: sortByGPA
* Description: This function will sort the list ascending by student GPA
* Input:
*   database - address of fisrt node in a list, has datatype Student - pass by reference
* Output:
*/



/*
* Function: sortByName
* Description: This function will sort the list ascending by student name
* Input:
*   database - address of fisrt node in a list, has datatype Student - pass by reference
* Output:
*/
void sortByName(std::list <Student> &database)
{
    database.sort([](Student &a, Student &b) -> bool{return a.getName() < b.getName() ;});
}