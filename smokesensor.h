#ifndef SMOKESENSOR_H
#define SMOKESENSOR_H
#include "EmergencyCentreLib_global.h"
#include "sensor.h"
#include "location.h"



class EMERGENCYCENTRELIB_EXPORT SmokeSensor: public Sensor
{
public:
    SmokeSensor();
    SmokeSensor(std::string vendor, std::shared_ptr<Location> loc);
    std::string getSensorType() const override;

};

#endif // SMOKESENSOR_H
