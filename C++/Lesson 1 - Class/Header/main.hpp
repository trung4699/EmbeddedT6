#include <iostream>
#include <string>


class Object
{
private:
    std::string Name;
    int Age;
    std::string Gender;
    int ID;
    int *ptr;
public:
    Object(); // Conductor: to initialize an object with default value
   
    ~Object(); // Deductor: before deallocated an object, the program will run deductor


    void enterData(std::string name, int age, std::string gender);


    void print();

    int var;
    static int static_var;
};