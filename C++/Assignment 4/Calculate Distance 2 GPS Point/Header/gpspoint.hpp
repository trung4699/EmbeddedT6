#ifndef GPSPOINT_H
#define GPSPOINT_H

#define EARTH_RADIUS 6371
#define PI 3.14

#include <iostream>

class GPSPoint
{
private:
    double Latitude;
    double Longitude;
public:
    GPSPoint();
    void input(double latitude, double longitude);
    bool isValid(double latitude, double longitude);
    double getLatitude();
    double getLongitude();
    void toRadians();
    double distanceTo(GPSPoint gpspoint);
};



#endif