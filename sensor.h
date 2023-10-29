#ifndef SENSOR_H
#define SENSOR_H
#include "EmergencyCentreLib_global.h"
#include "service.h"
#include "space.h"
#include <vector>
#include <memory>
#include "location.h"

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
    bool getActivated() const;
    bool getTimerState() const;
    std::string getStartTime() const;
    std::string getEndTime() const;

    void setStartTime(const std::string &newStartTime);
    void setEndTime(const std::string &newEndTime);

private:
    //attributes
    bool activated {false};
    std::string startTime;
    std::string endTime;
    bool timerState;
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
