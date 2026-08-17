#ifndef PLACE_H
#define PLACE_H
#include <vector>
#include <string>

class Place {
protected:
    std::string name;

public:
    explicit Place(const std::string& placeName) : name(placeName) {}
    virtual ~Place() = default; 

    // Prevent slicing and double-frees
    Place(const Place&) = delete;
    Place& operator=(const Place&) = delete;

    std::string getName() const { return name; }
    
    virtual void traverse() = 0; 
    virtual std::vector<Place*> getNeighbours() const = 0;
    virtual double getDistanceTo(Place* other) const = 0;
    virtual double getTravelTimeTo(Place* other) const = 0;
    virtual double getCostTo(Place* other) const = 0;
};

#endif 