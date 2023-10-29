#ifndef CONTROLCENTER_H
#define CONTROLCENTER_H

#include <string>
#include <vector>
#include <memory>
#include "space.h"
//#include "sensor.h"
#include "location.h"

class ControlCenter
{
public:
    ControlCenter();
    bool test(Space& space);
    void activate(Space& space);
    void deactivate(Space& space);
    void addSpace(std::shared_ptr<Space> space);
//    std::vector<std::shared_ptr<Sensor>> getAllSensors();
    std::vector<std::shared_ptr<Location>> getAllLocations();

private:
    std::string name {};
    std::vector<std::shared_ptr<Space>> spaces {};
};

#endif // CONTROLCENTER_H
