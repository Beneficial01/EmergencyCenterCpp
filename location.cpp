#include "location.h"
#include "space.h"
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
    if(!subSpaces.empty()){

        for (const std::shared_ptr<Space>& space: subSpaces){
            (*space).trigger();
        }

    } else {

        std::cout << spaceName << ": This space has no subspaces or sensors to trigger" << std::endl;

    }

    return false;
}

void Location::addSpace(std::shared_ptr<Space> space)
{
    subSpaces.push_back(space);
}

void Location::setSpaceName(const std::string &newSpaceName)
{
    spaceName = newSpaceName;
}

std::vector<std::shared_ptr<Space> > Location::getSubSpaces() const
{
    return subSpaces;
}
