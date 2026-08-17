#ifndef TOLLDECORATOR_H
#define TOLLDECORATOR_H
#include "PlaceDecorator.h"

class TollDecorator : public PlaceDecorator {
    private:
        double fee;

    public:
        TollDecorator(Place* p, double tollFee = 0.0);
        virtual ~TollDecorator();

        double getCost() override;
        void traverse() override;
        void print() override;
};


#endif