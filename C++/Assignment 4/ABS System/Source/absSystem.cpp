


#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 4\ABS System\Header\absSystem.hpp"
#include <cassert>

ABS_System::ABS_System(Car *car)
{
    ABS_System_Car = car;
}

bool ABS_System::isSpeedWheelUnderLimit()
{
    return ((*ABS_System_Car).getSpeed() < WHEEL_LIMIT_SPEED);
}


void ABS_System::brake()
{
    assert(!isSpeedWheelUnderLimit() && "Wheel are in danger of locking up");
}
