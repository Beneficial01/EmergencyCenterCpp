#include "motionsensor.h"
#include <iostream>

MotionSensor::MotionSensor(std::string vendor, std::shared_ptr<Location> loc)
{
    generateId();
    vendorName = vendor;
    location = loc;
    std::cout << "Motion Sensor constructor 1 called with Vendor  " << vendorName <<std::endl;
    std::cout << "in : " << (*location).toString() << std::endl;
}


std::string MotionSensor::getSensorType() const
{
    return "Motion";
}
