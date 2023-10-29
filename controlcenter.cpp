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

std::vector<std::shared_ptr<Space> > ControlCenter::unrollSpaces()
{
    std::vector<std::shared_ptr<Space>> unrolledSpaces;
    std::vector<std::shared_ptr<Space>> unrolledSpaces2;

    for(auto& space: spaces){

        unrolledSpaces2 = recursiveUnroll(*space);
        unrolledSpaces.insert(unrolledSpaces2.end(), unrolledSpaces2.begin(), unrolledSpaces2.end());
//        unrolledSpaces.push_back(space);
//        unrolledSpaces2 = unrolledSpaces(space);
//        unrolledSpaces.insert();
    }



}

std::vector<std::shared_ptr<Space> > ControlCenter::recursiveUnroll(Space& space)
{

}

















