#ifndef SPACE_H
#define SPACE_H


#include "EmergencyCentreLib_global.h"
#include <string>

class EMERGENCYCENTRELIB_EXPORT Space
{
public:
    Space() = default;
    virtual ~Space() = default;
    virtual std::string toString() const = 0;
    virtual bool trigger() const = 0;
};


#endif // SPACE_H
