#include "PlaceDecorator.h"

PlaceDecorator::PlaceDecorator(Place* component): Place("Decorator"), component(component){}

Place* PlaceDecorator::getComponent() const {
    return component;

}

void PlaceDecorator::print(){
    if (component){
        PlaceDecorator* dec = dynamic_cast<PlaceDecorator*>(component);
        if (dec){
            dec->print();
        }
    }
}

double PlaceDecorator::getCost(){
    if (component){
        PlaceDecorator* dec = dynamic_cast<PlaceDecorator*>(component);
        if (dec){
            return dec->getCost();
        }
        return component->getCostTo(nullptr);
    }
    return 0.0;
}

void PlaceDecorator::enter() {
    if (component) {
        PlaceDecorator* dec = dynamic_cast<PlaceDecorator*>(component);
        if (dec) {
            dec->enter();
        }
    }
}

void PlaceDecorator::traverse() {
    if (component) {
        component->traverse();
    }
}


PlaceDecorator::~PlaceDecorator() {
    delete component;
}


std::vector<Place*> PlaceDecorator::getNeighbours() const { 
    return component->getNeighbours(); 
}

double PlaceDecorator::getDistanceTo(Place* other) const { 
    return component->getDistanceTo(other); 
}

double PlaceDecorator::getTravelTimeTo(Place* other) const { 
    return component->getTravelTimeTo(other); 
}

double PlaceDecorator::getCostTo(Place* other) const {
     return component->getCostTo(other); 
}