#ifndef SMOKESENSOR_H
#define SMOKESENSOR_H
#include "EmergencyCentreLib_global.h"
#include "sensor.h"



class EMERGENCYCENTRELIB_EXPORT SmokeSensor: Sensor
{
public:
    SmokeSensor();
    SmokeSensor(std::string vendor);
    std::string getSensorType() const override;

};

#endif // SMOKESENSOR_H
