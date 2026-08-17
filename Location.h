#ifndef LOCATION_H
#define LOCATION_H

#include <map>
#include <vector>
#include "Place.h"

class Location : public Place {
public:
    explicit Location(const std::string& placeName);
    ~Location() override = default;

    void traverse() override;
    void addConnection(Place* neighbour, double distance, double travelTime, double cost);
    std::vector<Place*> getNeighbours() const override;
    double getDistanceTo(Place* other) const override;
    double getTravelTimeTo(Place* other) const override;
    double getCostTo(Place* other) const override; 

private:
    std::vector<Place*> neighbours;
    std::map<Place*, double> distances;
    std::map<Place*, double> travelTimes;
    std::map<Place*, double> costs;
};

#endif 