#include "sensor.h"
#include <chrono>
#include <ctime>

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
    // Get the current time.
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    // Convert the start and end times to std::tm.
    std::tm tm_start = {};
    std::tm tm_end = {};
    strptime(startTime.c_str(), "%H:%M:%S", &tm_start);
    strptime(endTime.c_str(), "%H:%M:%S", &tm_end);

    // Convert the std::tm times to std::chrono time_points.
    std::chrono::system_clock::time_point start_time = std::chrono::system_clock::from_time_t(std::mktime(&tm_start));
    std::chrono::system_clock::time_point end_time = std::chrono::system_clock::from_time_t(std::mktime(&tm_end));

    // Check if the current time is within the active interval.
    return now >= start_time && now <= end_time;
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

bool Sensor::getTimerState() const
{
    return timerState;
}

std::string Sensor::getStartTime() const
{
    return startTime;
}

void Sensor::setStartTime(const std::string &newStartTime)
{
    startTime = newStartTime;
}

std::string Sensor::getEndTime() const
{
    return endTime;
}

void Sensor::setTimeDependent(bool state) const
{
    isTimeDependent = state;
}

bool Sensor::isTimeDependent() const
{
    return isTimeDependent;
}


void Sensor::setEndTime(const std::string &newEndTime)
{
    endTime = newEndTime;
}

