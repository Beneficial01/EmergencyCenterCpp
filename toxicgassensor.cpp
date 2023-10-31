#include "toxicgassensor.h"
#include <iostream>

ToxicGasSensor::ToxicGasSensor(std::string vendor, int gas, std::shared_ptr<Location> loc)
{
    generateId();
    vendorName = vendor;
    gasAmount = gas;
    location = loc;
}

std::string ToxicGasSensor::getSensorType() const
{
    return "Gas";
}
