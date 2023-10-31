#include "location.h"
#include "space.h"
#include <iostream>

Location::Location()
{

}

std::string Location::toString() const
{
    return "This location is: " + spaceName;
}

void Location::trigger() const
{
    if(!subSpaces.empty()){
        //trigger all subspaces in this location
        for (const std::shared_ptr<Space>& space: subSpaces){
            (*space).trigger();
        }

    } else {

        std::cout << spaceName << ": This space has no subspaces or sensors to trigger" << std::endl;

    }

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

std::string Location::getSpaceName() const
{
    return spaceName;
}
