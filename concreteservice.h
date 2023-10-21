#ifndef CONCRETESERVICE_H
#define CONCRETESERVICE_H

#include "service.h"
#include <string>


class ConcreteService : Service
{
public:
    ConcreteService() = default;

    virtual void update() const override;

    void setText(const std::string &newText);
    std::string getText() const;

private:
    std::string text {"No service has been configured here"};
};

#endif // CONCRETESERVICE_H


