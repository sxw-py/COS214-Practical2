#ifndef FASTESTROUTESTRATEGY_H
#define FASTESTROUTESTRATEGY_H
#include "RouteStrategy.h"

class FastestRouteStrategy : public RouteStrategy{
    public:
        std::vector<Place*> getRoute(Place* start, Place* end) override;
};

#endif