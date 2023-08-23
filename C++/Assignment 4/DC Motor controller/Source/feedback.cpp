


#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 4\DC Motor controller\Header\feedback.hpp"

Feedback_System::Feedback_System(double *heat, double *load)
{
    Heat = heat;
    Load = load;
}

bool Feedback_System::overheatDetected()
{
    return ((*Heat) > HEAT_LIMITED);
}

bool Feedback_System::overloadDetected()
{
    return ((*Load) > LOAD_LIMITED);
}