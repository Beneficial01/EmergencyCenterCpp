#ifndef LOCATION_H
#define LOCATION_H

#include "EmergencyCentreLib_global.h"
#include "space.h"
#include <vector>
#include <string>

class EMERGENCYCENTRELIB_EXPORT Location: Space
{
public:
    Location();
    std::string toString() const override;
    bool trigger() const override;

private:
    std::vector<Space> subSpaces {};
    std::string spaceName;
};

#endif // LOCATION_H
