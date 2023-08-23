#ifndef DC_MOTOR_H
#define DC_MOTOR_H

#include <iostream>


typedef enum {
    Clockwise,
    Counter_Clockwise

} Direction;


typedef enum {
    Running,
    Stop
} Running_Status;


class DC_Motor
{
private:
    double Voltage;
    double Max_Current;
    double Speed;
    Direction Motor_Direction;
    Running_Status Motor_Status;

public:
    DC_Motor(double voltage, double max_current);

    void setSpeed(double speed);
    void setDirection(Direction motor_direction);
    void startRunning();
    void stopRunning();
    bool isRunning();
    
};



#endif