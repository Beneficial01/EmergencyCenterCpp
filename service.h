#ifndef SERVICE_H
#define SERVICE_H

#include "EmergencyCentreLib_global.h"

class EMERGENCYCENTRELIB_EXPORT Service
{
public:
    Service() = default;
    virtual ~Service() = default;
    virtual void update() const = 0;

};

#endif // SERVICE_H
