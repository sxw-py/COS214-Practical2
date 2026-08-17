#ifndef WEATHERDECORATOR_H
#define WEATHERDECORATOR_H
#include "PlaceDecorator.h"
#include <iostream>


class WeatherDecorator : public PlaceDecorator{
    private:
        std::string condition;
    public:
        WeatherDecorator(Place* p, std::string cond);
        void print() override;
        void traverse() override;
        virtual ~WeatherDecorator();
    
};

#endif