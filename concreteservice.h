#ifndef CONCRETESERVICE_H
#define CONCRETESERVICE_H

//#include "service.h"
#include <string>
#include "EmergencyCentreLib_global.h"
#include "service.h"

class EMERGENCYCENTRELIB_EXPORT ConcreteService:  public Service
{
public:
    ConcreteService();
    //std::string locName INCLUDE THIS AS WELL
    virtual void update(std::string sensorType, std::string location) const override;

    void setText(const std::string &newText);
    std::string getText() const;

private:
    std::string text {"No service has been configured here"};
};

#endif // CONCRETESERVICE_H


