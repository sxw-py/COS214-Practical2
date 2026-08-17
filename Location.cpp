#include "Location.h"
#include <iostream>

// Pass the string up to the base Place constructor
Location::Location(const std::string& placeName) : Place(placeName) {}

void Location::traverse() {
    std::cout << "[Location] Arrived at " << this->getName() << "." << std::endl;
}

// functions used in strategy pattern files
void Location::addConnection(Place* neighbour, double distance, double travelTime, double cost) {
    neighbours.push_back(neighbour);
    distances[neighbour] = distance;
    travelTimes[neighbour] = travelTime;
    costs[neighbour] = cost;
}

std::vector<Place*> Location::getNeighbours() const {
    return neighbours;
}

double Location::getDistanceTo(Place* other) const {
    return distances.count(other) ? distances.at(other) : 0.0;
}

double Location::getTravelTimeTo(Place* other) const {
    return travelTimes.count(other) ? travelTimes.at(other) : 0.0;
}

double Location::getCostTo(Place* other) const {
    return costs.count(other) ? costs.at(other) : 0.0;
}