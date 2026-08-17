#ifndef TRIP_H
#define TRIP_H
#include "RouteStrategy.h"
#include "Place.h"

#include <vector>


class Trip{
    private:
        RouteStrategy* route;
        Place* start;
        Place* end;

    public:
        Trip(Place* start, Place* end);
        void setStrategy(RouteStrategy* newStrategy);
        std::vector<Place*> planRoute() const;
        ~Trip();
};
#endif