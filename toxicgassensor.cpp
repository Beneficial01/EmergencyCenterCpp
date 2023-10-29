#include "toxicgassensor.h"
#include <iostream>

ToxicGasSensor::ToxicGasSensor(std::string vendor, int gas, std::shared_ptr<Location> loc)
{
    generateId();
    vendorName = vendor;
    gasAmount = gas;
    location = loc;
    std::cout << "Gas Sensor constructor 1 called with Vendor  " << vendorName <<std::endl;
    std::cout << "in : " << (*location).toString() << std::endl;
}

std::string ToxicGasSensor::getSensorType() const
{
    return "Gas";
}
