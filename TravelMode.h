#ifndef TRAVEL_MODE_H
#define TRAVEL_MODE_H

#include <string>

// Forward declaration to prevent circular dependency
class Traveller; 

class TravelMode {
public:
    virtual ~TravelMode() = default; 

    // Pure virtual functions
    virtual void move(Traveller* context, int distance) = 0;
    virtual std::string getModeName() const = 0;
};

#endif