#ifndef CONTROLCENTER_H
#define CONTROLCENTER_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>
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
    void testBySensorType(std::string sensorType);
    //test(string name, class type)
    //get all locations in string form -> structure print as tree

    ///ACTIVATION:
    void activate();
    void activate(std::string spaceName);
    void activate(std::string spaceName, std::string sensorType);
    void activateBySensorType(std::string sensorType);
    void deactivate();
    void deactivate(std::string spaceName);
    void deactivate(std::string spaceName, std::string sensorType);
    void deactivateBySensorType(std::string sensorType);


    ///OVERVIEW -> use function objects
    void getOverview(std::string comp);

    //all sensors ordered by vendor
    //all sensors by ID
    //all sensors by location name


    void addSpace(std::shared_ptr<Space> space);
//    std::vector<std::shared_ptr<Sensor>> getAllSensors();
    std::vector<std::shared_ptr<Location>> getAllLocations();

    //overload ++ to activate all sensors
    ControlCenter& operator++();



private:
    std::vector<std::shared_ptr<Location>> recursiveUnroll(Location& space);
    std::string name {"Control Center"};
    std::vector<std::shared_ptr<Space>> spaces {};
    std::vector<std::shared_ptr<Location>> allLocations {};
    std::vector<std::shared_ptr<Sensor>> getAllSensors();
    std::vector<std::shared_ptr<Sensor>> getAllSensorsInSpace(std::string spaceName);



    void modify(bool b);
    void modify(std::string spaceName, bool b);
    void modify(std::string spaceName, std::string sensorType, bool b );
    void modifyBySensorType(std::string sensorType, bool b);


};



//all sensors ordered by vendor
//all sensors by ID
//all sensors by location name


//class VendorAlphabetical
//{
//public:
//    bool operator()(std::unique_ptr<Sensor> & s1, std::unique_ptr<Sensor> & s2)
//    {
//        return (s1->getVendorName()) > (s2->getVendorName());
//    }
//};



#endif // CONTROLCENTER_H
