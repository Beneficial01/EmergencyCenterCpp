#ifndef CONCRETESERVICE_H
#define CONCRETESERVICE_H

//#include "service.h"
#include <string>
#include "EmergencyCentreLib_global.h"
#include "service.h"

class EMERGENCYCENTRELIB_EXPORT ConcreteService:  Service
{
public:
    ConcreteService();
    virtual void update() const override;

    void setText(const std::string &newText);
    std::string getText() const;

private:
    std::string text {"No service has been configured here"};
};

#endif // CONCRETESERVICE_H


