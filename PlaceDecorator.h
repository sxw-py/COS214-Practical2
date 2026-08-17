#ifndef PLACEDECORATOR_H
#define PLACEDECORATOR_H
#include "Place.h"
#include <vector>

class PlaceDecorator : public Place{
    protected:
        Place* component;
    public:
        PlaceDecorator(Place* component);
        virtual void print();
        virtual double getCost();
        virtual void enter();
        virtual void traverse() =0;
        Place* getComponent() const ;
        std::vector<Place*> getNeighbours() const;
        double getDistanceTo(Place* other) const;
        double getTravelTimeTo(Place* other) const;
        double getCostTo(Place* other) const;
        virtual ~PlaceDecorator();

};

#endif