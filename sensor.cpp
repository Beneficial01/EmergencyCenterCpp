#include "sensor.h"

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

// remember to refactor this in the space interface and everywhere else

bool Sensor::trigger() const
{

    for(auto& service : services){
        service->update();
    }
    return true;

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

void Sensor::setEndTime(const std::string &newEndTime)
{
    endTime = newEndTime;
}

