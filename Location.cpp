#include "Location.h"
#include <iostream>

// Pass the string up to the base Place constructor
Location::Location(const std::string& placeName) : Place(placeName) {}

void Location::traverse() {
    std::cout << "[Location] Arrived at " << this->getName() << "." << std::endl;
}