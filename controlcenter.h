#ifndef CONTROLCENTER_H
#define CONTROLCENTER_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "space.h"
#include "sensor.h"
#include "location.h"
#include "EmergencyCentreLib_global.h"

class EMERGENCYCENTRELIB_EXPORT ControlCenter
{
public:
    ControlCenter();
    ControlCenter(std::string n);
    //second constructor with name

    /// TESTING:
    void test(Space& space);//test all in space
    void test();//test all
    void testByLocation(std::string locationName);//test by location name
    //void testBySensorType(std::string sensorType);
    //test(string name, class type)
    //get all locations in string form -> structure print as tree

    ///ACTIVATION:
    //void activate(Space& space);
    //activate() -> all
    void activate(std::string spaceName);
    void activate(std::string spaceName, std::string sensorType);
    //activate(class type)
    //void deactivate(Space& space);
    //deactivate() -> all
    //deactivate(string SpaceName)
    //deactivate(string SpaceName, class type)

    //PRIVATE FUNCTION WITH BOOL TO KNOW AVTIVATE OR DEACTIVATE
    //get all sensors from location from its name



    ///OVERVIEW -> use function objects
    //all sensors ordered by vendor
    //all sensors by ID
    //all sensors by location name


    void addSpace(std::shared_ptr<Space> space);
//    std::vector<std::shared_ptr<Sensor>> getAllSensors();
    std::vector<std::shared_ptr<Location>> getAllLocations();

    //overload ++ to activate all sensors




private:
    std::vector<std::shared_ptr<Location>> recursiveUnroll(Location& space);

    std::string name {"Control Center"};
    std::vector<std::shared_ptr<Space>> spaces {};
    std::vector<std::shared_ptr<Location>> allLocations {};
    std::vector<std::shared_ptr<Sensor>> getAllSensorsInSpace(std::string spaceName);
};

#endif // CONTROLCENTER_H
