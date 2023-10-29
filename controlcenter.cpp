#include "controlcenter.h"

ControlCenter::ControlCenter()
{

}

ControlCenter::ControlCenter(std::string n)
    :name{n}
{

}

void ControlCenter::test(Space &space)
{
    space.trigger();
}

