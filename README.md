# Emergency Center Repo

## Description:

This project is a C++ library for an emergency center software that allows for flexible sensor management and emergency response. It is our solution to the Advanced Programming Techniques lab task aimed at creating an efficient, extensible, and maintainable library. The emergency center software is designed to handle different types of sensors, including smoke sensors, motion sensors, and toxic gas sensors. These sensors are configurable and can trigger various emergency responses/services in any configuration of spaces. 


## UML:
- The UML class diagram below provides an overview of the class structure, relationships, and method signatures. 

    ![UML](UML_Emergency_Center.jpg)


## Important note:
The timing of the sensors has been implemented using the system time. That may influence the result of the test scenarios, since a given sensor may not trigger -> simply because the current time is not within the time that the sensor is active.
In order to work around this, the sensors time dependence can be removed using the "void setTimeDependent(bool state)" function found in Sensor.h. If the value is set to false the sensor no longer depends on the time


