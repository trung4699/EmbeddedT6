
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 4\ABS System\Header\absSystem.hpp"
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 4\ABS System\Header\car.hpp"
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 4\ABS System\Header\wheel.hpp"

int main()
{
    Car car;
    ABS_System abs_system(&car);

    // set up
    int wheel_speed;
    std::cout << "Set wheel speed: " << '\n';
    std::cin >> wheel_speed;
    car.setSpeed(wheel_speed);

    abs_system.brake();

    double customer_weight;
    std::cout << "Enter customer weight to add to car: " << '\n';
    std::cin >> customer_weight;

    car.addCustomer(customer_weight);

    // loop
    while (1)
    {
        std::cout << "Set wheel speed: " << '\n';
        std::cin >> wheel_speed;
        car.setSpeed(wheel_speed);
        
        abs_system.brake();
    }
    

    return 0;
}