#include "toxicgassensor.h"
#include <iostream>

ToxicGasSensor::ToxicGasSensor(std::string vendor, int gas)
{
    generateId();
    vendorName = vendor;
    gasAmount = gas;
    std::cout << "Gas Sensor constructor 1 called with Vendor  " << vendorName <<std::endl;
}

std::string ToxicGasSensor::getSensorType() const
{
    return "Gas";
}
