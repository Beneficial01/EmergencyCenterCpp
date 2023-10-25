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

int Sensor::getSensorId() const
{
    return sensorId;
}



void Sensor::generateId()
{
    sensorId = nextId;
    nextId++;
}

std::string Sensor::getVendorName() const
{
    return vendorName;
}

