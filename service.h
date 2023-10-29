#ifndef SERVICE_H
#define SERVICE_H

#include "EmergencyCentreLib_global.h"
#include <string>

class EMERGENCYCENTRELIB_EXPORT Service
{
public:
    Service() = default;
    virtual ~Service() = default;
    //std::string locName INCLUDE THIS LATER ON AFTER GETTING CHANGES FROM LOCATION
    virtual void update(std::string sensorType, int id) const = 0;

};

#endif // SERVICE_H
