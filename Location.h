#ifndef LOCATION_H
#define LOCATION_H

#include "Place.h"

class Location : public Place {
public:
    explicit Location(const std::string& placeName);
    ~Location() override = default;

    void traverse() override; 
};

#endif 