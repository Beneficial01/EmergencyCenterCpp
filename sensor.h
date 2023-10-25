#ifndef SENSOR_H
#define SENSOR_H
#include "EmergencyCentreLib_global.h"
#include "service.h"
#include "space.h"
#include <vector>

class EMERGENCYCENTRELIB_EXPORT Sensor: Space
{
public:
    Sensor() = default;
    virtual ~Sensor() = default;
    void activate() const;
    void deactivate() const;
    bool trigger() const;
    void addService(Service & service );

private:
    int generateId();


    //attributes
    bool activated;
    std::string vendorName;
    int id;
    std::string startTime;
    std::string endTime;
    bool timerState;
    //std::shared_ptr<Location> location;
    std::vector<Service> services;
};


#endif // SENSOR_H
