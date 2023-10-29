#include "smokesensor.h"
#include <iostream>


SmokeSensor::SmokeSensor(std::string vendor)
{
    generateId();
    vendorName = vendor;
    std::cout << "Smoke Sensor constructor 1 called with Vendor  " << vendorName <<std::endl;
}
std::string SmokeSensor::getSensorType() const
{
    return "Smoke";
}
