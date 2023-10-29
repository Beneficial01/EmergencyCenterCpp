#ifndef TOXICGASSENSOR_H
#define TOXICGASSENSOR_H
#include "EmergencyCentreLib_global.h"
#include "sensor.h"



class EMERGENCYCENTRELIB_EXPORT ToxicGasSensor: public Sensor
{
public:
    ToxicGasSensor();
    ToxicGasSensor(std::string vendor, int gas);
    std::string getSensorType() const override;

private:
    int gasAmount;
};

#endif // TOXICGASSENSOR_H
