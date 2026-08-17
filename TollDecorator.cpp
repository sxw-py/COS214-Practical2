#include "TollDecorator.h"
#include <iostream>

TollDecorator::TollDecorator(Place* p, double tollFee) : PlaceDecorator(p), fee(tollFee) {}

double TollDecorator::getCost() {
    double baseCost = PlaceDecorator::getCost();
    return baseCost + this->fee;
}

void TollDecorator::traverse() {
    std::cout << "[Toll Gate] Charging fee: R" << this->fee << std::endl;
    PlaceDecorator::traverse();
}

void TollDecorator::print(){
    std::cout << "[Feature] Toll Road (Fee: R" << this->fee << ")" << std::endl;
    PlaceDecorator* dec = dynamic_cast<PlaceDecorator*>(this->getComponent());
    if (dec){
        dec->print();
    }
}

TollDecorator::~TollDecorator(){}
