#include "motionsensor.h"
#include <iostream>

MotionSensor::MotionSensor(std::string vendor)
{
    generateId();
    vendorName = vendor;
    std::cout << "Smoke Sensor constructor 1 called with Vendor  " << vendorName <<std::endl;
}


std::string MotionSensor::getSensorType() const
{
    return "Motion";
}
