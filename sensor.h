#ifndef SENSOR_H
#define SENSOR_H
#include "EmergencyCentreLib_global.h"
#include "service.h"
#include "space.h"
#include <vector>
#include <memory>
#include <ctime>
#include "location.h"


/**
 * @class Sensor
 * @brief The Sensor class is an abstract base class for specific sensors in the Emergency Centre Library.
 * The Sensor class implements the Space interface and its methods
 * @see Space
 */
class EMERGENCYCENTRELIB_EXPORT Sensor: public Space
{
public:
    virtual ~Sensor() = default;
    virtual void activate();
    virtual void deactivate();
    /**
     * @brief trigger method is a method of the space interface
     * It is used to call the update method for the service(s) that are attached to a sensor
     */
    virtual void trigger() const override;
    void addService(std::shared_ptr<Service> service );

    bool isTimeDependent() const;
    bool isTimeWithinBounds() const;
    /**
     * @brief toString method gives an overview of the sensor details
     * @return std::string with sensor type, location, id
     * it also gives time details if the sensor is time dependent
     * else, it mentions that the sensor is time-independent
     */
    virtual std::string toString() const override;

    friend std::ostream & operator<<(std::ostream & os, const Sensor & s);
    Sensor& operator++();
    Sensor& operator--();

    int getSensorId() const;
    std::string getVendorName() const;
    bool getActivated() const;
    std::string getStartTime() const;
    std::string getEndTime() const;
    std::string getLocation() const;
    virtual std::string getSensorType() const = 0;

    void setTimeDependent(bool state);
    void setStartTime(const int hour, const int min);
    void setEndTime(const int hour, const int min);



private:

    bool activated {false};
    struct tm startTime;
    struct tm endTime;
    bool timeDependent {false};
    std::vector<std::shared_ptr<Service>> services;

protected:
    void generateId();
    int sensorId;
    std::string vendorName;
    std::shared_ptr<Location> location;
};
    static int nextId = 1;


#endif // SENSOR_H
