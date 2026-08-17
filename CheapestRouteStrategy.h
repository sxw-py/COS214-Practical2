#ifndef CHEAPESTROUTESTRATEGY_H
#define CHEAPESTROUTESTRATEGY_H
#include "RouteStrategy.h"

class CheapestRouteStrategy : public RouteStrategy{
    public:
        std::vector<Place*> getRoute(Place* start, Place* end) override;
};

#endif