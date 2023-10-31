#include "concreteservice.h"
#include <iostream>


ConcreteService::ConcreteService()
{

}

void ConcreteService::update(std::string sensorType, std::string location) const
{

    std::cout <<"\"" << text << "\"";
    std::cout << " from " << sensorType << "Sensor in "  << location << std::endl;
}

void ConcreteService::setText(const std::string &newText)
{
    text = newText;
}

std::string ConcreteService::getText() const
{
    return text;
}
