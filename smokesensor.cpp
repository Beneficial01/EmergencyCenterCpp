#include "smokesensor.h"
#include <iostream>


SmokeSensor::SmokeSensor(std::string vendor, std::shared_ptr<Location> loc)
{
    generateId();
    vendorName = vendor;
    location = loc;

}
std::string SmokeSensor::getSensorType() const
{
    return "Smoke";
}
