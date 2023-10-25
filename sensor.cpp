#include "sensor.h"

//Sensor::Sensor() {

//}


void Sensor::addService(std::shared_ptr<Service> service)
{
    services.push_back(service);
}

int Sensor::generateId()
{
    id = nextId;
    nextId++;

    return id;
}

