#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H


#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 4\DC Motor controller\Header\motor.hpp"
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 4\DC Motor controller\Header\feedback.hpp"


class Motor_Controller
{
private:
    DC_Motor *Motor;
    Feedback_System *Feedback;
public:
    Motor_Controller(double voltage, double max_current, DC_Motor *motor, Feedback_System *feedback);
    

    void controlMotor(Running_Status status);
    void setMotorDirection(Direction direction);
    void setMotorSpeed(double speed);

    bool checkFeedbackSystem();

    void checkStop();
    
};




#endif