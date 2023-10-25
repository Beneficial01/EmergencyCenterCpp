#ifndef SENSOR_H
#define SENSOR_H
#include "EmergencyCentreLib_global.h"
#include "service.h"
#include "space.h"
#include <vector>
#include <memory>

class EMERGENCYCENTRELIB_EXPORT Sensor: Space
{
public:
    //Sensor() = default;
    virtual ~Sensor() = default;
    virtual void activate();
    virtual void deactivate();
    virtual bool trigger() const;
    virtual std::string toString() const;
//    void addService(Service & service );
    void addService(std::shared_ptr<Service> service );
    int getSensorId() const;

private:
    //attributes
    bool activated;
    std::string vendorName;
    int sensorId;
    static int nextId;
    std::string startTime;
    std::string endTime;
    bool timerState;
    //std::shared_ptr<Location> location;
    //std::vector<Service> services;
    std::vector<std::shared_ptr<Service>> services;

protected:
    void generateId();
};

int Sensor::nextId = 1;

#endif // SENSOR_H
