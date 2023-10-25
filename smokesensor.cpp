#include "smokesensor.h"


SmokeSensor::SmokeSensor(std::string vendor)
{
    generateId();
    vendorName = vendor;

}

std::string SmokeSensor::getSensorType() const
{
    return "Smoke";
}
