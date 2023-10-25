#ifndef LOCATION_H
#define LOCATION_H

#include "EmergencyCentreLib_global.h"
#include "space.h"

class EMERGENCYCENTRELIB_EXPORT Location: Space
{
public:
    Location();
    std::string toString() const;
    bool trigger() const;

private:

};

#endif // LOCATION_H
