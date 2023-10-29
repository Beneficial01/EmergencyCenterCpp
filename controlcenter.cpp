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

void ControlCenter::test()
{
    for(auto& space: spaces){
        space->trigger();
    }
}

void ControlCenter::test(std::string locationName)
{

   /*
    * PLAN:
    *
    * For each in my list of spaces:
    *   Check if its a location, and if it is check its name.
    *   if not go through all its locations recursively
    *
    */
}

