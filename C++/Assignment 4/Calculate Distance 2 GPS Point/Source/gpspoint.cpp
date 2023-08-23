




#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 4\Calculate Distance 2 GPS Point\Header\gpspoint.hpp"
#include <cmath>
#include <cassert>

GPSPoint::GPSPoint()
{
    Latitude = 0;
    Longitude = 0;
}

void GPSPoint::input(double latitude, double longitude)
{
    if (isValid(latitude,longitude))
    {
        Latitude = latitude;
        Longitude = longitude;
    }
    else
    {
        assert(isValid(latitude,longitude) && "Valus is not valid");
    }
}

bool GPSPoint::isValid(double latitude, double longitude)
{
    return (latitude >= -90 && latitude <= 90 && longitude >= - 180 && longitude <= 180);
}

void GPSPoint::toRadians()
{
    Latitude = Latitude * PI / 180.0;
    Longitude = Longitude * PI / 180.0;
}

double GPSPoint::getLatitude()
{
    return Latitude;
}

double GPSPoint::getLongitude()
{
    return Longitude;
}

double GPSPoint::distanceTo(GPSPoint gpspoint)
{
        
        double dLat = (Latitude - gpspoint.getLatitude())*PI / 180;
        double dLon = (Longitude - gpspoint.getLongitude())*PI/180;

        toRadians();
        gpspoint.toRadians();

        // apply formulae
        double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(Latitude) * cos(gpspoint.getLatitude());
        double c = 2 * asin(sqrt(a));
        return EARTH_RADIUS * c;
}