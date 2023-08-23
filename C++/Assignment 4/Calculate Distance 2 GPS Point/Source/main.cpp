


#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 4\Calculate Distance 2 GPS Point\Header\gpspoint.hpp"


int main()
{
    GPSPoint point1;
    GPSPoint point2;
    while (1)
    {
        double latitude1, longitude1, latitude2, longitude2;
        do
        {
            std::cout << "Enter latitude point 1 in degree: " << '\n';
            std::cin >> latitude1;
            std::cout << "Enter longitude point 1 in degree: " << '\n';
            std::cin >> longitude1;
            point1.input(latitude1,longitude1);

        } while (!point1.isValid(latitude1,longitude1));

        do
        {
            std::cout << "Enter latitude point 2 in degree: " << '\n';
            std::cin >> latitude2;
            std::cout << "Enter longitude point 2 in degree: " << '\n';
            std::cin >> longitude2;
            point2.input(latitude2,longitude2);

        } while (!point2.isValid(latitude2,longitude2));
        
        std::cout << "Distance from point 1 to point 2 is: " << '\n'
                  <<  point1.distanceTo(point2)  << " kilometers. " << '\n';
        
    }
    
    return 0;
}