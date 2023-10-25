#ifndef LOCATION_H
#define LOCATION_H

#include "EmergencyCentreLib_global.h"
#include "space.h"
#include <vector>
#include <string>
#include <memory>

class EMERGENCYCENTRELIB_EXPORT Location: Space
{
public:
    Location();
    std::string toString() const override;
    bool trigger() const override;
    void addSpace(std::shared_ptr<Space> space);
    void setSpaceName(const std::string &newSpaceName);

private:
    std::vector<std::shared_ptr<Space>> subSpaces {};
    std::string spaceName;
};

#endif // LOCATION_H
