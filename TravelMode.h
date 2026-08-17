#ifndef TRAVEL_MODE_H
#define TRAVEL_MODE_H

#include <string>

// Forward declaration to prevent circular dependency
class Traveller; 
class Terrain;

class TravelMode {
public:
    virtual ~TravelMode() = default; 
    TravelMode(const TravelMode&) = delete;
    TravelMode& operator=(const TravelMode&) = delete;
    // Pure virtual functions
    virtual void move(Traveller* context, int distance, Terrain* currentTerrain) = 0;
    virtual std::string getModeName() const = 0;
protected:
    TravelMode() = default;
};

#endif