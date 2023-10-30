#ifndef SENSOR_H
#define SENSOR_H
#include "EmergencyCentreLib_global.h"
#include "service.h"
#include "space.h"
#include <vector>
#include <memory>
#include <ctime>
#include "location.h"

class EMERGENCYCENTRELIB_EXPORT Sensor: public Space
{
public:
    //Sensor() = default;
    virtual ~Sensor() = default;
    virtual void activate();
    virtual void deactivate();
    virtual void trigger() const override;
    virtual std::string toString() const override;
    virtual std::string getSensorType() const = 0;

//    void addService(Service & service );
    void addService(std::shared_ptr<Service> service );
    int getSensorId() const;
    std::string getVendorName() const;
    bool getActivated() const;
    std::string getStartTime() const;
    std::string getEndTime() const;
    void setTimeDependent(bool state);
    bool isTimeDependent() const;
    bool isTimeWithinBounds() const;

    void setStartTime(const int hour, const int min);
    void setEndTime(const int hour, const int min);

    std::string getLocation() const;

private:
    //attributes
    bool activated {false};
    struct tm startTime;
    struct tm endTime;
    bool timeDependent;
    //std::vector<Service> services;
    std::vector<std::shared_ptr<Service>> services;

protected:
    void generateId();
    int sensorId;
    std::string vendorName;
    std::shared_ptr<Location> location;
};
    static int nextId = 1;


#endif // SENSOR_H
