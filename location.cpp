#include "location.h"
#include <iostream>

Location::Location()
{

}

std::string Location::toString() const
{
    std::cout << "This is a temp message, name is: " << spaceName << std::endl;

    //  #TODO: implement to string function to loop through all locations
    return "this is my toString";
}

bool Location::trigger() const
{
    // #TODO: implement tigger to trigger all sub systems
    return false;
}

void Location::setSpaceName(const std::string &newSpaceName)
{
    spaceName = newSpaceName;
}
