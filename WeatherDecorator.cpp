#include "WeatherDecorator.h"

WeatherDecorator::WeatherDecorator(Place* p, std::string cond) : PlaceDecorator(p), condition(cond) {}

void WeatherDecorator::print() {
    std::cout << "[Weather Update] It is currently " << this->condition << "!" << std::endl;
    PlaceDecorator::print();
}

void WeatherDecorator::traverse() {
    std::cout << "[Weather] Traversing through weather: " << this->condition << std::endl;
    PlaceDecorator::traverse();
}

WeatherDecorator::~WeatherDecorator(){
   
}
