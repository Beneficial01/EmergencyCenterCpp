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

/**
 * @brief The ControlCenter class used as a central control point for the security system
 */
class EMERGENCYCENTRELIB_EXPORT ControlCenter
{
public:
    ControlCenter();
    ControlCenter(std::string n);


    /// FUNCTIONS TO TEST SENSORS/LOCATIONS:
    void test(Space& space);//test all in space
    void test();//test all
    void testByLocation(std::string locationName);//test by location name
    void testBySensorType(std::string sensorType);
    void test(std::string locationName, std::string sensorType);

    ///FUNCTIONS TO (DE)ACTIVATE SENSORS/LOCATIONS:
    void activate();
    void activate(std::string spaceName);
    void activate(std::string spaceName, std::string sensorType);
    void activateBySensorType(std::string sensorType);
    void deactivate();
    void deactivate(std::string spaceName);
    void deactivate(std::string spaceName, std::string sensorType);
    void deactivateBySensorType(std::string sensorType);


    ///OTHER FUNCTIONS:
    /**
     * @brief prints a overview of all sensors in the system
     * @param comp to indicate which comparator is used:
     *          - comp = "vendor" -> orders alphabetically by vendor
     *          - comp = "id" -> orders by sensor id
     *          - comp = "location" -> orders by location alphabetically
     *          - comp = "*" -> no ordering applied
     */
    void getOverview(std::string comp);


    void addSpace(std::shared_ptr<Space> space);
    std::vector<std::shared_ptr<Location>> getAllLocations();

    ControlCenter& operator++();

    std::vector<std::shared_ptr<Sensor>> getAllSensorsInSpace(std::string spaceName);




private:
    std::vector<std::shared_ptr<Location>> recursiveUnroll(Location& space);
    std::string name {"Control Center"};
    std::vector<std::shared_ptr<Space>> spaces {};
    std::vector<std::shared_ptr<Location>> allLocations {};
    std::vector<std::shared_ptr<Sensor>> getAllSensors();



    void modify(bool b);
    void modify(std::string spaceName, bool b);
    void modify(std::string spaceName, std::string sensorType, bool b );
    void modifyBySensorType(std::string sensorType, bool b);


};


#endif // CONTROLCENTER_H
