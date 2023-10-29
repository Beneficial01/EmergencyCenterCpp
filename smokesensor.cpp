#include "smokesensor.h"
#include <iostream>


SmokeSensor::SmokeSensor(std::string vendor, std::shared_ptr<Location> loc)
{
    generateId();
    vendorName = vendor;
    location = loc;
    std::cout << "Smoke Sensor constructor 1 called with Vendor  " << vendorName << std::endl;
    std::cout << "in location : " << location << std::endl;
}
std::string SmokeSensor::getSensorType() const
{
    return "Smoke";
}
