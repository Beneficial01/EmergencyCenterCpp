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

std::vector<std::shared_ptr<Location> > ControlCenter::unrollSpaces()
{
    std::vector<std::shared_ptr<Location>> unrolledSpaces;
    std::vector<std::shared_ptr<Location>> unrolledSpaces2;

    for(auto& space: spaces){

        if(std::dynamic_pointer_cast<Location>(space) != nullptr){
            auto loc = std::dynamic_pointer_cast<Location>(space);
            unrolledSpaces2 = recursiveUnroll( *loc );
            unrolledSpaces.push_back(loc);
            unrolledSpaces.insert(unrolledSpaces2.end(), unrolledSpaces2.begin(), unrolledSpaces2.end());
        }

//        unrolledSpaces.push_back(space);
//        unrolledSpaces2 = unrolledSpaces(space);
//        unrolledSpaces.insert();
    }

    return unrolledSpaces;
}


//JUST KEEP THIS FUNCTION AND CALL IT EACH TIME WE ADD A NEW SPACE TO OUR SYSTEM!!!!
std::vector<std::shared_ptr<Location> > ControlCenter::recursiveUnroll(Location& space)
{
    std::vector<std::shared_ptr<Space>> subspaces;

    std::vector<std::shared_ptr<Location>> locations;
    std::vector<std::shared_ptr<Location>> locations2;

    subspaces = space.getSubSpaces();
    for(auto& subspace: subspaces){

        //if its a location:
        /*
         * add it to locations
         * locations 2 become the recursive call of this location
         * and then I insert it into the first location
         */
        if(std::dynamic_pointer_cast<Location>(subspace) != nullptr){
            auto loc = std::dynamic_pointer_cast<Location>(subspace);
            locations.push_back(loc);
            locations2.clear();
            locations2 = recursiveUnroll(*loc);
            locations.insert(locations2.end(), locations2.begin(), locations2.end());
        }


    }

    return locations;

}

















