#include "sensor.h"
#include <iostream>


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
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    std::cout << "current time is " << timeinfo->tm_hour << ":" << timeinfo->tm_min << std::endl;

    // Convert all to minutes
    int currentTimeMinutes = timeinfo->tm_hour * 60 + timeinfo->tm_min;
    int startTimeMinutes = startTime.tm_hour * 60 + startTime.tm_min;
    int endTimeMinutes = endTime.tm_hour * 60 + endTime.tm_min;

    if (endTimeMinutes < startTimeMinutes) {
        // The end time is on the next day, handle the wrap-around
        return (currentTimeMinutes >= startTimeMinutes) || (currentTimeMinutes <= endTimeMinutes);
    } else {
        return (currentTimeMinutes >= startTimeMinutes) && (currentTimeMinutes <= endTimeMinutes);
    }
}



void Sensor::trigger() const
{
    for (auto& service : services) {
        if (this->getActivated() && (!isTimeDependent() || isTimeWithinBounds())) {
            service->update(this->getSensorType(), location->getSpaceName());
        }
    }
}

std::string Sensor::toString() const
{
    std::string ret;
    ret = "Sensor Type: " + getSensorType() + "\n" + "Vendor: " + vendorName + "\n"
          + "Location: " + location->getSpaceName() + "\n"
          + "Sensor ID: " + std::to_string(sensorId);
    if(isTimeDependent()){
        ret += "\n";
        ret += "Activate start time: " + getStartTime();
        ret += "\n";
        ret += "Activate end time: " + getEndTime();
    }
    else{
        ret += "\nSensor activation is time independent";
    }

    return ret;
}

Sensor &Sensor::operator++()
{
    activated = true;
    return *this;
}

Sensor &Sensor::operator--()
{
    activated = false;
    return *this;
}


std::ostream &operator<<(std::ostream &os, const Sensor &s)
{
    os << "Sensor Overview:" <<std::endl << s.toString() << std::endl;
    return os;
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

