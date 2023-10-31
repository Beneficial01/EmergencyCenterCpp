#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H
#include "EmergencyCentreLib_global.h"
#include "sensor.h"

class EMERGENCYCENTRELIB_EXPORT MotionSensor: public Sensor
{
public:
    MotionSensor();
    MotionSensor(std::string vendor, std::shared_ptr<Location> loc);
    std::string getSensorType() const override;

    void setDistance(int newDistance);

private:
    int distance {};

};
#endif // MOTIONSENSOR_H
