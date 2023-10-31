#include "motionsensor.h"
#include <iostream>

MotionSensor::MotionSensor(std::string vendor, std::shared_ptr<Location> loc)
{
    generateId();
    vendorName = vendor;
    location = loc;

}


std::string MotionSensor::getSensorType() const
{
    return "Motion";
}
