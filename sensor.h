#ifndef SENSOR_H
#define SENSOR_H
#include "EmergencyCentreLib_global.h"
#include "service.h"
#include "space.h"
#include <vector>
#include <memory>

class EMERGENCYCENTRELIB_EXPORT Sensor: Space
{
public:
    //Sensor() = default;
    virtual ~Sensor() = default;
    virtual void activate();
    virtual void deactivate();
    virtual bool trigger() const override;
    virtual std::string toString() const override;
    virtual std::string getSensorType() const = 0;

//    void addService(Service & service );
    void addService(std::shared_ptr<Service> service );
    int getSensorId() const;
    std::string getVendorName() const;

private:
    //attributes
    bool activated;
    std::string startTime;
    std::string endTime;
    bool timerState;
    //std::shared_ptr<Location> location;
    //std::vector<Service> services;
    std::vector<std::shared_ptr<Service>> services;

protected:
    void generateId();
    int sensorId;
    std::string vendorName;
};
    static int nextId = 1;


#endif // SENSOR_H
