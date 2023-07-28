#ifndef MAIN
#define MAIN

#include <iostream>
#include <string>

class Human
{
    protected:
    std::string Name;
    int Age;
    std::string Home_Address;

    public:

    Human(/* args */);
    ~Human();

    void print();
    void enterData(std::string name, int age, std::string address);
};

class Student : public Human
{
    private:
        int StudentID;

    public:
        Student();
        int getStudentID();
        //void print();
        void enterData(std::string name, int age, std::string address);

};




#endif