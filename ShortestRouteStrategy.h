#ifndef SHORTESTROUTESTRATEGY_H
#define SHORTESTROUTESTRATEGY_H
#include "RouteStrategy.h"
#include <vector>

class ShortestRouteStrategy : public RouteStrategy{
    public:
        std::vector<Place*> getRoute(Place* start, Place* end) override;
};

#endif