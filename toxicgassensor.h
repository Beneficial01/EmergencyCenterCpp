#ifndef TOXICGASSENSOR_H
#define TOXICGASSENSOR_H
#include "EmergencyCentreLib_global.h"
#include "sensor.h"



class EMERGENCYCENTRELIB_EXPORT ToxicGasSensor: public Sensor
{
public:
    ToxicGasSensor();
    ToxicGasSensor(std::string vendor, int gas, std::shared_ptr<Location> loc);
    std::string getSensorType() const override;

private:
    int gasAmount;
};

#endif // TOXICGASSENSOR_H
