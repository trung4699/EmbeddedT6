
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Lesson 1 - Class\Header\main.hpp"

Object::Object()
{
    static int id = 0;
    ptr = &id;
    ID = id;
    id++;
}

Object::~Object()
{
    *ptr = 100;
}   

void Object::enterData(std::string name, int age, std::string gender)
{
    Name = name;
    Age = age;
    Gender = gender;
}

void Object::print()
{
    std::cout << "Name: " << Name << '\n';
    std::cout << "Age: "<< Age << '\n';
    std::cout << "Gender: " << Gender << '\n';
    std::cout << "ID: " << ID << '\n';
}

int Object::static_var; // initialize static_var of object first

void test1(std::string name, int age, std::string gender)
{
    Object test;
    test.enterData(name,age,gender);
    test.print();
}


int main()
{
    Object Test1;
    Object Test2;
    Object Test3;
    Test1.enterData("Trung", 24, "Male");
    Test1.print();

    Test2.enterData("Trung2", 25,"F");
    Test2.print();

    Test3.enterData("Trung3",26,"M");
    Test3.print();

    test1("T", 24, "M");
    test1("T", 25, "M");
    test1("T", 26, "M");

    printf("Address of dt.var: %p\n",&Test1.var);
    printf("Address of dt1.var: %p\n",&Test2.var);
    printf("Address of dt2.var: %p\n",&Test3.var);


    printf("Address of dt.static_var: %p\n",&Test1.static_var);
    printf("Address of dt1.static_var: %p\n",&Test2.static_var);
    printf("Address of dt2.static_var: %p\n",&Test3.static_var);

    return 0;
}