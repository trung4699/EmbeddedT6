#ifndef FEEDBACK_SYSTEM_H
#define FEEDBACK_SYSTEM_H

#define HEAT_LIMITED 100
#define LOAD_LIMITED 100

class Feedback_System
{
private:
    double *Heat;
    double *Load;
public:
    Feedback_System(double *heat, double *load);
    bool overloadDetected();
    bool overheatDetected();
   
};




#endif