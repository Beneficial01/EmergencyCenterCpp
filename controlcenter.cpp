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

ControlCenter &ControlCenter::operator++()
{
        modify(true); // Activate all sensors
        return *this;

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

void ControlCenter::testBySensorType(std::string sensorType)
{
    for(auto& location: allLocations){
        std::vector<std::shared_ptr<Space>> subSpaces = location->getSubSpaces();

        for(auto& space: subSpaces){
            if(std::dynamic_pointer_cast<Sensor>(space) != nullptr){
                auto s = std::dynamic_pointer_cast<Sensor>(space);
                if(s->getSensorType() == sensorType){
                    s->trigger();
                }
            }
        }

    }
}

void ControlCenter::test(std::string locationName, std::string sensorType)
{

    auto sensors = getAllSensorsInSpace(locationName);

    for(auto& s: sensors){
        //check if its a sensor
        if(s->getSensorType() == sensorType){
            s->trigger();
        }
    }

}

void ControlCenter::getOverview(std::string comp)
{

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




    std::cout << "Overview of sensors:" << std::endl << std::endl;


    for(auto&s: sensors){
//        std::cout << "Sensor ID: " << s->getSensorId() << std::endl;
//        std::cout << "Vendor name: " << s->getVendorName() << std::endl;
//        std::cout << "Sensor location: " << s->getLocation() << std::endl;
//        if(s->isTimeDependent()){
//            std::cout << "Activate start time: " << s->getStartTime() << std::endl;
//            std::cout << "Activate end time: " << s->getEndTime() << std::endl;
//        }
//        else{
//            std::cout << "Sensor activation is time independent"  << std::endl;
//        }
        std::cout << (*s) << std::endl;
        std::cout << std::endl;
    }


}

void ControlCenter::activate()
{
    modify(true);
}

void ControlCenter::activate(std::string spaceName)
{
    modify(spaceName, true);
}

void ControlCenter::activate(std::string spaceName, std::string sensorType)
{
    modify(spaceName, sensorType, true);
}

void ControlCenter::activateBySensorType(std::string sensorType)
{
    modifyBySensorType(sensorType, true);
}

void ControlCenter::deactivate()
{
    modify(false);
}

void ControlCenter::deactivate(std::string spaceName)
{
    modify(spaceName, false);
}

void ControlCenter::deactivate(std::string spaceName, std::string sensorType)
{
    modify(spaceName, sensorType, false);
}

void ControlCenter::deactivateBySensorType(std::string sensorType)
{
    modifyBySensorType(sensorType, false);
}

//void ControlCenter::testBySensorType(std::string sensorType)
//{
//    for(auto& location: allLocations){
//        if(location->getSpaceName() == locationName){
//            location->trigger();
//        }
//    }
//}


std::vector<std::shared_ptr<Sensor>> ControlCenter::getAllSensorsInSpace(std::string spaceName) {

    /*
     * first find the location matching the spaceName
     * get all the subspaces of the spaceName with recursiveUnroll
     * for each of these spaces, go through list of sensors
     * for each sensor, add to list
     */

    std::vector<std::shared_ptr<Sensor>> sensorsInSpace;

    for(auto& location: allLocations)
    {
        if (location->getSpaceName() == spaceName) {
            auto allSubspaces = recursiveUnroll(*location);

            for (const auto& subspace : allSubspaces) {
                auto findingSubspace = subspace->getSubSpaces();
                for (const auto& maybeSensor : findingSubspace) {
                    if (std::dynamic_pointer_cast<Sensor>(maybeSensor) != nullptr) {
                        sensorsInSpace.push_back(std::dynamic_pointer_cast<Sensor>(maybeSensor));
                    }
                }
            }

            auto internalSubspaces = location->getSubSpaces();
            for(auto& is: internalSubspaces){
                if (std::dynamic_pointer_cast<Sensor>(is) != nullptr) {
                    sensorsInSpace.push_back(std::dynamic_pointer_cast<Sensor>(is));
                }
            }
        }
    }
    return sensorsInSpace;
}

void ControlCenter::modify(bool b)
{
    auto allSensors = getAllSensors();
    for(auto& sensor: allSensors){
        b ? ++(*sensor):--(*sensor);
    }
}

void ControlCenter::modify(std::string spaceName, bool b)
{
    auto sensorsInSpace = getAllSensorsInSpace(spaceName);
    for(auto& sensor: sensorsInSpace){
        b ? ++(*sensor):--(*sensor);
    }
}

void ControlCenter::modify(std::string spaceName, std::string sensorType, bool b)
{
    auto sensorsInSpace = getAllSensorsInSpace(spaceName);
    for(auto& sensor: sensorsInSpace){
        if(sensor->getSensorType()==sensorType){
            b ? ++(*sensor):--(*sensor);
        }
    }
}

void ControlCenter::modifyBySensorType(std::string sensorType, bool b)
{
    auto allSensors = getAllSensors();
    for(auto& sensor: allSensors){
        if(sensor->getSensorType()== sensorType){
            b ? ++(*sensor):--(*sensor);
        }
    }
}


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















