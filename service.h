#ifndef SERVICE_H
#define SERVICE_H

#include "EmergencyCentreLib_global.h"
#include <string>

/**
 * @brief The Service class is an interface to be implemented by any service you wish to add to a sensor
 */
class EMERGENCYCENTRELIB_EXPORT Service
{
public:
    Service() = default;
    virtual ~Service() = default;
    /**
     * @brief update - called by a sensor to alert the service
     * @param sensorType - type of sensor calling the alert
     * @param location - location of the sensor calling the alert
     */
    virtual void update(std::string sensorType, std::string location) const = 0;

};

#endif // SERVICE_H
