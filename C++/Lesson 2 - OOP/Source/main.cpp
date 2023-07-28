
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Lesson 2 - OOP\Header\main.hpp"

Human::Human() // Conductor
{

}

Human::~Human() // Deductor
{

}

void Human::enterData(std::string name, int age, std::string address)
{
    Name = name;
    Age = age;
    Home_Address = address;
}

void Human::print()
{
    std::cout << "Name: " << Name << '\n';
    std::cout << "Age: " << Age << '\n';
    std::cout << "Home Address: " << Home_Address << '\n';
}

Student::Student()
{
    
    static int id = 10;
    StudentID = id;
    id++;
}

int Student::getStudentID()
{
    return StudentID;
}


void Student::enterData(std::string name, int age, std::string address)
{
    Name = name;
    Age = age;
    Home_Address = address;
}

/*void Student::print()
{
    std::cout << "Name: " << Name << '\n';
    std::cout << "Age: " << Age << '\n';
    std::cout << "Home Address: " << Home_Address << '\n';
    std::cout << "Student ID: " << StudentID << '\n';
}*/

int main()
{
    Human people1;
    Student student1;
    Student student2;

    people1.enterData("Trung", 24, "Q10");
    people1.print();

    student1.enterData("T",25,"Q11"); // ke thua
    student1.print();

    student2.enterData("A",20,"Q12");
    student2.print();

  

    return 0;
}