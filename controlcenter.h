#ifndef CONTROLCENTER_H
#define CONTROLCENTER_H

#include <string>
#include <vector>
#include <memory>
#include "space.h"

class ControlCenter
{
public:
    ControlCenter();
    bool test(Space& space);
    void activate(Space& space);
    void deactivate(Space& space);
    void addSpace(Space& space);

private:
    std::string name {};
    std::vector<std::shared_ptr<Space>> spaces {};
};

#endif // CONTROLCENTER_H
