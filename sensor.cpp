#include "sensor.h"
#include <iostream>

//Sensor::Sensor() {

//}


void Sensor::activate()
{
    activated = true;
}

void Sensor::deactivate()
{
    activated = false;
}

bool Sensor::isTimeWithinBounds() const
{
    // Get current time
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);

    std::cout << "current time is " << (*timeinfo).tm_hour << ":" << (*timeinfo).tm_min << std::endl;

    // Convert all to minutes
    int currentTimeMinutes = (*timeinfo).tm_hour * 60 + (*timeinfo).tm_min;
    int startTimeMinutes = startTime.tm_hour * 60 + startTime.tm_min;
    int endTimeMinutes = endTime.tm_hour * 60 + endTime.tm_min;
    return (currentTimeMinutes >= startTimeMinutes) && (currentTimeMinutes <= endTimeMinutes);
}


// remember to refactor this in the space interface and everywhere else

void Sensor::trigger() const
{
    for (auto& service : services) {
        if (this->getActivated() && (!isTimeDependent() || isTimeWithinBounds())) {
            service->update(this->getSensorType(), this->getSensorId());
        }
    }
}

std::string Sensor::toString() const
{
    return "Sensor Type: " + getSensorType() + ", Vendor: " + vendorName;
}

void Sensor::addService(std::shared_ptr<Service> service){
    services.push_back(service);
}


void Sensor::generateId()
{
    sensorId = nextId;
    nextId++;
}

std::string Sensor::getLocation() const
{
    return location->getSpaceName();
}



int Sensor::getSensorId() const
{
    return sensorId;
}

std::string Sensor::getVendorName() const
{
    return vendorName;
}

bool Sensor::getActivated() const
{
    return activated;
}


std::string Sensor::getStartTime() const
{
    return std::to_string(startTime.tm_hour) + ":" + std::to_string(startTime.tm_min);
}

void Sensor::setStartTime(const int hour, const int min)
{
    startTime.tm_hour = hour;
    startTime.tm_min = min;
}

std::string Sensor::getEndTime() const
{
    return std::to_string(endTime.tm_hour) + ":" + std::to_string(endTime.tm_min);
}

void Sensor::setTimeDependent(bool state)
{
    timeDependent = state;
}

bool Sensor::isTimeDependent() const
{
    return timeDependent;
}


void Sensor::setEndTime(const int hour, const int min)
{
    endTime.tm_hour = hour;
    endTime.tm_min = min;
}

