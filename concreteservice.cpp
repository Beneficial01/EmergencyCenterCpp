#include "concreteservice.h"
#include <iostream>



//void ConcreteService::update() const
//{
//    std::cout << text << std::endl;
//}

ConcreteService::ConcreteService()
{
    std::cout << "Creating a concrete service" << std::endl;
}

void ConcreteService::update() const
{
    std::cout << text << std::endl;
}

void ConcreteService::setText(const std::string &newText)
{
    text = newText;
}

std::string ConcreteService::getText() const
{
    return text;
}
