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

void ControlCenter::addSpace(std::shared_ptr<Space> space)
{
    spaces.push_back(space);
    if(std::dynamic_pointer_cast<Location>(space) != nullptr){
        auto loc = std::dynamic_pointer_cast<Location>(space);
        allLocations.push_back(loc);
        auto subLocations = recursiveUnroll(*loc);
        allLocations.insert(allLocations.end(), subLocations.begin(), subLocations.end());
    }

}

void ControlCenter::test()
{
    for(auto& space: spaces){
        space->trigger();
    }
}

void ControlCenter::testByLocation(std::string locationName)
{

    for(auto& location: allLocations){
        if(location->getSpaceName() == locationName){
            location->trigger();
        }
    }

}

void ControlCenter::getOverview(std::string comp)
{
/*
 *
 *FIX THE IF ELSE STRUCTURE TO DETERMINE THE COMPARITOR!!!
 *
 *
 */
    std::vector<std::shared_ptr<Sensor>> sensors = getAllSensors();
    if(comp == "vendor"){
        std::sort(sensors.begin(), sensors.end(), [](auto & s1, auto & s2)
                  {return s1->getVendorName() < s2->getVendorName();});
    }
    else if(comp == "id"){
        std::sort(sensors.begin(), sensors.end(), [](auto & s1, auto & s2)
                  {return s1->getSensorId() < s2->getSensorId();});
    }
    else if(comp == "location"){
        std::sort(sensors.begin(), sensors.end(), [](auto & s1, auto & s2)
                  {return s1->getLocation() < s2->getLocation();});
    }

    for(auto&s: sensors){
        std::cout << s->getVendorName() << std::endl;
        std::cout << s->getSensorId() << std::endl;
        std::cout << s->getLocation() << std::endl;
    }

    std::cout << "test" << std::endl;

}

//void ControlCenter::testBySensorType(std::string sensorType)
//{
//    for(auto& location: allLocations){
//        if(location->getSpaceName() == locationName){
//            location->trigger();
//        }
//    }
//}



//JUST KEEP THIS FUNCTION AND CALL IT EACH TIME WE ADD A NEW SPACE TO OUR SYSTEM!!!!
std::vector<std::shared_ptr<Location> > ControlCenter::recursiveUnroll(Location& space)
{
    std::vector<std::shared_ptr<Space>> subspaces;
    subspaces = space.getSubSpaces();

    std::vector<std::shared_ptr<Location>> locations;
    std::vector<std::shared_ptr<Location>> locations2;


    for(auto& subspace: subspaces){


        if(std::dynamic_pointer_cast<Location>(subspace) != nullptr){
            auto loc = std::dynamic_pointer_cast<Location>(subspace);
            locations.push_back(loc);
            locations2.clear();
            if((*loc).getSubSpaces().size() > 0){
               locations2 = recursiveUnroll(*loc);
               locations.insert(locations.end(), locations2.begin(), locations2.end());
            }

        }


    }

    return locations;

}

std::vector<std::shared_ptr<Sensor> > ControlCenter::getAllSensors()
{
    std::vector<std::shared_ptr<Sensor>> sensors;
    std::vector<std::shared_ptr<Space>> subSpaces;

    for(auto& l: allLocations){
        subSpaces = l->getSubSpaces();
        for(auto& s: subSpaces){
            if(std::dynamic_pointer_cast<Sensor>(s) != nullptr){
               sensors.push_back(std::dynamic_pointer_cast<Sensor>(s));
            }
        }
    }

    return sensors;
}

















