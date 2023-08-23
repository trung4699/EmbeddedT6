


#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 4\DC Motor controller\Header\motorcontroller.hpp"

Motor_Controller::Motor_Controller(double voltage, double max_current, DC_Motor *motor, Feedback_System *feedback)
{
    Motor = motor;
    Feedback = feedback;
}

void Motor_Controller::setMotorDirection(Direction direction)
{
    (*Motor).setDirection(direction);
}

void Motor_Controller::setMotorSpeed(double speed)
{
    (*Motor).setSpeed(speed);
}

void Motor_Controller::controlMotor(Running_Status status)
{
    if (status == Running)
    {
        (*Motor).startRunning();
        checkStop();
    }

    else if (status == Stop)
    {
        (*Motor).stopRunning();
    }
    
}


bool Motor_Controller::checkFeedbackSystem()
{
   
    return  ((*Feedback).overheatDetected() || (*Feedback).overloadDetected());
    
}


void Motor_Controller::checkStop()
{
    if (checkFeedbackSystem())
    {
        controlMotor(Stop);
    }
    
}