#ifndef ROUTESTRATEGY_H
#define ROUTESTRATEGY_H
#include "Place.h"
#include <vector>

class Place;

class RouteStrategy{
    public:
        virtual std::vector<Place*> getRoute(Place* start, Place* end) = 0;
        virtual ~RouteStrategy();
};








#endif 