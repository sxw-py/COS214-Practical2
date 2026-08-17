#include "Trip.h"

Trip::Trip(Place* start, Place* end) : start(start), end(end), route(nullptr){}

void Trip::setStrategy(RouteStrategy* newStrategy){
    delete route;
    this->route = newStrategy;
}

std::vector<Place*> Trip::planRoute() const{
     if (!route){
        return {};
     }

    return this->route->getRoute(this->start, this->end);

}

Trip::~Trip(){
   delete route;
}